#pragma once

#include <Spore\Resource\ResourceObject.h>
#include <EASTL\vector.h>

namespace Sporepedia
{
	namespace OTDB
	{
		struct Parameter
		{
			enum ParamTypes
			{
				kInt = 0x2E1A75D,
				kFloat = 0x2E1A7FF
			};

			/* 00h */	uint32_t paramID;
			/* 04h */	uint32_t type;
			/* 08h */	union UNNAMED(ParamValuesUnion) {
				int valueInt;
				float valueFloat;
			};

			static Parameter Int(uint32_t paramID, int value);
			static Parameter Float(uint32_t paramID, float value);
		};
		ASSERT_SIZE(Parameter, 0xC);

		class ParameterResource
			: public Resource::ResourceObject
		{
		public:
			static const uint32_t TYPE = 0x670DA17;
			static const uint32_t RESOURCE_TYPE = 0x2D5C9AF;  // .summary

			/* 14h */	int field_14;
			/* 18h */	eastl::vector<Parameter> mParameters;
		};
		ASSERT_SIZE(ParameterResource, 0x2C);

		struct QueryParameter
		{
			/* 00h */	uint32_t paramID;
			/* 04h */	uint32_t type;  // 0x2E1A7FF
			union UNNAMED(ParameterRangeUnion) {
				struct UNNAMED(ParameterFloatRange) {
					/* 08h */	float fminValue;
					/* 0Ch */	float fmaxValue;
				};
				struct UNNAMED(ParameterIntRange) {
					/* 08h */	int iminValue;
					/* 0Ch */	int imaxValue;
				};
			};
			/* 10h */	eastl::vector<QueryParameter> mParameters;

			static QueryParameter Int(uint32_t paramID, int minValue, int maxValue);
			static QueryParameter Float(uint32_t paramID, float minValue, float maxValue);
		};
		ASSERT_SIZE(QueryParameter, 0x24);

		// 0x165E841 messageID for saving summary, receives resourcekey


		namespace Parameters
		{
			enum eParameterIDs
			{
				/// General
				kParameterIDPublished = 0x05fb4759,
				kParameterIDFeedID = 0x03cc89b1,	//kParameterIDThemeID
				kParameterIDContentSource = 0x05dc0b88,
				kParameterTimeDownloaded = 0x061ef9b1,
				kParamIDType = 0xdd90af,
				kParamIDSubType = 0x2dc9d1e,
				kParameterIDGAProp = 0xcd6e902c,
				kParameterIDValidationPlayable = 0x54a32960,
				kParameterIDValidationPollinatable = 0x54a32961,
				kParameterIDValidationViewableLarge = 0x0665f917,
				kParameterIDValidationEditable = 0x067b82d8,
				kParameterIDExpansionPackage = 0x17a1c72d,

				/// Creature
				kParameterIDCreatureSpeciesArchetype = 0x52def3f,
				kParameterIDCreatureSpeciesArchetypeQuery = 0x052def4b,
				kParamIDCreatureCarnivore = 0x2f05c58,
				kParamIDCreatureHerbivore = 0x2f05c59,
				kParamIDCreatureTotalAttack = 0x3fea1a0,
				kParamIDCreatureTotalSocial = 0x2f05c5f,

				/// Vehicle
				kParameterIDVehicleDefense = 0x0429d47d,
				kParameterIDVehicleSpeed = 0x0429d47e,
				kParameterIDVehiclePower = 0x0429d47c,
				kParameterIDVehicleTotalScore = 0x05b950d7,
				kParameterIDVehicleType = 0x05c96ff0,

				/// Vehicle/Building
				// F08 Build
				kParameterIDBoundingBoxX = 0x05de94e6,
				kParameterIDBoundingBoxY = 0x05de94e7,
				kParameterIDBoundingBoxZ = 0x05de94e8,
				kParameterIDBoundingBoxTotalF08 = 0x05de94e9,

				// Release
				kParameterIDBoundingBoxHeight = 0x05de94ea, //BoundingBoxMaxZ
				kParameterIDBoundingBoxTotal = 0x05e62409,

				/// Adventure
				kParameterIDAdventureCompleted = 0x15e8afc8,	//in Space Stage?
				kParameterIDAdventureCannotEdit = 0xb91fba14,
				kParameterIDAdventureMissingAsset = 0xd22f5e35,
				kParameterIDAdventureAvatarLocked = 0x5a3584a7,
				kParameterIDAdventureInvalidVersion = 0xdb4675dd
			};

			enum eFeedIDs
			{
				kFeedIDShippingContent = 0x913b23be,	//Assembled
				kFeedIDLocalContent = 0x5a3b873d,
				kFeedIDPollinatedContent = 0x058669b4	//Imported
			};

			enum eContentSourceIDs
			{
				kContentSourceAssembled = 0,
				kContentSourceMatched = 1,
				kContentSourceImported = 2
			};

			enum eExpansionPackageIDs
			{
				kExpansionPackageCoreGame = 1,
			};

			enum eVehicleTypes
			{
				kVehicleTypeWater = 0x05c972ee,
				kVehicleTypeLand = 0x05c972ea,
				kVehicleTypeAir = 0x05c972f1,
			};
			// TODO: Some of these don't seem to work; the ones that are verified to work are commented.
			enum Parameters : uint32_t
			{
				type = 0x2DD90AF,
				subtype = 0x2DC9D1E,
				archetype = 0x52DEF3F,
				cost = 0x5B06E36,
				baseGear = 0x2F05C60,
				height = 0x7358629A,
				carnivore = 0x2F05C58, // works
				herbivore = 0x2F05C59, // works
				cuteness = 0x2F05C5E,
				meanLookingScore = 0x3FEA210,
				totalAttack = 0x3FEA1A0, // works
				totalSocial = 0x2F05C5F, // works
				attack = 0x5B15A92,
				social = 0x5B15AA5,
				numFeet = 0x3FEA1C0,
				numGraspers = 0x2F05C61,
				biteCapRange = 0x4AB3BD8,
				strikeCapRange = 0x4AB3BD9,
				chargeCapRange = 0x4AB3BDA,
				spitCapRange = 0x4AB3BDB,
				singCapRange = 0xF42136D5,
				danceCapRange = 0xF42136D6,
				charmCapRange = 0xF42136D7,
				poseCapRange = 0xF42136D8,
				glideCapRange = 0x5AC2B96,
				stealthCapRange = 0x5AC2B97,
				sprintCapRange = 0x5AC2B98,
				senseCapRange = 0x68DE3E8,
				healthCapRange = 0x5AC2B99,
			};
		}

		inline Parameter Parameter::Int(uint32_t paramID, int value)
		{
			Parameter p;
			p.paramID = paramID;
			p.type = Parameter::kInt;
			p.valueInt = value;
			return p;
		}
		inline Parameter Parameter::Float(uint32_t paramID, float value)
		{
			Parameter p;
			p.paramID = paramID;
			p.type = Parameter::kFloat;
			p.valueFloat = value;
			return p;
		}

		inline QueryParameter QueryParameter::Int(uint32_t paramID, int minValue, int maxValue)
		{
			QueryParameter p;
			p.paramID = paramID;
			p.type = Parameter::kInt;
			p.iminValue = minValue;
			p.imaxValue = maxValue;
			return p;
		}
		inline QueryParameter QueryParameter::Float(uint32_t paramID, float minValue, float maxValue)
		{
			QueryParameter p;
			p.paramID = paramID;
			p.type = Parameter::kFloat;
			p.fminValue = minValue;
			p.fmaxValue = maxValue;
			return p;
		}
	}
}

typedef Sporepedia::OTDB::Parameter OTDBParameter;
typedef Sporepedia::OTDB::QueryParameter OTDBQueryParameter;