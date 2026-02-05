#ifndef MODAPI_DLL_EXPORT
#include <Spore\Editors\Editor.h>
#include <Spore\Editors\EditorRigblock.h>
#include <Spore\Editors\EditorModel.h>
#include <Spore\Editors\TuningSpine.h>
#include <Spore\Editors\cEditorAnimEvent.h>
#include <EASTL\internal\thread_support.h>

namespace Editors
{
	auto_METHOD(cEditor, bool, sub_581F70, Args(EditorRigblock* part, void* activeHandle, int value), Args(part, activeHandle, value));

	auto_METHOD_VOID(cEditor, SetEditorModel, Args(EditorModel* pEditorModel), Args(pEditorModel));
	auto_METHOD_VOID(cEditor, CommitEditHistory, Args(bool p, EditorStateEditHistory* pStateHistory), Args(p, pStateHistory));
	auto_METHOD_VOID(cEditor, Undo, Args(bool a, bool b), Args(a, b));
	auto_METHOD_VOID_(cEditor, Redo);
	auto_METHOD_VOID_(cEditor, SetCreatureToNeutralPose);
	auto_METHOD_VOID(cEditor, SetActiveMode, Args(Mode mode, bool arg), Args(mode, arg));

	auto_METHOD_VOID_(EditorModel, Dispose);
	auto_METHOD_const_(EditorModel, eastl::string16&, GetCreationName);
	auto_METHOD_VOID(EditorModel, SetColor, Args(int index, struct ColorRGB color), Args(index, color));
	auto_METHOD_VOID(EditorModel, Load, Args(cEditorResource* pResource), Args(pResource));
	auto_METHOD_VOID(EditorModel, Save, Args(cEditorResource* pResource), Args(pResource));

	auto_STATIC_METHOD_(cTuningSpine, cTuningSpine*, Get);


	int IEditorLimits::AddRef() {
		++mnRefCount;
		return mnRefCount;
	}

	int IEditorLimits::Release() {
		--mnRefCount;
		if (mnRefCount == 0) {
			delete this;
			return 0;
		}
		return mnRefCount;
	}


	auto_METHOD_VIRTUAL_VOID(EditorModel, INameableEntity, SetName, Args(const char16_t* pString), Args(pString));
	auto_METHOD_VIRTUAL_VOID(EditorModel, INameableEntity, SetDescription, Args(const char16_t* pString), Args(pString));

	const char16_t* EditorModel::GetName() {
		return mName.c_str();
	}

	const char16_t* EditorModel::GetDescription() {
		return mDescription.c_str();
	}

	void EditorModel::SetTags(const char16_t* pString) {}
	const char16_t* EditorModel::GetTags() { return nullptr; }

	EditorModel::EditorModel()
		: mnRefCount(0)
		, mKey()
		, mRigblocks()
		, mbAllBlocksLoaded()
		, mPhysicsWorld()
		, mUseDynamics()
		, mBounds()
		, mFeetBounds()
		, mMinHeight(-2.0f)
		, mMaxHeight(2.0f)
		, mMinimumLeglessCreatureHeight()
		, mShowHiddenHandles()
		, mShowBoneLengthHandles()
		, mUseBoundsForDelete(true)
		, mUsingSymmetry()
		, mSkinNeedsUpdating()
		, mChanged()
		, mTranslationOptions()
		, mModelType()
		, mName()
		, mDescription()
		, mAcceptedName()
		, mSkinEffectIDs()
		, mSkinEffectSeeds{1234, 1234, 1234}
		, mColors {ColorRGB(1.0f, 1.0f, 1.0f), ColorRGB(1.0f, 1.0f, 1.0f), ColorRGB(1.0f, 1.0f, 1.0f)}
		, mBBoxesOverride()
	{
	}

	EditorModel::~EditorModel()
	{
		Dispose();

		// field_30 is a pointer, but I don't know what kind so we manually Release it
		if (mPhysicsWorld != 0) {
			int* pointer = (int*)mPhysicsWorld;
			pointer[1]--;
			if (pointer[1] == 0) {
				pointer[1] = 1;
				delete ((IVirtual*)pointer);
			}
		}
	}

	cEditorResource::cEditorResource()
		: mBlocks()
		, mProperties {}
	{
	}

	cEditorResource::~cEditorResource()
	{}

	void* cEditorResource::Cast(uint32_t type) const
	{
		if (type == cEditorResource::TYPE) return (cEditorResource*)this;
		else return Resource::ResourceObject::Cast(type);
	}


	auto_METHOD(cEditorSkin, cEditorSkinMesh*, GetMesh, Args(int hq), Args(hq));

	auto_METHOD_(cEditorSkin, bool, IsPainting);

	auto_METHOD(cEditorSkin, bool, PaintSkin, Args(EditorModel* editorModel), Args(editorModel));


	cEditorAnimEvent::cEditorAnimEvent()
		: field_C()
		, field_10()
		, mpEditorModel()
		, mEventID()
		, field_1C()
		, field_20()
		, field_24()
		, field_28(-1)
		, field_2C(1.0f)
	{
	}

	int cEditorAnimEvent::AddRef()
	{
		return eastl::Internal::atomic_increment(&mnRefCount);
	}

	int cEditorAnimEvent::Release()
	{
		int count = eastl::Internal::atomic_decrement(&mnRefCount);
		if (count == 0)
		{
			return mnRefCount;
		}
		return count;
	}

	int cEditorAnimEvent::GetReferenceCount()
	{
		eastl::Internal::atomic_increment(&mnRefCount);
		return eastl::Internal::atomic_decrement(&mnRefCount);
	}

	auto_METHOD_VOID(cEditorAnimEvent, MessageSend,
		Args(uint32_t eventID, int arg1, EditorModel* arg2, int arg3, bool arg4, float arg5, bool arg6, int arg7, float arg8),
		Args(eventID, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8));

	auto_METHOD_VOID(cEditorAnimEvent, MessagePost,
		Args(uint32_t eventID, int arg1, EditorModel* arg2, int arg3, bool arg4, float arg5, bool arg6, int arg7, float arg8),
		Args(eventID, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8));


	auto_METHOD(cEditorAnimWorld, EditorCreatureController*, GetCreatureController,
		Args(int creatureID), Args(creatureID));

	auto_METHOD(cEditorAnimWorld, Anim::AnimatedCreature*, GetAnimatedCreature,
		Args(int creatureID), Args(creatureID));

	auto_METHOD(cEditor, bool, AddCreature,
		Args(int a, const ResourceKey* key), Args(a, key));

	auto_METHOD_VOID(cEditorAnimWorld, DestroyCreature,
		Args(int creatureID), Args(creatureID));

	auto_METHOD_VOID(cEditorAnimWorld, SetTargetPosition,
		Args(int creatureID, struct Math::Vector3 position, bool applyNow, bool ignoreZ), 
		Args(creatureID, position, applyNow, ignoreZ));

	auto_METHOD_VOID(cEditorAnimWorld, SetTargetAngle,
		Args(int creatureID, float angle, bool applyNow), Args(creatureID, angle, applyNow));


	auto_METHOD_VOID(cEditor, PostEventToActors,
		Args(uint32_t eventID, int a, float b, float c), Args(eventID, a, b, c));



	auto_METHOD_VOID(EditorRigblock, SetShadedDisplay, Args(bool isShaded), Args(isShaded));

	auto_STATIC_METHOD(cEditor, uint32_t, GetEditorForAssetType, Args(uint32_t assetTypeID), Args(assetTypeID));

	auto_STATIC_METHOD(cEditor, uint32_t, GetTypeIDForAssetType, Args(uint32_t assetTypeID), Args(assetTypeID));

	auto_STATIC_METHOD(cEditor, const char16_t*, GetNameForAssetType, Args(uint32_t assetTypeID), Args(assetTypeID));
	
	auto_STATIC_METHOD_VOID(cEditor, ComputeCreatureVerbIcons, Args(cCreatureDataResource* creatureData, cSPVerbTrayCollection* VerbTrayCollection, int brainLevel, float param_4), Args(creatureData, VerbTrayCollection, brainLevel, param_4));


	auto_STATIC_METHOD(cEditor, bool, LoadCreatureData,Args(ResourceKey* creation, cCreatureDataResource** dst), Args(creation, dst));

	auto_METHOD(EditorModel, int, GetSkinEffect, Args(int skinLayout), Args(skinLayout));

	auto_METHOD(EditorModel, int, GetSkinEffectSeed, Args(int skinLayout), Args(skinLayout));

	auto_METHOD_VOID(EditorModel, SetSkinEffect, Args(int skinLayout, uint32_t effectID), Args(skinLayout, effectID));
	auto_METHOD_VOID(EditorModel, SetSkinEffectSeed, Args(int skinLayout, uint32_t seed), Args(skinLayout, seed));
}
#endif
