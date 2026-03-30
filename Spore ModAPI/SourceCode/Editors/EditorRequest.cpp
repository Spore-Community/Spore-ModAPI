#ifndef MODAPI_DLL_EXPORT
#include <Spore\Editors\EditorRequest.h>
#include <Spore\App\IGameModeManager.h>

namespace Editors
{
	EditorRequest::EditorRequest()
		: mRefCount()
		, mEditorName(-1)
		, mModelKey()
		, mCallingGameModeID(GameModeManager.GetActiveModeID())
		, mbIsFirstTimeInEditor()
		, mEditableTests()
		, mbSporepediaCanSwitch()
		, mbDisableNameEdit()
		, mbAllowSporepedia()
		, mShowSaveButton()
		, mShowNewButton()
		, mShowExitButton(true)
		, mShowPublishButton()
		, mShowCancelButton(true)
		, field_3C()
		, field_3D(true)
		, field_40()
		, field_50()
		, field_60()
		, field_64()
		, mShowPlayButton()
		, field_66()
		, field_68()
		, field_6C()
		, field_6D(true)
		, field_6E(true)
		, field_6F()
		, mConsequenceTraits()
		, field_84()
		, field_88()
		, field_8C()
		, field_90()
		, mpCollectableItems(nullptr)
		, mpNext(nullptr)
	{
	}

	EditorRequest::~EditorRequest() {}

	int EditorRequest::AddRef() {
		++mRefCount;
		return mRefCount;
	}

	int EditorRequest::Release() {
		--mRefCount;
		if (!mRefCount) delete this;
		return mRefCount;
	}

	auto_STATIC_METHOD(EditorRequest, bool, Submit, Args(EditorRequest* request), Args(request));
}
#endif
