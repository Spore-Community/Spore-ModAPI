#pragma once

#include <Spore\UI\cSPUIPropertyLayout.h>

#define cSPVerbIconRolloverPtr eastl::intrusive_ptr<Editors::cSPVerbIconRollover>

namespace Editors
{
    class cSPVerbIconRollover
        : public UI::cSPUIPropertyLayout
    {
    public:
        virtual int AddRef() override;
        virtual int Release() override;
        virtual ~cSPVerbIconRollover();
    };
    ASSERT_SIZE(cSPVerbIconRollover, 0x78);
}