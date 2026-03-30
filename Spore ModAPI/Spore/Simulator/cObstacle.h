#pragma once

#include <Spore\Simulator\cGameData.h>
#include <Spore\Graphics\Model.h>
#include <EASTL\bitset.h>

#define cObstaclePtr eastl::intrusive_ptr<Simulator::cObstacle>

namespace Simulator
{
	class cObstacle
		: public cGameData
	{
	public:
		static const uint32_t TYPE = 0x3ED590D;
		static const uint32_t NOUN_ID = 0x3ED8573;

		using Object::AddRef;
		using Object::Release;
		using Object::Cast;

		enum PlantType
		{
			kLargeSpecies = 0,
			kMediumSpecies = 1,
			kSmallSpecies = 2,
		};

	public:
		/* 34h */	eastl::bitset<3> mFlags;
		/* 38h */	Math::Vector3 mPosition;
		/* 44h */	float mObstacleBaseCollisionRadius;
		/* 48h */	float mObstacleCanopyCollisionRadius;
		/* 4Ch */	float mObstacleCollisionHeight;
		/* 50h */	int mSeqID;  // -1
		/* 54h */	int mDistributeEffect;
		/* 58h */	int mDistributeSamples;
		/* 5Ch */	int mSequenceNumIdx;  // -1
		/* 60h */	uint32_t mID;  // not initialized
		/* 64h */	uint32_t mGridID;  // -1
		/* 68h */	float mAlpha;  // 1.0
		/* 6Ch */	uint32_t mModelID;  // not initialized
		/* 70h */	ModelPtr mModel;
		/* 74h */	uint32_t mAlphaModelID;
		/* 78h */	ModelPtr mAlphaModel;
		/* 7Ch */	ResourceKey mSpeciesKey;
		/* 88h */	PlantType mPlantType;
	};
	ASSERT_SIZE(cObstacle, 0x8C);
}