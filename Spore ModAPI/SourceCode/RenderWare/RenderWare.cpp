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
#include <Spore\RenderWare\RWHeader.h>
#include <Spore\RenderWare\CompiledState.h>

namespace RenderWare
{
	auto_METHOD_VOID(RWHeader, GetRWObject, Args(int index, RWObjectQuery& query), Args(index, query));

	RWObjectQuery::RWObjectQuery()
		: typeCode(0)
		, pData(nullptr)
		, field_8()
		, field_18()
	{
	}


	bool CompiledState::SetTransform(const Math::Matrix4& matrix, Graphics::GlobalState::MatrixType type)
	{
		if ((softStateDirty & (int)Flags::UseTransform) != 0) {
			auto data = GetData();
			*((Math::Matrix4*)data) = matrix;

			softStateDirty &= 0x0FFFFFFF;
			softStateDirty |= type << 28;
			return true;
		}
		return false;
	}
}
