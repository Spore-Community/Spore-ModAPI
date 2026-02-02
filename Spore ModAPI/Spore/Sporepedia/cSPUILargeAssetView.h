#pragma once

#include <Spore\UTFWin\IWindow.h>
#include <Spore\UTFWin\UILayout.h>
#include <Spore\App\IMessageListener.h>
#include <Spore\Sporepedia\AssetData.h>
#include <Spore\Sporepedia\ISPUILargeAssetView.h>
#include <Spore\Editors\cSPEditorVerbTrayCollection.h>
#include <Spore\UI\cSPAssetView.h>
#include <Spore\App\MessageListenerData.h>
#include <EASTL\intrusive_ptr.h>

#define cSPUIAssetViewPtr eastl::intrusive_ptr<Sporepedia::cSPUILargeAssetView>

namespace Sporepedia
{
    class cSPUILargeAssetViewSmh
    {
        /* 00h */	virtual void* Dispose();
        /* 04h */	virtual bool func04h(int unk, int unk2);
        /* 08h */	virtual int AddRef();
        /* 0Ch */	virtual int Release();
    };
    ASSERT_SIZE(cSPUILargeAssetViewSmh, 0x4);

	class cSPUILargeAssetView
        : public ISPUILargeAssetView
        , public cSPUILargeAssetViewSmh
		, public UTFWin::IWinProc
		, public App::IMessageListener
		, public DefaultRefCounted
	{
	public:
    /* 18h */   UILayoutPtr mLayout;
    /* 1Ch */   IWindowPtr mWinParent;
    /* 20h */   IWindowPtr mWinRoot;
    /* 24h */   int field_24;
    /* 28h */   int field_28;
    /* 2Ch */   IWindowPtr mWinRenderWindow;
    /* 30h */   IWindowPtr mWinBakingIndicator;
    /* 34h */   IWindowPtr mWinName;
    /* 38h */   IWindowPtr mWinAuthor;
    /* 3Ch */   IWindowPtr mWinDescription;
    /* 40h */   IWindowPtr mWinTags;
    /* 44h */   IWindowPtr mWinStatsContainer;
    /* 48h */   IWindowPtr mWinBakingForeground;
    /* 4Ch */   IWindowPtr mWinPublished;
    /* 50h */   int field_50;
    /* 54h */   int field_54;
    /* 58h */   int field_58;
    /* 5Ch */   int field_5C;
    /* 60h */   int mCommentsBrowserPtr;
    /* 64h */   int mExpansionPackBrowserPtr;
    /* 68h */   cSPEditorVerbTrayCollectionPtr mVerbIcons;
    /* 6Ch */   IWindowPtr mWinAssetVerbs;
    /* 70h */   int mAssetVerbsPtr;
    /* 74h */   IAssetDataPtr mAssetData;
    /* 78h */   int field_78;
    /* 7Ch */   int field_7C;
    /* 80h */   int field_80;
    /* 84h */   int mTraitSuperPowerRollover;
    /* 88h */   int field_88;
    /* 8Ch */   int field_8C;
    /* 90h */   int field_90;
    /* 94h */   bool mIsOnline;
    /* 98h */   int field_98;
    /* 9Ch */   int field_9C;
    /* A0h */   int field_A0;
    /* A4h */   int field_A4;
    /* A8h */   bool mIsLoaded;
    /* A9h */   bool field_A9;
    /* ABh */   bool field_AB;
    /* ACh */   bool field_AC;
    /* B0h */   int field_B0;
    /* B4h */   int field_B4;
    /* B8h */   bool field_B8;
    /* BCh */   App::MessageListenerData mAutoMsgHandler;
	};
    ASSERT_SIZE(cSPUILargeAssetView, 0xCC);

    namespace Addresses(cSPUILargeAssetViewSmh)
    {
        DeclareAddress(Dispose);
        DeclareAddress(func04h);
        DeclareAddress(AddRef);
        DeclareAddress(Release);
    }
}