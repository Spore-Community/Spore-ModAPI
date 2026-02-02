#pragma once

#include <Spore\Editors\cSPVerbTrayCollection.h>

#define cSPEditorVerbTrayCollectionPtr eastl::intrusive_ptr<Editors::cSPEditorVerbTrayCollection>

namespace Editors
{
    class cSPEditorVerbTrayCollection
        : public cSPVerbTrayCollection
    {
    public:
        static const uint32_t TYPE = 0x4aa3b42;
    };
    ASSERT_SIZE(cSPEditorVerbTrayCollection, 0x58);
}