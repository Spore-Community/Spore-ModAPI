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
#pragma once

#include <Spore\Internal.h>
#include <Spore\IO\Constants.h>
#include <Spore\IO\IStream.h>

namespace SSL
{
	class CertStream
		: public IO::IStream
	{
	protected:
		/* 04h */ char* mpBuffer;
		/* 08h */ uint32_t mnBufSize;
		/* 0Ch */ uint32_t mnPosition;
		/* 10h */ // cRandomMaxSequence mMaxSequence

	public:
		static const uint32_t TYPE = 0x5ca906f;

		CertStream();

		/* 00h */ ~CertStream();
		/* 04h */ virtual int AddRef() override;
		/* 08h */ virtual int Release() override;
		/* 0Ch */ virtual uint32_t GetType() const override;
		/* 10h */ virtual IO::AccessFlags GetAccessFlags() const override;
		/* 14h */ virtual IO::FileError GetState() const override;
		/* 18h */ virtual bool Close() override;
		/* 1Ch */ virtual IO::size_type GetSize() const override;
		/* 20h */ virtual bool SetSize(IO::size_type size) override;
		/* 24h */ virtual int GetPosition(IO::PositionType positionType = IO::PositionType::Begin) const override;
		/* 28h */ virtual bool SetPosition(int distance, IO::PositionType positionType = IO::PositionType::Begin) override;
		/* 2Ch */ virtual int GetAvailable() const override;
		/* 30h */ virtual int Read(void* pData, size_t nSize) override;
		/* 34h */ virtual bool Flush() override;
		/* 38h */ virtual int Write(const void* pData, size_t nSize) override;
	};

	namespace Addresses(CertStream)
	{
		DeclareAddress(AddRef);
		DeclareAddress(Release);
		DeclareAddress(GetType);
		DeclareAddress(GetAccessFlags);
		DeclareAddress(GetState);
		DeclareAddress(Close);
		DeclareAddress(GetSize);
		DeclareAddress(SetSize);
		DeclareAddress(GetPosition);
		DeclareAddress(SetPosition);
		DeclareAddress(GetAvailable);
		DeclareAddress(Read);
		DeclareAddress(Flush);
		DeclareAddress(Write);
	};
}
