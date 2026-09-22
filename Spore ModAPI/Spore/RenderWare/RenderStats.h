#pragma once

#include <Spore\Internal.h>

namespace RenderWare
{
	struct RenderStats
	{
		float mMsPerFrame;
		float mFPS;
		float mSmoothedMsPerFrame;
		float mSmoothedFPS;
		float mRenderTime;
		int mLayers;
		int mJobs;
		int mJobsQueued;
		int mVertices;
		int mIndices;
		int mPrimitives;
	};
	ASSERT_SIZE(RenderStats, 0x2c);
}
