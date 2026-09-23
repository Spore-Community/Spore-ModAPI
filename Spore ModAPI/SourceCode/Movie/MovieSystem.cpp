#ifndef MODAPI_DLL_EXPORT
#include <Spore\Movie\MovieSystem.h>

namespace Movie
{
	IMovieSystem::~IMovieSystem()
	{
	}

	auto_STATIC_METHOD_(MovieSystem, IMovieSystem*, Get);

	int MovieSystem::AddRef()
	{
		return 2;
	}
	int MovieSystem::Release()
	{
		return 1;
	}
	MovieSystem::~MovieSystem()
	{
	}

	auto_METHOD_VIRTUAL_VOID(MovieSystem, Graphics::ILayer, DrawLayer,
		Args(int flags, int layerIndex, App::cViewer** viewers, Graphics::RenderStatistics& statistics),
		Args(flags, layerIndex, viewers, statistics)
	);


	auto_METHOD_VIRTUAL_(MovieSystem, IMovieSystem, bool, Init);

	auto_METHOD_VIRTUAL_(MovieSystem, IMovieSystem, bool, Shutdown);

	auto_METHOD_VIRTUAL_VOID(MovieSystem, IMovieSystem, Update, Args(uint32_t deltaMS), Args(deltaMS));

	auto_METHOD_VIRTUAL(MovieSystem, IMovieSystem, bool, PlayMovie,
		Args(const ResourceKey& key, const cMoviePlayInfo& info),
		Args(key, info)
	);

	auto_METHOD_VIRTUAL_(MovieSystem, IMovieSystem, bool, MovieIsPlaying);

	auto_METHOD_VIRTUAL_VOID_(MovieSystem, IMovieSystem, PauseMovie);

	auto_METHOD_VIRTUAL_VOID_(MovieSystem, IMovieSystem, ContinueMovie);

	auto_METHOD_VIRTUAL_(MovieSystem, IMovieSystem, bool, StopMovie);

	auto_METHOD_VIRTUAL_(MovieSystem, IMovieSystem, bool, CheckEscape);

	auto_METHOD_VIRTUAL_(MovieSystem, IMovieSystem, bool, func28h);

	auto_METHOD_VIRTUAL(MovieSystem, IMovieSystem, bool, RecordMovie,
		Args(const wchar_t* name, const cMovieRecordInfo& info),
		Args(name, info)
	);

	auto_METHOD_VIRTUAL_(MovieSystem, IMovieSystem, bool, MovieIsRecording);

	auto_METHOD_VIRTUAL_(MovieSystem, IMovieSystem, wchar_t*, GetRecordingMovieName);

	auto_METHOD_VIRTUAL_(MovieSystem, IMovieSystem, bool, StopRecordingMovie);

	auto_METHOD_VIRTUAL_(MovieSystem, IMovieSystem, bool, func3Ch);

	auto_METHOD_VIRTUAL_VOID(MovieSystem, IMovieSystem, func40h, Args(bool arg_4), Args(arg_4));

	auto_METHOD_VIRTUAL_VOID(MovieSystem, IMovieSystem, func44h, Args(int arg_4), Args(arg_4));
}
#endif
