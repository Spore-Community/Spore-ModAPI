#pragma once

#include <EASTL\intrusive_ptr.h>
#include <EASTL\vector.h>
#include <Spore\UTFWin\IWindow.h>
#include <Spore\UTFWin\UILayout.h>
#include <Spore\UTFWin\IWinProc.h>
#include <Spore\App\PropertyList.h>
#include <Spore\Editors\VerbIconData.h>
#include <Spore\Editors\cSPEditorVerbIcon.h>
#include <Spore\Editors\cSPVerbIconRollover.h>
#include <Spore\Editors\VerbIconEnums.h>
#include <Spore\Editors\VerbIconStructs.h>

#define cSPEditorVerbIconTrayPtr eastl::intrusive_ptr<Editors::cSPEditorVerbIconTray>

namespace Editors
{
    class cSPEditorVerbIconTray
        : public UTFWin::IWinProc
        , public DefaultRefCounted
    {
    public:
        static const uint32_t TYPE = 0x4976064;

        virtual int AddRef() override;
        virtual int Release() override;
        virtual ~cSPEditorVerbIconTray();

    public:
    /* 0Ch */   eastl::vector<cSPEditorVerbIconPtr> mVerbIcons;
    /* 20h */   VerbIconDataPtr mOverrideData;
    /* 24h */   cSPEditorVerbIconPtr mOverrideVerbIcon;
    /* 28h */   UILayoutPtr mLayout;
    /* 2Ch */   IWindowPtr mWinRoot;
    /* 30h */   IWindowPtr mWinIconPanel;
    /* 34h */   IWindowPtr mWinLevel;
    /* 38h */   IWindowPtr mWinIcon;
    /* 3Ch */   IWindowPtr mWinText;
    /* 40h */   PropertyListPtr mVerbTrayProperties;
    /* 44h */   ResourceKey mIconKey;
    /* 50h */   uint32_t mSoundKey;
    /* 54h */   ResourceKey mLayoutKey;
    /* 60h */   ResourceKey mTrayKey;
    /* 6Ch */   uint32_t mIconID;
    /* 70h */   bool mShowIcons;
    /* 71h */   bool mAnimateIcons;
    /* 74h */   eResizeStyle mResizeStyle;
    /* 78h */   eLayoutJustification mLayoutJustification;
    /* 7Ch */   ResourceKey mRolloverLayout;
    /* 88h */   float mLevelTotal;
    /* 8Ch */   float mMaxLevel;
    /* 90h */   bool mShowLevel;
    /* 91h */   bool mRolloverShowLevel;
    /* 92h */   bool mShowPercent;
    /* 93h */   bool mShowPercentInRollover;
    /* 94h */   int field_94;
    /* 98h */   bool mShowVerbIconWhenCollapsed;
    /* 9Ch */   float mDisplayedLevel;
    /* A0h */   float mOriginalWidth;
    /* A4h */   float mOriginalHeight;
    /* A8h */   Math::Rectangle mMaxArea;
    /* B8h */   Math::Rectangle mGutters;
    /* C8h */   int mAbilityCount;
    /* CCh */   float mVerbIconAspectRatio;
    /* D0h */   float mIconHeight;
    /* D4h */   float mIconWidth;
    /* D8h */   bool mDoIconLevelsExist;
    /* D9h */   bool mOverrideAggregate;
    /* DAh */   bool mIsEnabled;
    /* DBh */   bool mIsHealthBar;
    /* DCh */   bool mIgnoreKeyPress;
    /* E0h */   uint32_t mAlertID;
    /* E4h */   bool field_E4;
    /* E5h */   bool mSetHaveChargeDials;
    /* E6h */   bool mSetForceEnabled;
    /* E7h */   bool mIconsHaveChargeDials;
    /* E8h */   bool mIconsForceEnabled;
    /* ECh */   uint32_t mOverrideType;
    /* F0h */   cVerbIconInterpolationValue mBaseStat;
    /* 10Ch */  bool mShowRollover;
    /* 110h */  cSPVerbIconRolloverPtr mRollover;
    /* 114h */  int mAbilityArray;
    /* 118h */  uint32_t mRepresentativeAnimation;
    /* 11Ch */  int mCollectionID;
    };
    ASSERT_SIZE(cSPEditorVerbIconTray, 0x120);
}