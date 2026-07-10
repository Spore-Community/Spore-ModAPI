#pragma once

#include <EASTL\map.h>
#include "FileStream.h"

namespace IO
{
	///
	/// A class that is used to read, parse, and write INI configuration files.
	/// Stub, do not detour.
	///
	class IniFile
	{
	public:
		enum Options
		{
			kOptionNone,
			kOptionLeaveFileOpen
		};

		typedef bool(*EnumCallback_t)(wchar_t*, wchar_t*, void*);

		IniFile(const wchar_t* pPath, int optionFlags);
		IniFile(IStream* pStream);

		/* 00h */	virtual ~IniFile() final;
		/* 04h */	virtual int GetOption(Options option) const;
		/* 08h */	virtual void SetOption(Options option, int value);
		/* 0Ch */	virtual wchar_t const* GetPath() const;
		/* 10h */	virtual bool SetPath(const wchar_t* pPath);
		/* 14h */	virtual IStream* GetStream() const;
		/* 18h */	virtual bool SetStream(IStream* pStream);
		/* 1Ch */	virtual bool Close();
		/* 20h */	virtual int ReadEntry(const wchar_t* pSection, const wchar_t* pKey, eastl::basic_string<wchar_t>& sValue);
		/* 24h */	virtual int ReadEntryToBuffer(const wchar_t* pSection, const wchar_t* pKey, wchar_t* pValue, uint32_t nValueLength);
		// Stub, do not detour.
		/* 28h */	virtual int ReadEntryFormatted(const wchar_t* pSection, const wchar_t* pKey, const wchar_t* pValueFormat, ...);
		/* 2Ch */	virtual bool WriteEntry(const wchar_t* pSection, const wchar_t* pKey, const wchar_t* pValue);
		// Stub, do not detour.
		/* 30h */	virtual bool WriteEntryFormatted(const wchar_t* pSection, const wchar_t* pKey, const wchar_t* kValueFormat, ...);
		/* 34h */	virtual int ReadBinary(const wchar_t* pSection, const wchar_t* pKey, void* pData, uint32_t nDataLength);
		/* 38h */	virtual bool WriteBinary(const wchar_t* pSection, const wchar_t* pKey, const void* pData, uint32_t nDataLength);
		/* 3Ch */	virtual int EnumSections(EnumCallback_t pCallback, void* pContext);
		/* 40h */	virtual int EnumEntries(const wchar_t* pSection, EnumCallback_t pCallback, void* pContext);
		/* 44h */	virtual bool SectionExists(const wchar_t* pSection);
	protected:
		/* 48h */	virtual bool Open(int nAccessFlags);
		/* 4Ch */	virtual int GetEncoding();
		/* 50h */	virtual bool LoadSectionNames(int nAccessFlags);
		/* 54h */	virtual bool GetFileLine8To8(eastl::basic_string<char>& sLine);
		/* 58h */	virtual bool GetFileLine16To16(eastl::basic_string<wchar_t>& sLine);
		/* 5Ch */	virtual bool GetFileLine(eastl::basic_string<wchar_t>& sLine);
		/* 60h */	virtual bool ConvertAndWriteStream(const wchar_t* pchar, uint32_t count);

		/* 04h */	wchar_t mPath[260];
		/* 20Ch */	FileStream mFileStream;
		/* 438h */	IStream* mpStream;
		/* 43Ch */	int mnEncodingSrc;
		/* 440h */	bool mbFileIsOpenForWriting;
		/* 441h */	bool mbLeaveFileOpenBetweenOperations;
		/* 442h */	bool mbReadEntryCacheReady;
		/* 444h */	eastl::map<eastl::basic_string<wchar_t>, long, eastl::less<eastl::basic_string<wchar_t>>> mSectionPositionMap;
		/* 460h */	eastl::map<eastl::basic_string<wchar_t>, eastl::basic_string<wchar_t>, eastl::less<eastl::basic_string<wchar_t>>> mSectionNameMap;
	};
	ASSERT_SIZE(IniFile, 0x47C);

	namespace Addresses(IniFile)
	{
		DeclareAddress(GetOption);
		DeclareAddress(SetOption);
		DeclareAddress(GetPath);
		DeclareAddress(SetPath);
		DeclareAddress(GetStream);
		DeclareAddress(SetStream);
		DeclareAddress(Close);
		DeclareAddress(ReadEntry);
		DeclareAddress(ReadEntryToBuffer);
		DeclareAddress(ReadEntryFormatted);
		DeclareAddress(WriteEntry);
		DeclareAddress(WriteEntryFormatted);
		DeclareAddress(ReadBinary);
		DeclareAddress(WriteBinary);
		DeclareAddress(EnumSections);
		DeclareAddress(EnumEntries);
		DeclareAddress(SectionExists);
		DeclareAddress(Open);
		DeclareAddress(GetEncoding);
		DeclareAddress(LoadSectionNames);
		DeclareAddress(GetFileLine8To8);
		DeclareAddress(GetFileLine16To16);
		DeclareAddress(GetFileLine);
		DeclareAddress(ConvertAndWriteStream);
		// stub
		DeclareAddress(_vftable);
	}
}