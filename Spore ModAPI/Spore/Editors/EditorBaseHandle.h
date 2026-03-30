#pragma once

#include <Spore\Object.h>
#include <Spore\MathUtils.h>
#include <Spore\Graphics\Model.h>

#define EditorBaseHandlePtr eastl::intrusive_ptr<Editors::EditorBaseHandle>

namespace Editors
{
	class EditorRigblock;

	enum class EditorHandleState : int
	{
		/// User is moving the handle
		Active = 0,
		/// Rigblock is not selected, usually handle is invisible
		Unselected = 1,
		/// Mouse is hovering over the handle
		Rollover = 2,
		/// Rigblock is selected but user is not interacting with handle
		Default = 3
	};

	class EditorBaseHandle
		: public Object
		, public DefaultRefCounted
	{
	public:
		static const uint32_t TYPE = 0x50A1FE5;
		EditorBaseHandle();
		virtual ~EditorBaseHandle();

		virtual int AddRef() override;
		virtual int Release() override;
		virtual void* Cast(uint32_t typeID) const override;
		/* 10h */	virtual uint32_t GetTypeID();
		/* 14h */	virtual void PlaceHandle();
		// also used to unload
		/* 18h */	virtual void Init(EditorRigblock* pRigblock, bool initHandles, uint32_t pHandleModel, uint32_t pOverdrawHandleModel);
		/* 1Ch */	virtual void Shutdown();
		/// Sets the scale (scaling the model and overdraw model), which gets multiplied by `mDefaultScale`
		/// @param scale
		/* 20h */	virtual void SetScale(float scale);
		/* 24h */	virtual Math::Vector3 GetHandlePosition();
		/* 28h */	virtual void SetUIState(bool pSetHightlight, EditorHandleState state);
		/* 2Ch */	virtual void AnimateOn();
		/* 30h */	virtual void SetState(EditorHandleState state, bool animateIt);
		/* 34h */	virtual ResourceKey GetTuningFile();
		/* 38h */	virtual float GetAlpha(EditorHandleState state);
		/* 3Ch */	virtual float GetOverdrawAlpha(EditorHandleState state);
		/* 40h */	virtual Math::ColorRGB GetColor(EditorHandleState state);
		/* 44h */	virtual Math::ColorRGB GetOverdrawColor(EditorHandleState state);
		/* 48h */	virtual float GetDefaultScale();

	public:
		/* 0Ch */	PropertyListPtr mpPropList;
		/* 10h */	EditorRigblock* mpRigblock;
		/* 14h */	ModelPtr mpModel;
		/* 18h */	ModelPtr mpOverdrawModel;
		/* 1Ch */	EditorHandleState mCurrentState;  // not initialized, maybe state?
		/* 20h */	float mFadeInTime;
		/* 24h */	float mFadeOutTime;
		/* 28h */	float mAnimateInTime;
		/* 2Ch */	float mAnimateOutTime;
		/* 30h */	ResourceKey mDefaultModel;
		/* 3Ch */	ResourceKey mDefaultOverdrawModel;
		/* 48h */	bool mHasOverdraw;
		/* 4Ch */	float mDefaultScale;
	};
	ASSERT_SIZE(EditorBaseHandle, 0x50);

	namespace Addresses(EditorBaseHandle)
	{
		DeclareAddress(AddRef);
		DeclareAddress(Release);
		DeclareAddress(Cast);
		DeclareAddress(GetTypeID);
		DeclareAddress(PlaceHandle);
		DeclareAddress(Init);
		DeclareAddress(Shutdown);
		DeclareAddress(SetScale);
		DeclareAddress(GetHandlePosition);
		DeclareAddress(SetUIState);
		DeclareAddress(AnimateOn);
		DeclareAddress(SetState);
		DeclareAddress(GetTuningFile);
		DeclareAddress(GetAlpha);
		DeclareAddress(GetOverdrawAlpha);
		DeclareAddress(GetColor);
		DeclareAddress(GetOverdrawColor);
		DeclareAddress(GetDefaultScale);
	}

	inline EditorBaseHandle::EditorBaseHandle()
		: mpPropList(nullptr)
		, mpRigblock(nullptr)
		, mpModel(nullptr)
		, mpOverdrawModel(nullptr)
		, mCurrentState()
		, mFadeInTime()
		, mFadeOutTime()
		, mAnimateInTime()
		, mAnimateOutTime()
		, mDefaultModel()
		, mDefaultOverdrawModel()
		, mHasOverdraw(false)
		, mDefaultScale(1.0)
	{
	}
	inline EditorBaseHandle::~EditorBaseHandle() {
		EditorBaseHandle::Shutdown();
	}
	inline int EditorBaseHandle::AddRef() {
		return DefaultRefCounted::AddRef();
	}
	inline int EditorBaseHandle::Release() {
		return DefaultRefCounted::Release();
	}
	inline void* EditorBaseHandle::Cast(uint32_t type) const {
		CLASS_CAST(Object);
		CLASS_CAST(EditorBaseHandle);
		return nullptr;
	}
	inline float EditorBaseHandle::GetAlpha(EditorHandleState state)
	{
		return 1;
	}
	inline float EditorBaseHandle::GetOverdrawAlpha(EditorHandleState state)
	{
		return 1;
	}
	inline Math::ColorRGB EditorBaseHandle::GetColor(EditorHandleState state)
	{
		return { 1,1,1 };
	}
	inline Math::ColorRGB EditorBaseHandle::GetOverdrawColor(EditorHandleState state)
	{
		return { 1,1,1 };
	}

#ifndef SDK_TO_GHIDRA

	inline auto_METHOD_(EditorBaseHandle, uint32_t, GetTypeID);
	inline auto_METHOD_VOID_(EditorBaseHandle, PlaceHandle);
	inline auto_METHOD_VOID(EditorBaseHandle, Init, Args(EditorRigblock* pRigblock, bool initHandles, uint32_t pHandleModel, uint32_t pOverdrawHandleModel), Args(pRigblock, initHandles, pHandleModel, pOverdrawHandleModel));
	inline auto_METHOD_VOID_(EditorBaseHandle, Shutdown);
	inline auto_METHOD_VOID(EditorBaseHandle, SetScale, Args(float scale), Args(scale));
	inline auto_METHOD_(EditorBaseHandle, Math::Vector3, GetHandlePosition);
	inline auto_METHOD_VOID(EditorBaseHandle, SetUIState, Args(bool pSetHightlight, EditorHandleState state), Args(pSetHightlight, state));
	inline auto_METHOD_VOID_(EditorBaseHandle, AnimateOn);
	inline auto_METHOD_VOID(EditorBaseHandle, SetState, Args(EditorHandleState state, bool animateIt), Args(state, animateIt));
	inline auto_METHOD_(EditorBaseHandle, ResourceKey, GetTuningFile);
	//inline auto_METHOD(EditorBaseHandle, float, GetAlpha, Args(EditorHandleState state), Args(state));
	//inline auto_METHOD(EditorBaseHandle, float, GetOverdrawAlpha, Args(EditorHandleState state), Args(state));
	//inline auto_METHOD(EditorBaseHandle, Math::ColorRGB, GetColor, Args(EditorHandleState state), Args(state));
	//inline auto_METHOD(EditorBaseHandle, Math::ColorRGB, GetOverdrawColor, Args(EditorHandleState state), Args(state));
	inline auto_METHOD_(EditorBaseHandle, float, GetDefaultScale);

#endif
}