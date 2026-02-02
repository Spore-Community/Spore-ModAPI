#pragma once

#include <Spore\Sporepedia\AssetData.h>
#include <Spore/UTFWin/IWinProc.h>
#include <Spore/UTFWin/cSPUIMessageBox.h>
#include <Spore/App/IMessageListener.h>

#define AssetViewManager (*Sporepedia::cAssetViewManager::Get())

namespace Sporepedia
{
	typedef cSPAssetDataOTDB* (*AssetDataFactory)();

	class class_B8 {
		// this is a PLACEHOLDER class
	public:
		void SetAssetDataFactory(uint32_t typeID, AssetDataFactory factory);
	};

	class cAssetViewManager
		: public App::IMessageListener
		, public UTFWin::MessageBoxCallback
		, public UTFWin::IWinProc
		, public DefaultRefCounted
	{
	public:
		static cAssetViewManager* Get();

	public:
		char padding_0[0x88];
		int mCurrentLargeAssetView;
		char padding_1[0x18];
		class_B8* field_B8;
		//TODO more things
	};
	//0x250

	namespace Addresses(cAssetViewManager)
	{
		DeclareAddress(Get);
	}

	namespace Addresses(class_B8) 
	{
		DeclareAddress(SetAssetDataFactory);
	}
}