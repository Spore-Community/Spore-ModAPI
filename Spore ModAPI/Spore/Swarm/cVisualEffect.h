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

#include <Spore\Swarm\Components\VisualEffect.h>
#include <Spore\Swarm\IEffectsManager.h>
#include <Spore\Swarm\IVisualEffect.h>
#include <Spore\Swarm\IComponent.h>
#include <Spore\ResourceID.h>
#include <Spore\MathUtils.h>
#include <Spore\Transform.h>
#include <EASTL\intrusive_ptr.h>
#include <EASTL\bitset.h>

namespace Swarm
{
	class cVisualEffect
		: public IVisualEffect
		, public cComponentBase
	{
	public:

		void GetIndex(size_t& dstDirectoryIndex, size_t& dstEffectIndex) const;

		cVisualEffectDescription* GetDescription();

	public:
		enum Flags
		{
			kFlagPaused = 1,
			kFlagHidden = 2,
			kFlagTransformed = 4
		};
		enum tTransitionType
		{
			kSoftTransition = 0,
			kHardTransition = 1
		};

		/* 10h */	int field_10;
		/* 14h */	IEffectsManagerPtr mpManager;
		/* 18h */	uint32_t mInstanceID;
		/* 1Ch */	uint32_t mGroupID;
		/* 20h */	uint32_t mEffectIndex;  // & 0xFF000000 is the EffectDirectory index
		/* 24h */	tTransitionType mStartTransition;
		/* 28h */	cVisualEffectDescription* mpDescription;
		/* 2Ch */	eastl::bitset<13> mFlags;
		/* 30h */	Math::Vector3 mWorldPosition;
		/* 3Ch */	Math::Vector3 mWorldUp;
		/* 48h */	int mCurrentLOD;
		/* 4Ch */	float mCurrentLODLerp;
		/* 50h */	Math::Vector2 mCurrentRange;
		/* 58h */	float mLODDistanceScale;
		/* 5Ch */	uint32_t mNotifyMessageID;
		/* 60h */	uint32_t mNotifyMessageUserData;
		/* 64h */	Transform mRigidTransform;
		/* 9Ch */	Transform mSourceTransform;
		/* D4h */	Transform mCmptRigidTransform;
		/* 10Ch */	Transform mCmptSourceTransform;
		/* 144h */	eastl::vector<int> mComponentRecs;
		/* 158h */	int mRigidBone;	//cIBonePtr
		/* 15Ch */	uint32_t mRigidBoneModCount;
		/* 160h */	int mSourceBone;	//cIBonePtr
		/* 164h */	uint32_t mSourceBoneModCount;
		/* 168h */	Math::Vector2 mLODSizeScale;
		/* 170h */	float mSizeScaleLOD;
		/* 174h */	int mWorld;	//cIEffectsWorld *
		/* 178h */	int mGlobalParams;	//cGlobalParams *
		/* 17Ch */	int mParams;	//cEffectParams *
		/* 180h */	int32_t mnSeed;
		/* 184h */	int field_184;  // not initialized
	};
	ASSERT_SIZE(cVisualEffect, 0x188);


	inline void cVisualEffect::GetIndex(size_t& dstDirectoryIndex, size_t& dstEffectIndex) const
	{
		dstDirectoryIndex = mEffectIndex >> 24;
		dstEffectIndex = mEffectIndex & 0x00FFFFFF;
	}

	inline cVisualEffectDescription* cVisualEffect::GetDescription()
	{
		return mpDescription;
	}
}
