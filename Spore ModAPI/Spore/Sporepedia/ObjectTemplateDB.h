#pragma once

#include <Spore\Sporepedia\OTDBParameters.h>

#define ObjectTemplateDB (*Sporepedia::OTDB::cObjectTemplateDB::Get())


namespace Sporepedia
{
	namespace OTDB
	{
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

		enum InterfaceId
		{

		};

		class cObjectTemplateDB
			: public Object
		{
		public:
			static cObjectTemplateDB* Get();

			/* 00h */	virtual int AddRef();
			/* 04h */	virtual int Release();
			/* 08h */	virtual void* Dispose();
			/* 0Ch */	virtual void* AsInterface(InterfaceId mID);
			/* 10h */	virtual bool Init();
			/* 14h */	virtual bool Shutdown();
			/* 18h */	virtual bool Write(bool, bool writeSummarizers);
			/* 1Ch */	virtual bool func1Ch();
			/* 20h */	virtual void func20h();
			/* 24h */	virtual bool func24h(eastl::vector<ResourceKey>& creation, int, const eastl::vector<QueryParameter>& parameters);
			/* 28h */	virtual bool func28h(eastl::vector<ResourceKey>& dstKeys);//, int, const eastl::vector<QueryParameter>& parameters);
			/* 2Ch */	virtual void FindObjects(eastl::vector<ResourceKey>& dst, const eastl::vector<Parameter>& parameters);
			//TODO thse functions are placeholders
			/* 30h */	virtual bool func30h(eastl::vector<ResourceKey>& creations, uint32_t param_2, const eastl::vector<QueryParameter>& parameters);
			/* 34h */	virtual bool func34h(eastl::vector<ResourceKey>& creations);
			/* 38h */	virtual void func38h(eastl::vector<ResourceKey>& creations, const eastl::vector<QueryParameter>& parameters);
			/* 3Ch */	virtual bool func3Ch(eastl::vector<ResourceKey>& creations, uint32_t param_2, const ResourceKey& creation, const eastl::vector<QueryParameter>& parameters);
			/* 40h */	virtual bool func40h(uint32_t param1, int* param2);
			/* 44h */	virtual bool func44h(uint32_t param1, int* param2);
			/* 48h */	virtual bool func48h(uint32_t param1, int* param2, eastl::vector<ResourceKey>& creations);
			/* 4Ch */	virtual bool func4Ch(uint32_t param1, int* param2, eastl::vector<ResourceKey>& creations);
			/* 50h */	virtual void func50h(int param);
			/* 54h */	virtual void func54h();
			/* 58h */	virtual bool func58h(const ResourceKey& creation, bool param);//ResourceKey*
			/* 5Ch */	virtual bool func5Ch(const ResourceKey& creation);
			/* 60h */	virtual bool func60h(const ResourceKey& creation);
			/* 64h */	virtual void func64h(uint32_t param1, eastl::vector<ResourceKey>& creations, int param);
			/* 68h */	virtual void func68h();
			/* 6Ch */	virtual void func6Ch(uint32_t param_1, uint32_t param_2); //App::Property
			/* 70h */	virtual bool func70h(const ResourceKey& creation);
			/* 74h */	virtual bool PurgeAssetSummarizer(const ResourceKey& creation, bool param);
			/* 78h */	virtual void PurgeAsset(const ResourceKey& creation, bool param);

			/* 7Ch */	virtual bool AddSummarizer(ISummarizer* pSummarizer);

			/* 80h */	virtual bool func80h(const ResourceKey& creation, int* param);
			/* 84h */	virtual bool func84h(const ResourceKey& creation, uint32_t* param_2);
			/* 88h */	virtual void func88h();

		public:

		/* 04h */	int field_04;
		/* 08h */	int field_08;
		/* 0Ch */	int field_0C;
		/* 10h */	int field_10;
		/* 14h */	int field_14;
		/* 18h */	int field_18;
		/* 1Ch */	int field_1C;
		/* 20h */	int field_20;
		/* 24h */	int field_24;
		/* 28h */	int field_28;
		/* 2Ch */	int field_2C;
		/* 30h */	int field_30;
		/* 34h */	int field_34;
		/* 38h */	int field_38;
		/* 3Ch */	int field_3C;
		/* 40h */	bool field_40;
		/* 41h */	bool field_41;
		/* 42h */	bool field_42;
		/* 43h */	bool field_43;
		/* 44h */	int field_44;
		/* 48h */	int field_48;
		/* 4Ch */	int field_4C;
		/* 50h */	int field_50;
		/* 54h */	int field_54;
		/* 58h */	int field_58;
		/* 5Ch */	int field_5C;
		/* 60h */	int field_60;
		/* 64h */	int field_64;
		/* 68h */	int field_68;
		/* 6Ch */	int field_6C;
		/* 70h */	int field_70;
		/* 74h */	int field_74;
		/* 78h */	int field_78;
		/* 7Ch */	int field_7C;
		/* 80h */	int field_80;
		/* 84h */	int field_84;
		/* 88h */	int field_88;
		/* 8Ch */	int field_8C;
		/* 90h */	int field_90;
		/* 94h */	int field_94;
		/* 98h */	int field_98;
		/* 9Ch */	int field_9C;
		/* A0h */	int field_A0;
		/* A4h */	int field_A4;
		/* A8h */	int field_A8;
		/* ACh */	int field_AC;
		/* B0h */	int field_B0;
		/* B4h */	int field_B4;
		/* B8h */	int field_B8;
		/* BCh */	int field_BC;
		/* C0h */	int field_C0;
		/* C4h */	int field_C4;
		/* C8h */	int field_C8;
		/* CCh */	int field_CC;
		/* D0h */	int field_D0;
		/* D4h */	int field_D4;
		/* D8h */	int field_D8;
		/* DCh */	int field_DC;
		/* E0h */	int field_E0;
		/* E4h */	int field_E4;
		/* E8h */	int field_E8;
		/* ECh */	int field_EC;
		/* F0h */	int field_F0;
		/* F4h */	int field_F4;
		/* F8h */	int field_F8;
		/* FCh */	int field_FC;
		/* 100h */	int field_100;
		/* 104h */	int field_104;
		/* 108h */	int field_108;
		/* 10Ch */	int field_10C;
		/* 110h */	int field_110;
		/* 114h */	int field_114;
		/* 118h */	int field_118;
		/* 11Ch */	int field_11C;
		/* 120h */	int field_120;
		/* 124h */	int field_124;
		/* 128h */	int field_128;
		/* 12Ch */	int field_12C;
		/* 130h */	int field_130;
		/* 134h */	int field_134;
		/* 138h */	int field_138;
		/* 13Ch */	int field_13C;
		/* 140h */	int field_140;
		/* 144h */	int field_144;
		/* 148h */	int field_148;
		/* 14Ch */	int field_14C;
		/* 150h */	int field_150;
		/* 154h */	int field_154;
		/* 158h */	int field_158;
		/* 15Ch */	int field_15C;
		/* 160h */	int field_160;
		/* 164h */	int field_164;
		/* 168h */	int field_168;
		/* 16Ch */	int field_16C;
		/* 170h */	int field_170;
		/* 174h */	int field_174;
		/* 178h */	int field_178;
		/* 17Ch */	int field_17C;
		/* 180h */	int field_180;
		/* 184h */	int field_184;
		/* 188h */	int field_188;
		/* 18Ch */	int field_18C;
		/* 190h */	int field_190;
		/* 194h */	int field_194;
		/* 198h */	int field_198;
		/* 19Ch */	int field_19C;
		/* 1A0h */	int field_1A0;
		/* 1A4h */	int field_1A4;
		/* 1A8h */	int field_1A8;
		/* 1ACh */	int field_1AC;
		/* 1B0h */	int field_1B0;
		/* 1B4h */	int field_1B4;
		/* 1B8h */	int field_1B8;
		/* 1BCh */	int field_1BC;
		/* 1C0h */	int field_1C0;
		/* 1C4h */	int field_1C4;
		/* 1C8h */	int field_1C8;
		/* 1CCh */	int field_1CC;
		/* 1D0h */	int field_1D0;
		/* 1D4h */	int field_1D4;
		/* 1D8h */	int field_1D8;
		/* 1DCh */	int field_1DC;
		/* 1E0h */	int field_1E0;
		/* 1E4h */	int field_1E4;
		/* 1E8h */	int field_1E8;
		/* 1ECh */	int field_1EC;
		/* 1F0h */	int field_1F0;
		/* 1F4h */	int field_1F4;
		/* 1F8h */	int field_1F8;
		/* 1FCh */	int field_1FC;
		/* 200h */	int field_200;
		/* 204h */	int field_204;
		/* 208h */	int field_208;
		/* 20Ch */	int field_20C;
		/* 210h */	int field_210;
		/* 214h */	int field_214;
		/* 218h */	int field_218;
		/* 21Ch */	int field_21C;
		/* 220h */	int field_220;
		/* 224h */	int field_224;
		/* 228h */	int field_228;
		/* 22Ch */	int field_22C;
		/* 230h */	int field_230;
		/* 234h */	int field_234;
		/* 238h */	int field_238;
		/* 23Ch */	int field_23C;
		/* 240h */	int field_240;
		/* 244h */	int field_244;
		/* 248h */	int field_248;
		/* 24Ch */	int field_24C;
		/* 250h */	int field_250;
		/* 254h */	int field_254;
		/* 258h */	int field_258;
		/* 25Ch */	int field_25C;
		/* 260h */	int field_260;
		/* 264h */	int field_264;
		/* 268h */	int field_268;
		/* 26Ch */	int field_26C;
		/* 270h */	int field_270;
		};
		ASSERT_SIZE(cObjectTemplateDB, 0x274);

		namespace Addresses(cObjectTemplateDB)
		{
			DeclareAddress(Get);
		}
	}
}