#pragma once

#include <Spore\Internal.h>

namespace Graphics
{
	struct RenderStatistics
	{
		// related with total render time
		/* 00h */	float msPerFrame;
		/* 04h */	float fps;
		/* 08h */	float msPerFrameSmoothed;
		/* 0Ch */	float fpsSmoothed;
		/* 10h */	float renderTime;
		/* 14h */	int numLayersRendered;
		/* 18h */	int numJobs;
		/* 1Ch */	int numJobsQueued;
		/* 20h */	int numVerticesRendered;
		/* 24h */	int numIndicesRendered;
		/* 28h */	int numDrawCalls;
	};
	ASSERT_SIZE(RenderStatistics, 0x2C);
}