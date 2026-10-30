#ifdef MODAPI_DLL_EXPORT
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
	namespace Addresses(CertStream)
	{
		DefineAddress(AddRef, SelectAddress(0x01098140, 0x00dd3ca0));
		DefineAddress(Release, SelectAddress(0x00e1cf40, 0x01154790));
		DefineAddress(GetType, SelectAddress(0x007c7fe0, 0x007c7950));
		DefineAddress(GetAccessFlags, SelectAddress(0x00e1cf40, 0x01154790));
		DefineAddress(GetState, SelectAddress(0x007c7ff0, 0x007c7960));
		DefineAddress(Close, SelectAddress(0x007c80b0, 0x007c7a20));
		DefineAddress(GetSize, SelectAddress(0x00923c40, 0x0093b630));
		DefineAddress(SetSize, SelectAddress(0x0101b0f0, 0x00dde930));
		DefineAddress(GetPosition, SelectAddress(0x007c8010, 0x007c7980));
		DefineAddress(SetPosition, SelectAddress(0x00951320, 0x00950e00));
		DefineAddress(GetAvailable, SelectAddress(0x007c8000, 0x007c7970));
		DefineAddress(Read, SelectAddress(0x007c8040, 0x007c79b0));
		DefineAddress(Flush, SelectAddress(0x0066ad60, 0x00b1e410));
		DefineAddress(Write, SelectAddress(0x00951320, 0x00950e00));
	}
}

#endif