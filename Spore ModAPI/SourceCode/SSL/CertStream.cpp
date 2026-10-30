#ifndef MODAPI_DLL_EXPORT
/****************************************************************************
* Copyright (C) 2026 Rosalie Wanders
*
* This file is part of Spore ModAPI.
*
* Spore ModAPI is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
****************************************************************************/
#include <Spore\SSL\CertStream.h>

namespace SSL
{
	CertStream::CertStream() :
		mpBuffer(nullptr),
		mnBufSize(0),
		mnPosition(0)
	{
		//*(void**)this = (void*)GetAddress(CertStream, _vftable);
	}

	CertStream::~CertStream() = default;

	auto_METHOD_VIRTUAL_(CertStream, IStream, int, AddRef);
	auto_METHOD_VIRTUAL_(CertStream, IStream, int, Release);

	auto_METHOD_VIRTUAL_const_(CertStream, IStream, uint32_t, GetType);
	auto_METHOD_VIRTUAL_const_(CertStream, IStream, IO::AccessFlags, GetAccessFlags);
	auto_METHOD_VIRTUAL_const_(CertStream, IStream, IO::FileError, GetState);
	auto_METHOD_VIRTUAL_(CertStream, IStream, bool, Close);

	auto_METHOD_VIRTUAL_const_(CertStream, IStream, IO::size_type, GetSize);
	auto_METHOD_VIRTUAL(CertStream, IStream, bool, SetSize, Args(IO::size_type size), Args(size));
	auto_METHOD_VIRTUAL_const(CertStream, IStream, int, GetPosition, Args(IO::PositionType positionType), Args(positionType));
	auto_METHOD_VIRTUAL(CertStream, IStream, bool, SetPosition, Args(int distance, IO::PositionType positionType), Args(distance, positionType));
	auto_METHOD_VIRTUAL_const_(CertStream, IStream, int, GetAvailable);

	auto_METHOD_VIRTUAL(CertStream, IStream, int, Read, Args(void* pData, size_t nSize), Args(pData, nSize));
	auto_METHOD_VIRTUAL_(CertStream, IStream, bool, Flush);
	auto_METHOD_VIRTUAL(CertStream, IStream, int, Write, Args(const void* pData, size_t nSize), Args(pData, nSize));
}

#endif