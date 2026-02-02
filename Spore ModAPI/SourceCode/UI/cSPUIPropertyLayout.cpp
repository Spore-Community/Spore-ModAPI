#ifndef MODAPI_DLL_EXPORT
#include <Spore\UI\cSPUIPropertyLayout.h>

namespace UI
{
	auto_METHOD(cSPUIPropertyLayout, bool, SetProperty,
		Args(uint32_t windowID, App::Property* setProperty, uint32_t unk, int* unk2),
		Args(windowID, setProperty, unk, unk2));
}
#endif
