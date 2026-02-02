#pragma once

#include <Spore\App\Property.h>
#include <Spore\UTFWin\IWinProc.h>
#include <Spore\UTFWin\UILayout.h>
#include <EASTL\vector_map.h>
#include <Spore\Clock.h>

#define cSPUIPropertyLayoutPtr eastl::intrusive_ptr<UI::cSPUIPropertyLayout>

namespace UI
{
    struct Point2DT {
        float mX;
        float mY;
    };

    class cSPUIPropertyLayout
        : public UTFWin::IWinProc
        , public DefaultRefCounted
    {
    public:

        virtual int AddRef() override;
        virtual int Release() override;
        virtual ~cSPUIPropertyLayout();

        bool SetProperty(uint32_t windowID, App::Property* setProperty, uint32_t unk = 1, int* unk2 = nullptr);

    public:
        UTFWin::UILayout mLayout;
        uint32_t mResInstanceID;
        uint32_t mResGroupID;
        eastl::vector_map<unsigned int, App::Property> mProperties;
        bool mbInitialized;
        uint32_t mRootWinID;
        float mAutoUpdateIntervalSeconds;
        Clock mStopwatch;
        float mTimeSinceLastUpdate;
        Point2DT mOffset;
        bool mVisibleFlag;
    };
    ASSERT_SIZE(cSPUIPropertyLayout, 0x78);

    namespace Addresses(cSPUIPropertyLayout)
    {
        DeclareAddress(SetProperty);
    }
}