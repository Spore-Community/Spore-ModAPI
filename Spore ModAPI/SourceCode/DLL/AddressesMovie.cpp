#ifdef MODAPI_DLL_EXPORT
#include "stdafx.h"
#include <Spore\Movie\cMovieLetterbox.h>
#include <Spore\Movie\MovieSystem.h>

namespace Movie
{
	namespace Addresses(cMovieLetterbox)
	{
		DefineAddress(Initialize, SelectAddress(0xFAB930, 0xFD7730));
	}

	namespace Addresses(MovieSystem)
	{
		DefineAddress(Get, SelectAddress(0x672070, 0x67CAD0));

		DefineAddress(DrawLayer, SelectAddress(0xFAB430, 0xFD7240));

		DefineAddress(Init, SelectAddress(0xFAD2D0, 0xFD90D0));
		DefineAddress(Shutdown, SelectAddress(0xFAB9E0, 0xFD77E0));
		DefineAddress(Update, SelectAddress(0xFABF60, 0xFD7D60));
		DefineAddress(PlayMovie, SelectAddress(0xFAC9A0, 0xFD87A0));
		DefineAddress(MovieIsPlaying, SelectAddress(0xFAB740, 0xFD7550));
		DefineAddress(PauseMovie, SelectAddress(0xFAB750, 0xFD7560));
		DefineAddress(ContinueMovie, SelectAddress(0xFAB760, 0xFD7570));
		DefineAddress(StopMovie, SelectAddress(0xFABBC0, 0xFD79C0));
		DefineAddress(CheckEscape, SelectAddress(0xFAB770, 0xFD7580));
		DefineAddress(func28h, SelectAddress(0xFAB7E0, 0xFD75F0));
		DefineAddress(RecordMovie, SelectAddress(0xFAC370, 0xFD8170));
		DefineAddress(MovieIsRecording, SelectAddress(0xFAB830, 0xA1AEE0));
		DefineAddress(GetRecordingMovieName, SelectAddress(0xFABC70, 0xFD7A70));
		DefineAddress(StopRecordingMovie, SelectAddress(0xFAC160, 0xFD7F60));
		DefineAddress(func3Ch, SelectAddress(0x5D3460, 0x5DC490));
		DefineAddress(func40h, SelectAddress(0xFAB820, 0xFD7630));
		DefineAddress(func44h, SelectAddress(0xFAC8D0, 0xFD86D0));
	}
}
#endif
