#pragma once

#include <Spore\Graphics\IRenderTargetManager.h>
#include <Spore\Graphics\ILayer.h>
#include <Spore\Graphics\IModelWorld.h>
#include <Spore\Graphics\Texture.h>
#include <Spore\App\IMessageListener.h>
#include <Spore\App\PropertyList.h>
#include <Spore\Object.h>
#include <EASTL\string.h>

#define ThumbnailManager (*Graphics::IThumbnailManager::Get())
#define PlanetThumbnailRequestPtr eastl::intrusive_ptr<Graphics::PlanetThumbnailRequest>

namespace Graphics
{
	class PlanetThumbnailRequest
		: public DefaultRefCounted  // actually it doesn't have the last method
	{
	public:
		PlanetThumbnailRequest();

		/* 08h */	float mRadius;  // not initialized
		/* 0Ch */	int field_C;  // not initialized
		/* 10h */	ILayerPtr mpRenderable;
		/* 14h */	TexturePtr mpTexture;
		/* 18h */	eastl::string mName;
		/// ID of message sent when the image finishes rendering
		/* 28h */	uint32_t mMessageID;
	};
	ASSERT_SIZE(PlanetThumbnailRequest, 0x2C);

	class cPaletteThumbnailInfo
		: public DefaultRefCounted
	{
	public:
		/* 08h */	uint32_t mRes;
		/* 0Ch */	uint32_t mCameraId;
		/* 10h */	uint32_t mMsgId;
		/* 14h */	uint32_t mGroup;
		/* 18h */	uint32_t mInstance;
		/* 1Ch */	Math::Vector3 mCamCenter;
		/* 28h */	float mEditorScale;
		/* 2Ch */	eastl::vector<Math::BoundingBox> mBBoxes;//eastl::vector<eastl::intrusive_ptr<Math::BoundingBox>> mBBoxes;
		/* 40h */	uint32_t mEffectType;
		/* 44h */	uint32_t mFramingType;
		/* 48h */	float mZoomValue;
	};
	ASSERT_SIZE(cPaletteThumbnailInfo, 0x4C);

	class cEditorsThumbnailInfo
		: public DefaultRefCounted
	{
	public:
		cEditorsThumbnailInfo();

		/* 08h */	uint32_t mRes;
		/* 0Ch */	uint32_t mCameraId;
		/* 10h */	uint32_t mMsgId;
		/* 14h */	TexturePtr mThumbnailTex;
		/* 18h */	Math::Vector3 mCamCenter;
		/* 24h */	float mEditorScale;
		/* 28h */	eastl::vector<Math::BoundingBox> mBBoxes;//eastl::vector<eastl::intrusive_ptr<Math::BoundingBox>> mBBoxes;
		/* 3Ch */	uint32_t mEffectType;
	};
	ASSERT_SIZE(cEditorsThumbnailInfo, 0x40);

	class cCSAThumbnailInfo
		: public Graphics::ILayer
		, public RefCountTemplate
	{
	public:
		/* 0Ch */	bool mInitialized;
		/* 10h */	IModelWorldPtr mModelWorld;
		/* 14h */	IModelWorldPtr mBackgroundModelWorld;
		/* 18h */	TexturePtr mThumbnailTex;
		/* 18h */	App::cViewer* mViewer;
		/* 1Ch */	App::cViewer* mFilterViewer;
		/* 20h */	int mInfo;	//AutoRefCount<SP::cThumbnailManager::cCSAJobInfo>
	};
	ASSERT_SIZE(cCSAThumbnailInfo, 0x28);

	class cGameThumbnailInfo
		: public DefaultRefCounted
	{
	public:
		/* 08h */	uint32_t mRes;
		/* 0Ch */	uint32_t mGroup;
		/* 10h */	uint32_t mInstance;
		/* 14h */	uint32_t mMsgId;
		/* 18h */	uint32_t mDrawSet;
	};
	ASSERT_SIZE(cGameThumbnailInfo, 0x1C);

	class unknownThumbnailInfo
		: public DefaultRefCounted
	{
	public:
		/* 08h */	uint32_t field_08;
		/* 0Ch */	uint32_t mRes;
		/* 10h */	uint32_t field_10;
		/* 14h */	uint32_t field_14;
		/* 18h */	uint32_t field_18;
	};
	ASSERT_SIZE(unknownThumbnailInfo, 0x1C);

	class IThumbnailManager
	{
	public:
	/* 00h */	virtual int AddRef();
	/* 04h */	virtual int Release();
	/* 08h */	virtual void* Dispose();
	/* 0Ch */	virtual bool Init();
	/* 10h */	virtual bool Shutdown();
	/* 14h */	virtual void FrameBoundingBoxPalette(BoundingBox* modelBBox, App::cViewer* model, uint32_t unk, float unk2);
	/* 18h */	virtual void GetThumbRectID(RenderTargetID* dst);
	/* 1Ch */	virtual void CapturePaletteThumbnail(IModelWorld* paletteModel, cPaletteThumbnailInfo* paltteInfo);
	/* 20h */	virtual void CaptureEditorsThumbnail(IModelWorld* creationModel, cEditorsThumbnailInfo* editorsInfo);
	/* 24h */	virtual void CaptureCSAPhotos(IModelWorld* param_1, IModelWorld* param_2, cCSAThumbnailInfo* CSAInfo);
	/* 28h */	virtual void CaptureGameThumbnail(IModelWorld* gameModelWorld, cGameThumbnailInfo* gameInfo);
	/* 2Ch */	virtual void func2ch(unknownThumbnailInfo* unkInfo);
	/* 30h */	virtual void func30h(IModelWorld* modelWorld, App::cViewer*, uint32_t msg, int size, uint32_t);
	/* 34h */	virtual void RenderPlanetThumbnail(PlanetThumbnailRequest* request, int thumbnailSize);
	/* 38h */	virtual void CaptureBESplatter(uint32_t, RenderTargetID*, eastl::vector<cMeshDataPtr>*, eastl::vector<cMaterialInfoPtr>*, eastl::vector_map<int, int>*, eastl::vector<eastl::vector_map<int, cMaterialInfoPtr>>*, eastl::vector_map<int, int>*, uint32_t, bool,int, int, RenderTargetID*, RenderTargetID*);
	/* 3Ch */	virtual bool CaptureAO(RenderTargetID*, IModelWorld*, eastl::vector<cMeshDataPtr>*, uint32_t, uint32_t lightingID, bool);
	/* 40h */	virtual bool CaptureAOCE(uint32_t modelID, uint32_t modelGroupID, BoundingBox* BBox, uint32_t lightingGroupID, uint32_t lightingID, App::PropertyList* lightingProp);
	/* 44h */	virtual void func44h(uint32_t msg);
	/* 48h */	virtual void GenerateTimelineImages(uint32_t, uint32_t, uint32_t, uint32_t);
	/* 4Ch */	virtual void FrameBoundingBoxThumbnail(BoundingBox* modelBBox, App::cViewer* model, uint32_t unk, float unk2);	//i'm not sure
	/* 50h */	virtual void FrameBBoxes(eastl::vector<eastl::intrusive_ptr<Math::BoundingBox>>* BBoxes, App::cViewer*, uint32_t cameraID, Vector3* param_4, float, float);
	/* 54h */	virtual void DownsampleGIF(RenderTargetID*, RenderTargetID*, int, int);
	/* 58h */	virtual void DownSampleRT(RenderTargetID*, RenderTargetID*, int, int);
	/* 5Ch */	virtual void func5Ch(RenderTargetID*, RenderTargetID*, RenderTargetID*, int, bool);
	/* 60h */	virtual void TerrainBlurFilterDraw(RenderTargetID* refractionRTT, RenderTargetID* blur1RTT, RenderTargetID* blur2RTT, RenderStatistics* stats);
	/* 64h */	virtual void GatherAOPasses(uint32_t, uint32_t, uint32_t, App::cViewer**, RenderStatistics*);

		static IThumbnailManager* Get();
	};

	namespace Addresses(IThumbnailManager) {
		DeclareAddress(Get);

		DeclareAddress(AddRef);
		DeclareAddress(Release);
		DeclareAddress(Dispose);
		DeclareAddress(Init);
		DeclareAddress(Shutdown);
		DeclareAddress(FrameBoundingBoxPalette);
		DeclareAddress(GetThumbRectID);
		DeclareAddress(CapturePaletteThumbnail);
		DeclareAddress(CaptureEditorsThumbnail);
		DeclareAddress(CaptureCSAPhotos);
		DeclareAddress(CaptureGameThumbnail);
		DeclareAddress(func2ch);
		DeclareAddress(func30h);
		DeclareAddress(RenderPlanetThumbnail);
		DeclareAddress(CaptureBESplatter);
		DeclareAddress(CaptureAO);
		DeclareAddress(CaptureAOCE);
		DeclareAddress(func44h);
		DeclareAddress(GenerateTimelineImages);
		DeclareAddress(FrameBoundingBoxThumbnail);
		DeclareAddress(FrameBBoxes);
		DeclareAddress(DownsampleGIF);
		DeclareAddress(DownSampleRT);
		DeclareAddress(func5Ch);
		DeclareAddress(TerrainBlurFilterDraw);
		DeclareAddress(GatherAOPasses);
	}
}