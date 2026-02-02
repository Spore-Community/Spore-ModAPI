#pragma once

#include <Spore\BasicIncludes.h>
#include <Spore\CommonIDs.h>

#define cSpeciesRelationshipManagerPtr intrusive_ptr<cSpeciesRelationshipManager>
#define SpeciesRelationshipManager (*Simulator::cSpeciesRelationshipManager::Get())

namespace Simulator
{

	enum eRelationshipStatus
	{
		kRelationshipNone = 0,
		kRelationshipFeared = 1,
		kRelationshipHated = 2,
		kRelationshipNeutral = 3,
		kRelationshipFriendly = 4,
		kRelationshipHostile = 5,
		kRelationshipBestFriends = 6,
		kRelationshipLover = 7,
	};

	enum eGameModeTransitionStatus
	{
		kTransitionEnd = 0,
		kTransitionPrepare = 1,
		kTransitionPost = 2,
	};

	class IGonzagoSubsystem
	{
	public:
		/* 00h */ virtual int AddRef();
		/* 04h */ virtual int Release();
		/* 08h */ virtual void InitGonzagoSubsystem();
		/* 0Ch */ virtual void ShutdownGonzagoSubsystem();
		/* 10h */ virtual wchar_t* GetGonzagoSubsystemName();
		/* 14h */ virtual void PreGameModeTransition(int, int);
		/* 18h */ virtual void PostGameModeTransition(int, int);
		/* 1Ch */ virtual GameModeIDs GetPreModeTransitionState();
		/* 20h */ virtual GameModeIDs GetPostModeTransitionState();
		/* 24h */ virtual bool CheckGonzagoSubsystemInitState();
		/* 28h */ virtual bool Write(ISerializerStream* stream);
		/* 2Ch */ virtual bool Read(ISerializerStream* stream);
		/* 30h */ virtual bool PostLoad(int);
		/* 34h */ virtual void DisposeAttributeToXML(XmlSerializer*); // No exact comparative func in F08
		/* 38h */ virtual void PreUpdateTick(int, int);
		/* 3Ch */ virtual void PostUpdateTick(int, int);
		/* 40h */ virtual void BeginPreGameModeTransition(int);
		/* 44h */ virtual void BeginPostGameModeTransition(int);
		/* 48h */ virtual void EndPreGameModeTransition();
		/* 4Ch */ virtual void EndPostGameModeTransition();
	};
	namespace Addresses(IGonzagoSubsystem) {
		DeclareAddress(AddRef);
		DeclareAddress(Release);
		DeclareAddress(InitGonzagoSubsystem);
		DeclareAddress(ShutdownGonzagoSubsystem);
		DeclareAddress(GetGonzagoSubsystemName);
		DeclareAddress(PreGameModeTransition);
		DeclareAddress(PostGameModeTransition);
		DeclareAddress(GetPreModeTransitionState);
		DeclareAddress(GetPostModeTransitionState);
		DeclareAddress(CheckGonzagoSubsystemInitState);
		DeclareAddress(Write);
		DeclareAddress(Read);
		DeclareAddress(PostLoad);
		DeclareAddress(DisposeAttributeToXML);
		DeclareAddress(PreUpdateTick);
		DeclareAddress(PostUpdateTick);
		DeclareAddress(BeginPreGameModeTransition);
		DeclareAddress(BeginPostGameModeTransition);
		DeclareAddress(EndPreGameModeTransition);
		DeclareAddress(EndPostGameModeTransition);
	}

	class cGonzagoSubsystem
		: public IGonzagoSubsystem
		, public ISimulatorSerializable
	{
	public:
		/* 0ch */ GameModeIDs mPreModeTransitionState;
		/* 10h */ GameModeIDs mPostModeTransitionState;
		/* 14h */ GameModeIDs mCurrentTransition;
		/* 18h */ eGameModeTransitionStatus mCurrentTransitionPhase;
	};
	ASSERT_SIZE(cGonzagoSubsystem, 0x18);

	struct tRelationshipData	//i think it's actually class-object because in F08 it contains Read and Write functions
	{
		/* 00h */	eRelationshipStatus relationship;
		/* 04h */	int friendlyCount;
		/* 08h */	int numBefriended;
		/* 0Ch */	int numKilled;
		/* 10h */	uint32_t lastAbilityMode;
		/* 14h */	uint32_t discoveryData;
	};

	class cSpeciesRelationshipManagerDispose
	{
	public:
		/* 00h */ virtual void* Dispose();
	};

	namespace Addresses(cSpeciesRelationshipManagerDispose) {
		DeclareAddress(Dispose);
	}

	class cSpeciesRelationshipManager
		: public cGonzagoSubsystem
		, public cSpeciesRelationshipManagerDispose
	{
	public:
		static const uint32_t TYPE = 0xf2dcc8bc;
		static const uint32_t NOUN_ID = 0x92dcc8bb;

		static cSpeciesRelationshipManager* Get();

		/* 00h */ virtual void* Dispose() override;
		/* 04h */ virtual bool HandleMessage(uint32_t message);
		/* 08h */ virtual int AddRef() override;
		/* 0Ch */ virtual int Release() override;
		/* 10h */ virtual uint32_t GetType(uint32_t);	//AsInterface
		/* 14h */ virtual int GetFieldValue(int*);
		/* 18h */ virtual uint32_t GetClassID();

		//static eRelationshipStatus GetRelationship(ResourceKey*, cCreatureBase*, cCreatureBase*);

	public:
		/* 1Ch */ int mNumOfKnowSpecies;
		/* 1Ch */ int _padding_;
		/* 1Ch */ int _padding_2;
		/* 20h */ hash_map<ResourceKey, tRelationshipData> mSpeciesRelationshipMap;	//hash_map<ResourceKey, tRelationshipData>
		/* 40h */ hash_map<ResourceKey, tRelationshipData> mSpeciesRelationshipMap2;
	};
	ASSERT_SIZE(cSpeciesRelationshipManager, 0x68);

	namespace Addresses(cSpeciesRelationshipManager) {
		DeclareAddress(Get);

		DeclareAddress(Dispose);
		DeclareAddress(HandleMessage);
		DeclareAddress(AddRef);
		DeclareAddress(Release);
		DeclareAddress(GetType);
		DeclareAddress(GetFieldValue);
		DeclareAddress(GetClassID);
	}
}