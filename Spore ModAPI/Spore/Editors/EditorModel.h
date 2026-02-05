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
#include <Spore\MathUtils.h>
#include <Spore\Editors\EditorRigblock.h>
#include <Spore\Editors\INameableEntity.h>
#include <Spore\Editors\cEditorResource.h>

#include <EASTL\string.h>
#include <EASTL\vector.h>

namespace Editors 
{
	/// Represents the state of a creation in an editor. This class keeps track of all its parts and paints,
	/// and is used to load and save the creation of the editor.
	/// The data can be converted into a cEditorResource with the Load() and Save() methods;
	/// then, you can use the ResourceManager to save the editor resource into a `.crt`, `.bld`, etc file.
	class EditorModel
		: public INameableEntity
		, public IVirtual
	{
	public:
		EditorModel();
		virtual ~EditorModel();

		virtual void SetName(const char16_t* pString) override;
		virtual const char16_t* GetName() override;
		virtual void SetDescription(const char16_t* pString) override;
		virtual const char16_t* GetDescription() override;
		virtual void SetTags(const char16_t* pString) override;
		virtual const char16_t* GetTags() override;


		void Load(cEditorResource* pResource);
		void Save(cEditorResource* pResource);

		void Dispose();

		eastl::string16& GetCreationName() const;

		void SetColor(int index, struct ColorRGB color);

		ColorRGB GetColor(int index) const;

		int GetRigblocksCount() const;
		EditorRigblock* GetRigblock(int index);


		/// skinLayout: 0 — base, 1 — coat, 2 — detail
		int GetSkinEffect(int skinLayout);

		void SetSkinEffect(int skinLayout, uint32_t effectID);

		int GetSkinEffectSeed(int skinLayout);

		void SetSkinEffectSeed(int skinLayout, uint32_t seed);

	protected:
		/* 08h */	int mnRefCount;

	public:
		/* 0Ch */	ResourceKey mKey;
		/* 18h */	eastl::vector<EditorRigblockPtr> mRigblocks;
		/* 2Ch */	bool mbAllBlocksLoaded;
		/* 30h */	int mPhysicsWorld;  // intrusive_ptr, but not to an Object
		/* 34h */	bool mUseDynamics;
		/* 38h */	float mBounds;
		/* 3Ch */	float mFeetBounds;
		/* 40h */	float mMinHeight;  // -2.0
		/* 44h */	float mMaxHeight;  // 2.0
		/* 48h */	float mMinimumLeglessCreatureHeight;
		/* 4Ch */	bool mShowHiddenHandles;
		/* 4Dh */	bool mShowBoneLengthHandles;
		/* 4Eh */	bool mUseBoundsForDelete;  // true
		/* 4Fh */	bool mUsingSymmetry;  //TODO allows symmetry?
		/* 50h */	bool mSkinNeedsUpdating;
		/* 51h */	bool mChanged;
		/* 54h */	int mTranslationOptions;
		/* 58h */	uint32_t mModelType;
		/* 5Ch */	eastl::string16 mName;
		/* 6Ch */	eastl::string16 mDescription;  // message 0x14418C3F ?
		/* 7Ch */	eastl::string16 mAcceptedName;  // the name after removing illegal characters
		/* 8Ch */	uint32_t mSkinEffectIDs[3];	// Skinpaint IDs
		/* 98h */	int mSkinEffectSeeds[3];  // 1234
		/* A4h */	ColorRGB mColors[3];	// Skinpaint Colors
		/* C8h */	eastl::vector<BoundingBox> mBBoxesOverride;
		/* DCh */	int mZCorpScore;  // not initialized
	};
	ASSERT_SIZE(EditorModel, 0xE0);

	namespace Addresses(EditorModel)
	{
		DeclareAddress(SetName);  // 0x4ADC20, 0x4AE280
		DeclareAddress(SetDescription);  // 0x4ADDE0, 0x4AE440
		DeclareAddress(GetCreationName);
		DeclareAddress(SetColor);
		DeclareAddress(Load);  // 0x4AE240, 0x4AE8D0
		DeclareAddress(Save);  // 0x4AF0F0, 0x4AF780
		DeclareAddress(Dispose);  // 0x4AD1F0, 0x4AD850
		DeclareAddress(GetSkinEffect);
		DeclareAddress(SetSkinEffect);
		DeclareAddress(GetSkinEffectSeed);
		DeclareAddress(SetSkinEffectSeed);
	}

#ifndef SDK_TO_GHIDRA
	inline ColorRGB EditorModel::GetColor(int index) const {
		return mColors[index];
	}

	inline int EditorModel::GetRigblocksCount() const {
		return mRigblocks.size();
	}
	inline EditorRigblock* EditorModel::GetRigblock(int index) {
		return mRigblocks[index].get();
	}
#endif
}

