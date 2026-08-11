#ifndef MODAPI_DLL_EXPORT
#include <Spore\UI\ScrollFrameVertical.h>

namespace UI
{
	auto_STATIC_METHOD(ScrollFrameVertical, UTFWin::IWindow*, Create,
		Args(const char16_t* pLayoutName, IWindowPtr& dstContent, bool arg_8),
		Args(pLayoutName, dstContent, arg_8));

	auto_STATIC_METHOD(ScrollFrameVertical, bool, Update,
		Args(UTFWin::IWindow* pScrollFrameVertical, bool arg_4),
		Args(pScrollFrameVertical, arg_4));
}
#endif
