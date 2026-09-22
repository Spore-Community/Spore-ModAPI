#pragma once

#include <Spore\App\IMessageListener.h>
#include <Spore\UTFWin\IWinProc.h>
#include <Spore\UTFWin\UILayout.h>

#define cMovieLetterboxPtr eastl::intrusive_ptr<Movie::cMovieLetterbox>

namespace Movie
{
	class cMovieLetterbox
		: public UTFWin::DefaultWinProc<>
	{
	public:
		static const uint32_t TYPE = 0x450062A;

		enum ControlIDs
		{
			kWinRoot = -1
		};

		void Initialize();
		inline void SetVisible(bool visible)
		{
			mLayout->SetVisible(visible);
		}

		virtual void* Cast(uint32_t type) const override;

		virtual bool HandleUIMessage(UTFWin::IWindow * pWindow, const UTFWin::Message& message) override;

	public:
		/* 0Ch */	UILayoutPtr mLayout;
	};
	ASSERT_SIZE(cMovieLetterbox, 0x10);

	namespace Addresses(cMovieLetterbox)
	{
		DeclareAddress(Initialize);
	}
}
