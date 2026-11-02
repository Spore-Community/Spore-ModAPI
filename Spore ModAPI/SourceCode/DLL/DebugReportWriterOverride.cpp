#ifdef MODAPI_DLL_EXPORT
#include "stdafx.h"
#include "DebugReportWriterOverride.h"

#include <Spore\Debug\ReportWriter.h>
#include <Spore\ModAPI.h>

#include <Psapi.h>

typedef LONG(WINAPI* RtlGetVersionPtr)(PRTL_OSVERSIONINFOW);

member_detour(WriteSystemInfoDetour, Debug::ReportWriter, bool(void))
{
	bool detoured(void)
	{
		char buffer[256] = { 0 };
		DWORD bufferSize = sizeof(buffer);

		if (GetComputerNameExA(COMPUTER_NAME_FORMAT::ComputerNameDnsFullyQualified, buffer, &bufferSize))
		{
			WriteKeyValue("Computer name", buffer);
		}

		bufferSize = sizeof(buffer);
		if (GetUserNameA(buffer, &bufferSize))
		{
			WriteKeyValue("User name", buffer);
		}

		WriteKeyValue("EA_PLATFORM", "Windows on X86");

		// GetVersionExA() is deprecated and only reports upto Windows 8
		// unless a higher Windows version is specified in the executable
		// manifest, so use RtlGetVersion() from ntdll.dll instead
		HMODULE ntdllHandle = GetModuleHandleW(L"ntdll.dll");
		if (ntdllHandle != nullptr)
		{
			RtlGetVersionPtr rtlGetVersion = (RtlGetVersionPtr)GetProcAddress(ntdllHandle, "RtlGetVersion");
			if (rtlGetVersion != nullptr)
			{
				RTL_OSVERSIONINFOW versionInfo = { 0 };
				versionInfo.dwOSVersionInfoSize = sizeof(RTL_OSVERSIONINFOW);

				if (rtlGetVersion(&versionInfo) == 0)
				{
					if (versionInfo.dwMajorVersion == 5 &&
						versionInfo.dwMinorVersion == 1)
					{
						sprintf_s(buffer, sizeof(buffer), "Windows XP");
					}
					else if (versionInfo.dwMajorVersion == 6 &&
						versionInfo.dwMinorVersion == 0)
					{
						sprintf_s(buffer, sizeof(buffer), "Windows Vista");
					}
					else if (versionInfo.dwMajorVersion == 6 &&
						versionInfo.dwMinorVersion == 1)
					{
						sprintf_s(buffer, sizeof(buffer), "Windows 7");
					}
					else if (versionInfo.dwMajorVersion == 6 &&
						versionInfo.dwMinorVersion == 2)
					{
						sprintf_s(buffer, sizeof(buffer), "Windows 8");
					}
					else if (versionInfo.dwMajorVersion == 6 &&
						versionInfo.dwMinorVersion == 3)
					{
						sprintf_s(buffer, sizeof(buffer), "Windows 8.1");
					}
					else if (versionInfo.dwMajorVersion == 10 &&
						versionInfo.dwMinorVersion == 0 &&
						versionInfo.dwBuildNumber < 22000)
					{
						sprintf_s(buffer, sizeof(buffer), "Windows 10");
					}
					else if (versionInfo.dwMajorVersion >= 10 &&
						versionInfo.dwMinorVersion == 0 &&
						versionInfo.dwBuildNumber >= 22000)
					{
						sprintf_s(buffer, sizeof(buffer), "Windows 11");
					}
					else
					{
						sprintf_s(buffer, sizeof(buffer), "Unknown");
					}
					WriteKeyValue("OS name", buffer);

					sprintf_s(buffer, sizeof(buffer), "%u.%u.%u", versionInfo.dwMajorVersion, versionInfo.dwMinorVersion, versionInfo.dwBuildNumber);
					WriteKeyValue("OS version number", buffer);

					if (versionInfo.szCSDVersion[0] != L'\0')
					{
						sprintf_s(buffer, sizeof(buffer), "%ls", versionInfo.szCSDVersion);
						WriteKeyValue("OS service pack", buffer);
					}

				}
			}
		}

		WriteKeyValue("Debugger present", (IsDebuggerPresent() ? "yes" : "no"));

		// GetSystemInfo() does not return correct information
		// when we're running on a x86_64 CPU while in a x86 process,
		// so use GetNativeSystemInfo() instead.
		SYSTEM_INFO systemInfo = { 0 };
		GetNativeSystemInfo(&systemInfo);

		sprintf_s(buffer, sizeof(buffer), "%u", systemInfo.dwNumberOfProcessors);
		WriteKeyValue("CPU count", buffer);

		if (systemInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
		{
			sprintf_s(buffer, sizeof(buffer), "x86-64");
		}
		else if (systemInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_IA32_ON_WIN64)
		{
			sprintf_s(buffer, sizeof(buffer), "x86 on x86-64");
		}
		else
		{
			sprintf_s(buffer, sizeof(buffer), "x86");
		}
		WriteKeyValue("Processor type", buffer);

		sprintf_s(buffer, sizeof(buffer), "%u", systemInfo.wProcessorLevel);
		WriteKeyValue("Processor level", buffer);

		sprintf_s(buffer, sizeof(buffer), "%u", systemInfo.wProcessorRevision);
		WriteKeyValue("Processor revision", buffer);


		MEMORYSTATUSEX memoryStatus = { 0 };
		memoryStatus.dwLength = sizeof(MEMORYSTATUSEX);
		if (GlobalMemoryStatusEx(&memoryStatus))
		{
			sprintf_s(buffer, sizeof(buffer), "%d%%", memoryStatus.dwMemoryLoad);
			WriteKeyValue("Memory load", buffer);

			sprintf_s(buffer, sizeof(buffer), "%I64d Mb", memoryStatus.ullTotalPhys / 1024 / 1024);
			WriteKeyValue("Total physical memory", buffer);

			sprintf_s(buffer, sizeof(buffer), "%I64d Mb", memoryStatus.ullAvailPhys / 1024 / 1024);
			WriteKeyValue("Available physical memory", buffer);

			sprintf_s(buffer, sizeof(buffer), "%I64d Mb", memoryStatus.ullTotalPageFile / 1024 / 1024);
			WriteKeyValue("Total page file memory", buffer);

			sprintf_s(buffer, sizeof(buffer), "%I64d Mb", memoryStatus.ullAvailPageFile / 1024 / 1024);
			WriteKeyValue("Available page file memory", buffer);

			sprintf_s(buffer, sizeof(buffer), "%I64d Mb", memoryStatus.ullTotalVirtual / 1024 / 1024);
			WriteKeyValue("Total virtual memory", buffer);

			sprintf_s(buffer, sizeof(buffer), "%I64d Mb", memoryStatus.ullAvailVirtual / 1024 / 1024);
			WriteKeyValue("Free virtual memory", buffer);
		}

		return true;
	}
};

member_detour(WriteApplicationInfoDetour, Debug::ReportWriter, bool(void))
{
	bool detoured(void)
	{
		bool ret = original_function(this);

		char buffer[256] = { 0 };
		sprintf_s(buffer, sizeof(buffer), "%i.%i.%i", ModAPI::GetMajorVersion(), ModAPI::GetMinorVersion(), ModAPI::GetBuildVersion());
		WriteKeyValue("ModAPI Version", buffer);

		return ret;
	}
};

member_detour(WriteModuleListDetour, Debug::ReportWriter, bool(void))
{
	bool detoured(void)
	{
		HMODULE hModules[256];
		DWORD cbNeeded = 0;
		HANDLE hProcess;
		char fileName[MAX_PATH] = { 0 };
		char fileNameBuffer[MAX_PATH] = { 0 };
		char filePath[MAX_PATH] = { 0 };
		char buffer[2048] = { 0 };
		MODULEINFO moduleInfo = { 0 };

		hProcess = GetCurrentProcess();
		if (hProcess == nullptr)
		{
			WriteText("Failed to retrieve process handle.", true);
			return false;
		}

		if (EnumProcessModules(hProcess, hModules, sizeof(hModules), &cbNeeded))
		{
			for (size_t i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
			{
				if (!GetModuleInformation(hProcess, hModules[i], &moduleInfo, sizeof(moduleInfo)))
				{
					// skip modules for which we can't get module information
					continue;
				}

				if (!GetModuleBaseNameA(hProcess, hModules[i], fileNameBuffer, sizeof(fileNameBuffer)))
				{
					strncpy_s(fileNameBuffer, sizeof(fileNameBuffer), "<unknown>", 10);
				}
				sprintf_s(fileName, sizeof(fileName), "\"%s\"", fileNameBuffer);

				if (!GetModuleFileNameExA(hProcess, hModules[i], filePath, sizeof(filePath)))
				{
					strncpy_s(filePath, sizeof(filePath), "<unknown>", 10);
				}

				sprintf_s(buffer, sizeof(buffer), "base 0x%08x size 0x%08x entry 0x%08x %-48s \"%s\"",
					(UINT32)moduleInfo.lpBaseOfDll, (UINT32)moduleInfo.SizeOfImage, (UINT32)moduleInfo.EntryPoint, fileName, filePath);
				WriteText(buffer, true);
			}
		}

		return true;
	}
};


long DebugReportWriterOverride::AttachDetour()
{
	long result = 0;
	result |= WriteSystemInfoDetour::attach(Address(ModAPI::ChooseAddress(0x0091f480, 0x0091f1c0)));
	result |= WriteApplicationInfoDetour::attach(Address(ModAPI::ChooseAddress(0x0091f850, 0x0091f590)));
	result |= WriteModuleListDetour::attach(Address(ModAPI::ChooseAddress(0x0091fd10, 0x0091fa50)));
	return result;
}
#endif
