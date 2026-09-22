#ifndef MODAPI_DLL_EXPORT
#include <Spore\Movie\cMovieLetterbox.h>

namespace Movie
{
	auto_METHOD_VOID_(cMovieLetterbox, Initialize);

	void* cMovieLetterbox::Cast(uint32_t type) const
	{
		CLASS_CAST(cMovieLetterbox);
		CLASS_CAST(UTFWin::IWinProc);
		return nullptr;
	}

	bool cMovieLetterbox::HandleUIMessage(UTFWin::IWindow* pWindow, const UTFWin::Message& message)
	{
		return false;
	}
}
#endif
