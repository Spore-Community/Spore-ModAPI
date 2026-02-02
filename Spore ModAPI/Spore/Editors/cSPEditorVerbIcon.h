#pragma once

#include <Spore\UTFWin\IWinProc.h>
#include <EASTL\vector.h>
#include <Spore\UTFWin\IWindow.h>
#include <Spore\UTFWin\UILayout.h>
#include <Spore\UTFWin\Image.h>
#include <Spore\Editors\cSPVerbIconRollover.h>
#include <Spore\Editors\VerbIconData.h>
#include <Spore\Editors\VerbIconEnums.h>
#include <Spore\Editors\VerbIconStructs.h>

#define cSPEditorVerbIconPtr eastl::intrusive_ptr<Editors::cSPEditorVerbIcon>

namespace Editors
{
    class cSPEditorVerbIcon
        : public UTFWin::IWinProc
        , public DefaultRefCounted
    {
    public:
        static const uint32_t TYPE = 0x497595a;

        virtual int AddRef() override;
        virtual int Release() override;
        virtual ~cSPEditorVerbIcon();

    public:
    /* 0Ch */   UILayoutPtr mLayout;
    /* 10h */   IWindowPtr mWinRoot;
    /* 14h */   IWindowPtr mWinIcon;
    /* 18h */   IWindowPtr mWinLevel;
    /* 1Ch */   IWindowPtr mWinHighlight;
    /* 20h */   IWindowPtr mWinShortcutText;
    /* 24h */   IWindowPtr mWinFlashingGlow;
    /* 28h */   IWindowPtr field_28;
    /* 2Ch */   IWindowPtr field_2C;
    /* 30h */   ImagePtr mChargeImage;
    /* 34h */   int _padding_[0xB];
    /* 60h */   uint32_t mRolloverLayout;
    /* 64h */   eVerbIconState mState;
    /* 68h */   bool mAnimate;
    /* 69h */   bool mIsVisible;
    /* 6Ah */   bool mShowRollover;
    /* 6Bh */   bool mShowRolloverWasSet;
    /* 6Ch */   bool field_6C;
    /* 6Dh */   bool mShowLevel;
    /* 6Eh */   bool mShowingLevel;
    /* 6Fh */   bool mForceEnable;
    /* 70h */   bool mIsEnabled;
    /* 71h */   bool mHasChargeDial;
    /* 72h */   bool mIgnoreKeyPress;
    /* 73h */   bool mIgnoreKeyOverride;
    /* 74h */   float field_74;
    /* 78h */   float field_78;
    /* 7Ch */   float field_7C;
    /* 80h */   float field_80;
    /* 84h */   float field_84;
    /* 88h */   float field_88;
    /* 8Ch */   float field_8C;
    /* 90h */   float field_90;
    /* 94h */   float field_94;
    /* 98h */   cVerbIconLinearInterpolationValue mCharge;
    /* ACh */   cVerbIconInterpolationValue mScaleX;
    /* C8h */   cVerbIconInterpolationValue mScaleY;
    /* E4h */   cVerbIconLinearInterpolationValue mLevel;
    /* F8h */   cVerbIconInterpolationValue mUpgradeScale;
    /* 114h */  cVerbIconMiddleInterpolationValue mUpgradeHighlightFade;
    /* 134h */  cVerbIconMiddleInterpolationValue mIconAlpha;
    /* 154h */  cVerbIconOscillatingAlpha mFlashAlpha;
    /* 170h */  VerbIconDataPtr mIconData;
    /* 174h */  cSPVerbIconRolloverPtr mRollover;
    /* 178h */  uint32_t mBaseTextColor;
    /* 17Ch */  int mCollectionID;  //ptr
    /* 180h */  float mAspectRatio;
    };
    ASSERT_SIZE(cSPEditorVerbIcon, 0x184);
}