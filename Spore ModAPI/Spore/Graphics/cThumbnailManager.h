#pragma once

#include <Spore\Graphics\IRenderTargetManager.h>
#include <Spore\Graphics\ILayer.h>
#include <Spore\Graphics\IModelWorld.h>
#include <Spore\Graphics\Texture.h>
#include <Spore\Graphics\IThumbnailManager.h>
#include <Spore\App\IMessageListener.h>
#include <Spore\App\PropertyList.h>
#include <Spore\Object.h>
#include <EASTL\string.h>

namespace Graphics
{
	class cThumbnailManager
		: public IThumbnailManager
		, public App::IMessageListener
		, public RefCountTemplate
	{
	public:
		/* 10h */	RenderWare::Raster* mThumbRaster;
		/* 14h */	RenderTargetID mThumbRectID;
		/* 1Ch */	RenderTargetID mBlurThumbRectID1;
		/* 24h */	RenderTargetID mBlurThumbRectID2;
		/* 2Ch */	RenderTargetID mTempThumbnailBuffer;
		/* 34h */	RenderTargetID mCSALargeRectID;
		/* 3Ch */	RenderTargetID mCSASmallRectID;
		/* 44h */	RenderTargetID mCSAAntiAliasRectID;
		/* 4Ch */	RenderTargetID mTimelineRectID[3];
		/* 64h */	TexturePtr mTimelineCellBg;
		/* 68h */	TexturePtr mTimelineCreatureBg;
		/* 6Ch */	TexturePtr mTimelineTribeBg;
		/* 70h */	TexturePtr mTimelineCivBg;
		/* 74h */	TexturePtr mTimelineSpaceBg;
		/* 78h */	App::cViewer* mSplatterViewer;
		/* 7Ch */	App::cViewer* mBakeInfoSplatterViewer;
		/* 80h */	App::cViewer* mNMapSpecSplatterViewer;
		/* 84h */	App::cViewer* mDilateViewer;
		/* 88h */	App::cViewer* mAmbOccShadowViewers[1024];
		/* 1088h */	App::cViewer* mAmbOccSplatterViewer;
		/* 108Ch */	App::cViewer* mAmbOccGatherViewer;
		/* 1090h */	RenderWare::Raster* mLargeBufferTexture;
		/* 1094h */	RenderTargetID mLargeBufferTextureRectID;
		/* 109Ch */	RenderWare::Raster* mWatermarkRaster;
		/* 10A0h */	RenderWare::Raster* mScreenshotRaster;
		/* 10A4h */	RenderTargetID mWatermarkRectID;
		/* 10ACh */	RenderTargetID mScreenshotRectID;
		/* 10B4h */	Graphics::IRenderTargetManager* mRTTMgr;	//or cRenderTargetManager?
		/* 10B8h */	uint32_t mTempCamCtrlr;
		/* 10BCh */	bool mMultiplyDiffuseWithAO;
		/* 10BDh */	bool mBakeLscm;
		/* 10C0h */	IVisualEffectPtr mShadowLightEffect;
		/* 10C4h */	IModelWorldPtr mAOModelWorld;
		/* 10C8h */	int mSkinModel;	//AutoRefCount<SP::cMWModel>
		/* 10CCh */	int mSplatInProgress;
		/* 10D0h */	bool mCurrentlyCapturingAO;
		/* 10D1h */	bool mTerrainFilterInitialized;
		/* 10D4h */	int mTerrainDownSampleFilter;	//AutoRefCount<SP::cThumbnailManager::cJobPostFilter>
		/* 10D8h */	int mTerrainBlurFilter1;	//AutoRefCount<SP::cThumbnailManager::cJobPostFilter>
		/* 10DCh */	int mTerrainBlurFilter2;	//AutoRefCount<SP::cThumbnailManager::cJobPostFilter>
		/* 10E0h */	App::cViewer* mTerrainBlurFilterViewer;
		/* 10E4h */	RenderTargetID mAOGatherRectID;
		/* 10ECh */	int mAOPostProcessLayer;	//AutoRefCount<SP::cThumbnailManager::cFilterChainJob>
		/* 10F0h */	int mAmbOccRenderJob[1024];	//AutoRefCount<SP::cThumbnailManager::cAmbOccJob>[1024]
		/* 20F0h */	int mDiffuseSplatterJob;	//AutoRefCount<SP::cThumbnailManager::cBESplatterJob>
		/* 20F4h */	int mBakeInfoSplatterJob;	//AutoRefCount<SP::cThumbnailManager::cBESplatterJob>
		/* 20F8h */	int mNMapSpecSplatterJob;	//AutoRefCount<SP::cThumbnailManager::cBESplatterJob>
		/* 20FCh */	int mAmbOccTextureCount;
		/* 2100h */	int mTimelineJobs[3];
		/* 2110h */	Clock mAOTimer;
	};
	ASSERT_SIZE(cThumbnailManager, 0x2128);
}