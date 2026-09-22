#pragma once

#include <Spore\Internal.h>
#include <Spore\RenderWare\ILayer.h>
#include <Spore\Movie\cMoviePlayInfo.h>
#include <Spore\Movie\cMovieRecordInfo.h>

namespace Movie
{
	class IMovieSystem
	{
	public:
		/* 00h */	virtual ~IMovieSystem();

		/* 04h */	virtual bool Init() = 0;
		/* 08h */	virtual bool Shutdown() = 0;
		/* 0Ch */	virtual void Update(uint32_t deltaMS) = 0;
		/* 10h */	virtual bool PlayMovie(const ResourceKey& key, const cMoviePlayInfo& info) = 0;
		/* 14h */	virtual bool MovieIsPlaying() = 0;
		/* 18h */	virtual void PauseMovie() = 0;
		/* 1Ch */	virtual void ContinueMovie() = 0;
		/* 20h */	virtual bool StopMovie() = 0;
		/* 24h */	virtual bool CheckEscape() = 0;
		/* 28h */	virtual bool func28h() = 0;
		/* 2Ch */	virtual bool RecordMovie(const wchar_t* name, const cMovieRecordInfo& info) = 0;
		/* 30h */	virtual bool MovieIsRecording() = 0;
		/* 34h */	virtual wchar_t* GetRecordingMovieName() = 0;
		/* 38h */	virtual bool StopRecordingMovie() = 0;
		/* 3Ch */	virtual bool func3Ch() = 0;
		/* 40h */	virtual void func40h(bool) = 0;
		/* 44h */	virtual void func44h(int) = 0;
	};
	ASSERT_SIZE(IMovieSystem, 0x4);

	class MovieSystem
		: public RenderWare::ILayer
		, public IMovieSystem
	{
	public:
		static IMovieSystem* Get();

		~MovieSystem();

		virtual int AddRef() override;
		virtual int Release() override;

		virtual void DrawLayer(uint32_t flags, uint32_t layerNumber, const void* const* viewer, RenderWare::RenderStats* stats) override;

		virtual bool Init() override;
		virtual bool Shutdown() override;
		virtual void Update(uint32_t deltaMS) override;
		virtual bool PlayMovie(const ResourceKey& key, const cMoviePlayInfo& info) override;
		virtual bool MovieIsPlaying() override;
		virtual void PauseMovie() override;
		virtual void ContinueMovie() override;
		virtual bool StopMovie() override;
		virtual bool CheckEscape() override;
		virtual bool func28h() override;
		virtual bool RecordMovie(const wchar_t* name, const cMovieRecordInfo& info) override;
		virtual bool MovieIsRecording() override;
		virtual wchar_t* GetRecordingMovieName() override;
		virtual bool StopRecordingMovie() override;
		virtual bool func3Ch() override;
		virtual void func40h(bool) override;
		virtual void func44h(int) override;
	};

	namespace Addresses(MovieSystem)
	{
		DeclareAddress(Get);
		DeclareAddress(DrawLayer);
		DeclareAddress(Init);
		DeclareAddress(Shutdown);
		DeclareAddress(Update);
		DeclareAddress(PlayMovie);
		DeclareAddress(MovieIsPlaying);
		DeclareAddress(PauseMovie);
		DeclareAddress(ContinueMovie);
		DeclareAddress(StopMovie);
		DeclareAddress(CheckEscape);
		DeclareAddress(func28h);
		DeclareAddress(RecordMovie);
		DeclareAddress(MovieIsRecording);
		DeclareAddress(GetRecordingMovieName);
		DeclareAddress(StopRecordingMovie);
		DeclareAddress(func3Ch);
		DeclareAddress(func40h);
		DeclareAddress(func44h);
	}
}
