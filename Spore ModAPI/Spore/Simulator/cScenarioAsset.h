/****************************************************************************
* Copyright (C) 2019 Eric Mor
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

#include <Spore\ResourceKey.h>

namespace Simulator
{
	class cScenarioAsset
	{
	public:

		/// Gets the ResourceKey of an asset thumbnail to display in the editor palette.
		/// @param[out] dst The destination value that will be assigned with the ResourceKey of a thumbnail.
		void GetThumbnail(ResourceKey& dst);

		/* 00h */	ResourceKey mKey;
		/* 0Ch */	uint32_t mMachineId;
		/* 10h */	uint64_t mServerId;
		/* 18h */	uint32_t mModelType;
		/* 1Ch */	bool field_1C;
	};
	ASSERT_SIZE(cScenarioAsset, 0x20);

	namespace Addresses(cScenarioAsset)
	{
		DeclareAddress(GetThumbnail);
	}
}