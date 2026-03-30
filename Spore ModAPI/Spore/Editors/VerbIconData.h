#pragma once

#include <Spore\Object.h>
#include <Spore\MathUtils.h>
#include <Spore\LocalizedString.h>
#include <Spore\App\PropertyList.h>

#define VerbIconDataPtr eastl::intrusive_ptr<Editors::VerbIconData>

namespace Editors
{
    enum eVerbIconCategory
    {
        kVerbCategoryNULL = 0,
        kVerbCategoryTribeAttack = 180661997,
        kVerbCategoryVehiclePower = 360359141,
        kVerbCategorySpeed = 640949982,
        kVerbCategoryTribeArmor = 662199250,
        kVerbCategoryHerbivore = 771444639,
        kVerbCategorySpit = 823131355,
        kVerbCategoryCellCilia = 835506386,
        kVerbCategoryVehicleDefense = 886488350,
        kVerbCategoryCellJaw = 1101458518,
        kVerbCategoryCellJet = 1168568857,
        kVerbCategorySprint = 1296465089,
        kVerbCategoryCellOmnivore = 1377441237,
        kVerbCategoryCellElectric = 1470348634,
        kVerbCategoryVehicleSpeed = 1501155019,
        kVerbCategoryOmnivore = 1557282664,
        kVerbCategoryTribeSocial = 1589650888,
        kVerbCategoryCellPoison = 1601154124,
        kVerbCategoryBite = 1645043423,
        kVerbCategoryDance = 1924791374,
        kVerbCategoryStarvivore = 2095425492,
        kVerbCategoryCellFlagella = 2165516464,
        kVerbCategoryGesture = 2167648234,
        kVerbCategoryPower = 2391494160,
        kVerbCategoryDefense = 2564315215,
        kVerbCategoryCarnivore = 2726979560,
        kVerbCategoryStealth = 2909291642,
        kVerbCategoryPosture = 2909789983,
        kVerbCategoryCellHealth = 2964572918,
        kVerbCategoryGlide = 2968795556,
        kVerbCategoryCellPoker = 3013574067,
        kVerbCategoryCellFilter = 3020374546,
        kVerbCategoryTribeFishing = 3188984297,
        kVerbCategoryTribeGather = 3253334812,
        kVerbCategoryVocalize = 3478552014,
        kVerbCategoryCellStarvivore = 3610717237,
        kVerbCategoryCellSpike = 3634179486,
        kVerbCategoryCellHerbivore = 3653024240,
        kVerbCategoryHealth = 3677180323,
        kVerbCategoryCellCarnivore = 3751859903,
        kVerbCategoryCall = 3753286133,
        kVerbCategoryJump = 3833651337,
        kVerbCategoryBlock = 4001580976,
        kVerbCategorySense = 4069948569,
        kVerbCategoryStrike = 4110605575,
        kVerbCategoryGrasp = 4248645338,
        kVerbCategoryCharge = 4285247397
    };
    class VerbIconData
        : public Object
        , public DefaultRefCounted
    {
    public:
        static const uint32_t TYPE = 0x4AA0ACD;
        VerbIconData();

        /* 00h */	virtual int AddRef() override;
        /* 04h */	virtual int Release() override;
        /* 08h */	virtual ~VerbIconData();
        /* 0Ch */	virtual void* Cast(uint32_t) const override;
        /* 10h */	virtual void Init(App::PropertyList* propList);
        /* 14h */	virtual void Shutdown();
        /* 18h */	virtual void SetArrayIndex(int arrayIndex);
        /// Used to generate text
        /* 1Ch */	virtual void SetHotKey(int verbIconTriggerKey);
        /* 20h */	virtual eastl::string16 GetIconName(bool includeLevel);
        /* 24h */	virtual eastl::string16* GetIconDescription();
	public:
    /* 0Ch */   bool mVerbIconUseDescription;   // true
    /* 0Dh */   bool mVerbIconShowLevel;    // true
    /* 0Eh */   bool mPaletteItemRolloverShowLevel; // true
    /* 0Fh */   bool mVerbIconRolloverShowLevel;    // true
    /* 10h */   bool mShowHotKey;   // false
    /* 11h */   bool mVerbIconShowZeroLevel;    // false
    /* 14h */   int mVerbIconTriggerKey;    // -2
    /* 18h */   float mVerbIconLevel;   // not initialized
    /* 1Ch */   float mVerbIconMaxLevel;    // 5.0
    /* 20h */   int field_20;
    /* 24h */   uint32_t mVerbIconCategory;   // not initialized
    /* 28h */   uint32_t mVerbIconRepresentativeAnimation;  // -1
    /* 2Ch */   Math::ColorRGBA mVerbIconColor;
    /* 3Ch */   uint32_t mVerbIconRolloverLevelImageID;
    /* 40h */   ResourceKey mVerbIconRolloverLevelLayoutID;
    /* 4Ch */   bool mVerbIconRolloverShowIcon;
    /* 4Dh */   bool mVerbIconEnforceMaxLevel;  // false
    /* 50h */   uint32_t mCreatureAbilityCategory;     // not initialized
    /* 54h */   LocalizedString mCreatureAbilityName;
    /* 68h */   eastl::string16 field_68;
    /* 78h */   uint32_t mTriggerKeyForLocalization;
    /* 7Ch */   int field_7C;   // -1
    /* 80h */   int field_80;   // -1
    /* 84h */   int field_84;
    /* 88h */   int field_88;
    /* 8Ch */   int field_8C;
    /* 90h */   uint32_t mVerbIconImageID;  // not initialized
    /* 94h */   uint32_t mVerbIconTrayOverrideImageID;
    /* 98h */   uint32_t mVerbIconTraySmallCardOverrideImageID;  // not initialized
    /* 9Ch */   ResourceKey mVerbIconLayout;
    /* A8h */   ResourceKey mVerbIconGameLayout;
    /* B4h */   ResourceKey mVerbIconStaticLayout;
    /* C0h */   PropertyListPtr mpPropList;   // not initialized
	};
    ASSERT_SIZE(VerbIconData, 0xC4);

    namespace Addresses(VerbIconData)
    {
        DeclareAddress(AddRef);
        DeclareAddress(Release);
        DeclareAddress(Dispose);
        DeclareAddress(Cast);
        DeclareAddress(Init);
        DeclareAddress(Shutdown);
        DeclareAddress(SetArrayIndex);
        DeclareAddress(SetHotKey);
        DeclareAddress(GetIconName);
        DeclareAddress(GetIconDescription);
    }

    inline VerbIconData::VerbIconData()
        : mVerbIconUseDescription(true)
        , mVerbIconShowLevel(true)
        , mPaletteItemRolloverShowLevel(true)
        , mVerbIconRolloverShowLevel(true)
        , mShowHotKey(false)
        , mVerbIconShowZeroLevel(false)
        , mVerbIconTriggerKey(-2)
        , mVerbIconLevel()
        , mVerbIconMaxLevel(5.0)
        , field_20()
        , mVerbIconCategory()
        , mVerbIconRepresentativeAnimation()
        , mVerbIconColor()
        , mVerbIconRolloverLevelImageID()
        , mVerbIconRolloverLevelLayoutID()
        , mVerbIconRolloverShowIcon()
        , mVerbIconEnforceMaxLevel()
        , mCreatureAbilityCategory()
        , mCreatureAbilityName(LocalizedString())
        , field_68(eastl::string16())
        , mTriggerKeyForLocalization()
        , field_7C(-1)
        , field_80(-1)
        , field_84()
        , field_88()
        , field_8C()
        , mVerbIconImageID()
        , mVerbIconTrayOverrideImageID()
        , mVerbIconTraySmallCardOverrideImageID()
        , mVerbIconLayout()
        , mVerbIconGameLayout()
        , mVerbIconStaticLayout()
        , mpPropList(nullptr)
    {
    }
    inline VerbIconData::~VerbIconData() {}
    inline int VerbIconData::AddRef() {
        return DefaultRefCounted::AddRef();
    }
    inline int VerbIconData::Release() {
        return DefaultRefCounted::Release();
    }
    inline void* VerbIconData::Cast(uint32_t type) const {
        CLASS_CAST(Object);
        CLASS_CAST(VerbIconData);
        return nullptr;
    }
#ifndef SDK_TO_GHIDRA

    inline auto_METHOD_VOID(VerbIconData, Init, Args(App::PropertyList* propList), Args(propList));
    inline auto_METHOD_VOID_(VerbIconData, Shutdown);
    inline auto_METHOD_VOID(VerbIconData, SetArrayIndex, Args(int arrayIndex), Args(arrayIndex));
    inline auto_METHOD_VOID(VerbIconData, SetHotKey, Args(int verbIconTriggerKey), Args(verbIconTriggerKey));
    inline auto_METHOD(VerbIconData, eastl::string16, GetIconName, Args(bool includeLevel), Args(includeLevel));
    inline auto_METHOD_(VerbIconData, eastl::string16*, GetIconDescription);

#endif
}
