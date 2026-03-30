#pragma once

#include <Spore\Sporepedia\OTDBParameters.h>
#include <Spore\App\IMessageListener.h>
#include <Spore\Resource\IResourceFactory.h>
#include <Spore\App\cJob.h>
#include <EASTL\vector_map.h>
#include <EASTL\vector_set.h>
#include <EASTL\map.h>

#define ObjectTemplateDB (*Sporepedia::OTDB::cObjectTemplateDB::Get())
#define cISummarizerPtr eastl::intrusive_ptr<Sporepedia::OTDB::ISummarizer>

namespace Sporepedia
{
	namespace OTDB
	{

		struct cID
		{
			uint32_t mnTraitClass;
			uint32_t mnTraitType;
		};
		struct cFeatureVector
		{
			//vector_map<SP::Traits::cID,float,eastl::less<SP::Traits::cID>,eastl::allocator,eastl::vector<eastl::pair<SP::Traits::cID,float>,eastl::allocator>_>
			eastl::vector_map<cID, float> mTraitMap;
			float mfLen;
		};

		struct MutliModeDistance
		{
			/* 00h */	cFeatureVector mTraitCounts;
			/* 1Ch */	cFeatureVector mInverseDocumentFrequency;

			//vector_map<unsigned_int,float,eastl::less<unsigned_int>,eastl::allocator,eastl::vector<eastl::pair<unsigned_int,float>,eastl::allocator>_>
			/* 38h */	eastl::vector_map<unsigned int, float> mTestTuningWeights;
			/* 50h */	bool mbUseTestWeights;
			/* 54h */	uint32_t mDistanceType;
		};

		struct AssetInfo
		{
			/* 00h */	ResourceKey mKey;
			/* 0Ch */	uint32_t mnModelSubtype;
			/* 10h */	cFeatureVector mFeatureVector;
			/* 2Ch */	eastl::vector<uint32_t> mConsequenceTraits;	//contains ids from herdtypes~
			/* 40h */	int field_40[4];
		};

		struct RandomLinearCongruential
		{
			uint32_t mnSeed;
		};

		struct cClassifierFactory
		{
			//vector_map<unsigned_int,SP::Traits::IClassifierFactoryFunction_const_*,eastl::less<unsigned_int>,eastl::allocator,eastl::vector<eastl::pair<unsigned_int,SP::Traits::IClassifierFactoryFunction_const_*>,eastl::allocator>_>
			eastl::vector_map<unsigned int, int> mFactoryFunctionMap;
		};

		class ISummarizer
			: public DefaultRefCounted
		{
		public:
			/* 10h */	virtual uint32_t GetID() const = 0;
			/* 14h */	virtual int GetAMTuningVersion() const = 0;
			/* 18h */	virtual int GetAssetTypesCount() const = 0;
			/* 1Ch */	virtual uint32_t GetAssetType(int index) const = 0;
			/* 20h */	virtual bool SetParameters(const ResourceKey& key, eastl::vector<Parameter>& dst) = 0;
		};

		class cIMatchTuning
		{
		public:
			static const uint32_t TYPE = 0x4ed5013;

			/* 00h */	virtual int AddRef();
			/* 04h */	virtual int Release();
			/* 08h */	virtual bool GetTraitVector(const ResourceKey& key, const cFeatureVector& traits);
			/* 0Ch */	virtual void* GetClassNameForTrait(const cID& traitID);
			/* 10h */	virtual void* cIMatchTuning_GetClassName(uint32_t nClassifierGUID);
			/* 14h */	virtual bool DescribeResource(ResourceKey*, void*);
			/* 18h */	virtual void SetDistanceFunc(uint32_t);
			/* 1Ch */	virtual void SetTestWeights(void*);
			/* 20h */	virtual void GetTuningWeights(void*);
			/* 24h */	virtual void UseTestWeights(bool);
			/* 28h */	virtual bool TunningWeightsEnabled();

		};

		class IObjectTemplateDB
		{
		public:
			/* 00h */	virtual int AddRef();
			/* 04h */	virtual int Release();
			/* 08h */	virtual ~IObjectTemplateDB();
			/* 0Ch */	virtual void* AsInterface(uint32_t mID);
			/* 10h */	virtual bool Init();
			/* 14h */	virtual bool Shutdown();
			
			//ReIndexIfNecessary
			/* 18h */	virtual bool Write(bool rewriteSummarizers, bool);
			/* 1Ch */	virtual bool func1Ch();
			/* 20h */	virtual void func20h();

			/// Creates the asset list. Used in the game modes and for plants randomizer in Scenario Mode
			/// @param keyList Pointer where the asset list will be created
			/// @param request determines which creations should be added to the asset list
			/// @return Return true if asset list was created, otherwise return false
			/* 24h */	virtual bool GetAssetList(eastl::vector<ResourceKey>& keyList, uint32_t nNumResults, const eastl::vector<Parameter>& request);

			/// Creates the asset list. Uknown where this is used
			/// @param keyList Pointer where the asset list will be created
			/// @param request determines which creations should be added to the asset list
			/// @return Return true if asset list was created, otherwise return false
			/* 28h */	virtual bool GetAssetListUnknown(eastl::vector<ResourceKey>& keyList, const eastl::vector<Parameter>& request);

			/// Creates the asset list of pollinated adventures that can be used as mission
			/// @param keyList Pointer where the asset list will be created
			/// @param request determines which creations should be added to the asset list
			/* 2Ch */	virtual void GetPollinatedAdventureList(eastl::vector<ResourceKey>& keyList, const eastl::vector<Parameter>& request);

			/// Creates the asset list that can be used in adventure: creatures, vehicles and buildings
			/// @param keyList Pointer where the asset list will be created
			/// @param request determines which creations should be added to the asset list
			/// @return Return true if asset list was created, otherwise return false
			/* 30h */	virtual bool GetAssetListToAdventure(eastl::vector<ResourceKey>& keyList, uint32_t nNumResults, const eastl::vector<Parameter>& request);

			/// [Crash the game] Creates the asset list that can be used in new game and showed up in sporepedia
			/// @param keyList Pointer where the asset list will be created
			/// @return Return true if asset list was created, otherwise return false
			/* 34h */	virtual bool GetBrowserAssetList(eastl::vector<ResourceKey>& keyList);

			/// Creates the asset list that can be showed up in sporepedia and used in quick play(?)
			/// @param keyList Pointer where the asset list will be created
			/// @param request determines which creations should be added to the asset list
			/* 38h */	virtual void GetAdventureAssetList(eastl::vector<ResourceKey>& keyList, const eastl::vector<Parameter>& request);

			/// Creates the asset list that can be used in the Civ and Space Modes for civilizations and empires
			/// @param keyList Pointer where the asset list will be created
			/// @param request determines which creations should be added to the asset list
			/// @return Return true if asset list was created, otherwise return false
			/* 3Ch */	virtual bool GetMatchedAssetList(eastl::vector<ResourceKey>& creations, uint32_t param_2, const ResourceKey& creation, const eastl::vector<Parameter>& request);

			/* 40h */	virtual bool GetParameterIntValues(uint32_t parameter, eastl::vector<int>& intValues);
			/* 44h */	virtual bool GetParameterFloatValues(uint32_t parameter, eastl::vector<float>& floatValues);
			/* 48h */	virtual bool GetParameterIntInfo(uint32_t parameter, eastl::vector<int>& intValues, eastl::vector<ResourceKey>& keyList);
			/* 4Ch */	virtual bool GetParameterFloatInfo(uint32_t parameter, eastl::vector<float>& floatValues, eastl::vector<ResourceKey>& keyList);
			/* 50h */	virtual void SetTheme(uint32_t themeID);
			/* 54h */	virtual void ClearTheme();
			/* 58h */	virtual bool SetInUse(const ResourceKey& key, bool bInUse);
			/* 5Ch */	virtual bool IsCreationInUse(const ResourceKey& key);

			///Add creation in asset list?
			/* 60h */	virtual bool func60h(const ResourceKey& creation);

			/* 64h */	virtual void func64h(uint32_t param1, eastl::vector<ResourceKey>& creations, int param);
			/* 68h */	virtual void func68h();
			/* 6Ch */	virtual void func6Ch(uint32_t param_1, uint32_t param_2); //App::Property
			/* 70h */	virtual bool RegisterAsset(const ResourceKey& assetToRegist);
			/* 74h */	virtual bool PurgeAssetSummarizer(const ResourceKey& creation, bool param);
			/* 78h */	virtual void PurgeAsset(const ResourceKey& creation, bool param);

			/* 7Ch */	virtual bool AddSummarizer(ISummarizer* pSummarizer);

			/* 80h */	virtual bool GetAssetType(const ResourceKey& creation, int* param);
			/* 84h */	virtual bool func84h(const ResourceKey& creation, uint32_t* param_2);
			/* 88h */	virtual void func88h();
		};

		class cObjectTemplateDB
			: public IObjectTemplateDB
			, public cIMatchTuning
			, public App::IMessageListener
			, public DefaultRefCounted
		{
		public:
			static cObjectTemplateDB* Get();

			static const uint32_t TYPE = 0x4ed03fd;
			/* 00h */	virtual int AddRef() override;
			/* 04h */	virtual int Release() override;
			/* 08h */	virtual ~cObjectTemplateDB();
			/* 0Ch */	virtual void* AsInterface(uint32_t mID);

		public:
		/* 14h */	eastl::vector<AssetInfo> mAssetList;
		/* 24h */	eastl::vector_set<unsigned int> mFreeList;
		/* 40h */	bool field_40;
		/* 44h */	cJobPtr field_44;
		/* 48h */	eastl::map<unsigned int, unsigned int> field_48;
		/* 64h */	eastl::vector_set<unsigned int> mInUse;
		/* 7Ch */	eastl::vector_set<unsigned int> field_7C;
		/* 94h */	eastl::vector_set<unsigned int> field_94;
		/* ACh */	eastl::vector_map<unsigned int, unsigned int> mPopulationCount;
		/* C4h */	eastl::vector_map<unsigned int, unsigned int> mRefillCount;
		/* DCh */	eastl::vector_map<unsigned int, unsigned int> mTypePopulation;
		/* F4h */	eastl::map<unsigned int, int> mIntParameters;
		/* 110h */	eastl::map<unsigned int, float> mFloatParameters;
		/* 12Ch */	eastl::vector_set<unsigned int> mResultSet;
		/* 144h */	eastl::vector_set<unsigned int> mScratchSet1;
		/* 15Ch */	eastl::vector_set<unsigned int> mScratchSet2;
		/* 174h */	MutliModeDistance mDistanceFunction;
		/* 1CCh */	RandomLinearCongruential mRandom;
		/* 1D0h */	bool mbSaveDataDirty;
		/* 1D4h */	cClassifierFactory mClassifierFactory;
		/* 1ECh */	eastl::multimap<unsigned int, cISummarizerPtr> mSummarizerTable;	//multimap<unsigned_int,EA::AutoRefCount<SP::FunctionalMatch::cISummarizer>,eastl::less<unsigned_int>,eastl::allocator>
		/* 208h */	eastl::multimap<unsigned int, int*> mClassifierTable;	//multimap<unsigned_int,EA::AutoRefCount<SP::Traits::cIClassifier>,eastl::less<unsigned_int>,eastl::allocator>
		/* 224h */	cISummarizerPtr field_224;	//used to check if summary and pSummarizer are same in AddSummarizer
		/* 228h */	eastl::vector_set<unsigned int> mResourceTypesToReindex;
		/* 240h */	eastl::vector_map<unsigned int, float> mClassifierWeights;	//vector_map<unsigned_int,float,eastl::less<unsigned_int>,eastl::allocator,eastl::vector<eastl::pair<unsigned_int,float>,eastl::allocator>_>
		/* 258h */	eastl::vector<int> mPriorityConstraints;	//vector<SP::cSPObjectTemplateDB::PriorityConstraint,eastl::sp_vector_allocator>
		/* 26Ch */	Resource::IResourceFactory* field_26C;
		};
		ASSERT_SIZE(cObjectTemplateDB, 0x270);

		namespace Addresses(cObjectTemplateDB)
		{
			DeclareAddress(Get);
		}
	}
}