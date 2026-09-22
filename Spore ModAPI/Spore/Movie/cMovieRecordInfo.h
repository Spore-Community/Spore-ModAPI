#pragma once

#include <Spore\Internal.h>

namespace Movie
{
    struct cMovieRecordInfo
    {
        uint32_t mWidth;
        uint32_t mHeight;
        float mFPS;
        float mTime;
        float mQuality;
        bool mAudio;
        bool mExcludeUI;

		cMovieRecordInfo(
			float fps = 15.0f,
			float time = 0.0f,
			uint32_t width = 320,
			uint32_t height = 240,
			float quality = 0.8,
			bool audio = true,
			bool excludeUI = false
		)
			: mFPS(fps)
			, mTime(time)
			, mWidth(width)
			, mHeight(height)
			, mQuality(quality)
			, mAudio(audio)
			, mExcludeUI(excludeUI)
		{
		}
    };
    ASSERT_SIZE(cMovieRecordInfo, 0x18);
}
