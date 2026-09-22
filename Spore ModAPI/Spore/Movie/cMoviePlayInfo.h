#pragma once

#include <Spore\Internal.h>

namespace Movie
{
	enum MovieDrawType
	{
		kMovieDrawStandard,
		kMovieDrawBW,
		kMovieDrawTheshold2,
		kMovieDrawTheshold4
	};

	struct cMoviePlayInfo
	{
		MovieDrawType mDrawType;
		float mScale;
		float mFadeInTime;
		float mFadeOutTime;
		float mEscapableTime;
		bool mLetterboxOn;

		cMoviePlayInfo(
			MovieDrawType drawType = kMovieDrawStandard,
			float scale = 1.0f,
			float fadeInTime = 0.0f,
			float fadeOutTime = 0.0f,
			float escapableTime = 0.0f,
			bool letterboxOn = true
		)
			: mDrawType(drawType)
			, mScale(scale)
			, mFadeInTime(fadeInTime)
			, mFadeOutTime(fadeOutTime)
			, mEscapableTime(escapableTime)
			, mLetterboxOn(letterboxOn)
		{
		}
	};
	ASSERT_SIZE(cMoviePlayInfo, 0x18);
}
