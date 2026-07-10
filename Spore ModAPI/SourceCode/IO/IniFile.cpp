#ifndef MODAPI_DLL_EXPORT

#include <Spore\IO\IniFile.h>

namespace IO
{
	IniFile::IniFile(const wchar_t* pPath, int optionFlags)
		: mFileStream((char*)nullptr)
		, mpStream(nullptr)
		, mnEncodingSrc(8)
		, mbFileIsOpenForWriting(false)
		, mbReadEntryCacheReady(false)
		, mbLeaveFileOpenBetweenOperations(optionFlags & 1)
		, mSectionPositionMap()
		, mSectionNameMap()
	{
		*(void**)this = (void*)GetAddress(IniFile, _vftable);
		mPath[0] = L'\0';
		IniFile::SetPath(pPath);
	}

	IniFile::IniFile(IStream* pStream)
		: mFileStream((char*)nullptr)
		, mnEncodingSrc(8)
		, mbFileIsOpenForWriting(false)
		, mbReadEntryCacheReady(false)
		, mbLeaveFileOpenBetweenOperations(true)
		, mSectionPositionMap()
		, mSectionNameMap()
		, mpStream(pStream)
	{
		*(void**)this = (void*)GetAddress(IniFile, _vftable);
		mPath[0] = L'\0';
	}

	IniFile::~IniFile() = default;

	auto_METHOD_VIRTUAL_const(IniFile, IniFile, int, GetOption, Args(Options option), Args(option));
	auto_METHOD_VIRTUAL_VOID(IniFile, IniFile, SetOption, Args(Options option, int value), Args(option, value));
	auto_METHOD_VIRTUAL_const_(IniFile, IniFile, wchar_t const*, GetPath);
	auto_METHOD_VIRTUAL(IniFile, IniFile, bool, SetPath, Args(const wchar_t* pPath), Args(pPath));
	auto_METHOD_VIRTUAL_const_(IniFile, IniFile, IStream*, GetStream);
	auto_METHOD_VIRTUAL(IniFile, IniFile, bool, SetStream, Args(IStream* pStream), Args(pStream));
	auto_METHOD_VIRTUAL_(IniFile, IniFile, bool, Close);
	auto_METHOD_VIRTUAL(IniFile, IniFile, int, ReadEntry, Args(const wchar_t* pSection, const wchar_t* pKey, eastl::basic_string<wchar_t>& sValue), Args(pSection, pKey, sValue));
	auto_METHOD_VIRTUAL(IniFile, IniFile, int, ReadEntryToBuffer, Args(const wchar_t* pSection, const wchar_t* pKey, wchar_t* pValue, uint32_t nValueLength), Args(pSection, pKey, pValue, nValueLength));
	// Stub, do not detour.
	int __cdecl IniFile::ReadEntryFormatted(const wchar_t* pSection, const wchar_t* pKey, const wchar_t* pValueFormat, ...) { return 0; }
	auto_METHOD_VIRTUAL(IniFile, IniFile, bool, WriteEntry, Args(const wchar_t* pSection, const wchar_t* pKey, const wchar_t* pValue), Args(pSection, pKey, pValue));
	// Stub, do not detour.
	bool __cdecl IniFile::WriteEntryFormatted(const wchar_t* pSection, const wchar_t* pKey, const wchar_t* kValueFormat, ...) { return 0; }
	auto_METHOD_VIRTUAL(IniFile, IniFile, int, ReadBinary, Args(const wchar_t* pSection, const wchar_t* pKey, void* pData, uint32_t nDataLength), Args(pSection, pKey, pData, nDataLength));
	auto_METHOD_VIRTUAL(IniFile, IniFile, bool, WriteBinary, Args(const wchar_t* pSection, const wchar_t* pKey, const void* pData, uint32_t nDataLength), Args(pSection, pKey, pData, nDataLength));
	auto_METHOD_VIRTUAL(IniFile, IniFile, int, EnumSections, Args(EnumCallback_t pCallback, void* pContext), Args(pCallback, pContext));
	auto_METHOD_VIRTUAL(IniFile, IniFile, int, EnumEntries, Args(const wchar_t* pSection, EnumCallback_t pCallback, void* pContext), Args(pSection, pCallback, pContext));
	auto_METHOD_VIRTUAL(IniFile, IniFile, bool, SectionExists, Args(const wchar_t* pSection), Args(pSection));
	auto_METHOD_VIRTUAL(IniFile, IniFile, bool, Open, Args(int nAccessFlags), Args(nAccessFlags));
	auto_METHOD_VIRTUAL_(IniFile, IniFile, int, GetEncoding);
	auto_METHOD_VIRTUAL(IniFile, IniFile, bool, LoadSectionNames, Args(int nAccessFlags), Args(nAccessFlags));
	auto_METHOD_VIRTUAL(IniFile, IniFile, bool, GetFileLine8To8, Args(eastl::basic_string<char>& sLine), Args(sLine));
	auto_METHOD_VIRTUAL(IniFile, IniFile, bool, GetFileLine16To16, Args(eastl::basic_string<wchar_t>& sLine), Args(sLine));
	auto_METHOD_VIRTUAL(IniFile, IniFile, bool, GetFileLine, Args(eastl::basic_string<wchar_t>& sLine), Args(sLine));
	auto_METHOD_VIRTUAL(IniFile, IniFile, bool, ConvertAndWriteStream, Args(const wchar_t* pchar, uint32_t count), Args(pchar, count));
}

#endif
