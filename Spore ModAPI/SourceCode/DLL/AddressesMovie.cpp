#ifdef MODAPI_DLL_EXPORT
#include "stdafx.h"
#include <Spore\Movie\cMovieLetterbox.h>
#include <Spore\Movie\MovieSystem.h>

namespace Movie
{
	namespace Addresses(cMovieLetterbox)
	{
		DefineAddress(Initialize, SelectAddress(0xFD7E80, 0xFD7730));
	}

	namespace Addresses(MovieSystem)
	{
		DefineAddress(Get, SelectAddress(0x67CC60, 0x67CAD0));

		DefineAddress(DrawLayer, SelectAddress(0xFD7970, 0xFD7240));

		DefineAddress(Init, SelectAddress(0xFD97F0, 0xFD90D0));
		DefineAddress(Shutdown, SelectAddress(0xFD7F30, 0xFD77E0));
		DefineAddress(Update, SelectAddress(0xFD84B0, 0xFD7D60));
		DefineAddress(PlayMovie, SelectAddress(0xFD8EF0, 0xFD87A0));
		DefineAddress(MovieIsPlaying, SelectAddress(0xFD7C80, 0xFD7550));
		DefineAddress(PauseMovie, SelectAddress(0xFD7C90, 0xFD7560));
		DefineAddress(ContinueMovie, SelectAddress(0xFD7CA0, 0xFD7570));
		DefineAddress(StopMovie, SelectAddress(0xFD8110, 0xFD79C0));
		DefineAddress(CheckEscape, SelectAddress(0xFD7CB0, 0xFD7580));
		DefineAddress(func28h, SelectAddress(0xFD7D20, 0xFD75F0));
		DefineAddress(RecordMovie, SelectAddress(0xFD88C0, 0xFD8170));
		DefineAddress(MovieIsRecording, SelectAddress(0xFD7D80, 0xA1AEE0));
		DefineAddress(GetRecordingMovieName, SelectAddress(0xFD81C0, 0xFD7A70));
		DefineAddress(StopRecordingMovie, SelectAddress(0xFD86B0, 0xFD7F60));
		DefineAddress(func3Ch, SelectAddress(0xFD7D60, 0x5DC490));
		DefineAddress(func40h, SelectAddress(0xFD7D70, 0xFD7630));
		DefineAddress(func44h, SelectAddress(0xFD8E20, 0xFD86D0));
	}
}
#endif
