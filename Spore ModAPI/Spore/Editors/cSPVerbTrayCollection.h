#pragma once

#include <EASTL\intrusive_ptr.h>
#include <EASTL\map.h>
#include <EASTL\vector.h>
#include <Spore\UTFWin\IWindow.h>
#include <Spore\UTFWin\IWinProc.h>
#include <Spore\Editors\cSPEditorVerbIconTray.h>
#include <Spore\Editors\VerbIconEnums.h>

#define cSPVerbTrayCollectionPtr eastl::intrusive_ptr<Editors::cSPVerbTrayCollection>

namespace Editors
{
    class cSPVerbTrayCollection
        : public UTFWin::IWinProc
        , public DefaultRefCounted
    {
    public:
        static const uint32_t TYPE = 0x4976064;

        /* 00h */	virtual int AddRef() override;
        /* 04h */	virtual int Release() override;
        //* 08h */	virtual ~cSPVerbTrayCollection();
        //* 0Ch */	virtual void* Cast(uint32_t typeID);
        /* 10h */	virtual void Init(App::PropertyList* propList);
        /* 14h */	virtual void SetTrayData(eastl::vector<VerbIconDataPtr>*);
        /* 18h */	virtual void Shutdown();
        /* 1Ch */	virtual void Update(App::PropertyList* propList);
        /* 20h */	virtual UTFWin::IWindow* GetTrayWindow(uint32_t controlID);
        /* 24h */	virtual void InitTrays(uint32_t instanceID, uint32_t typeID, uint32_t groupID);
        /* 28h */	virtual void LayoutCollection();

    public:
    /* 0Ch */    eastl::vector<cSPEditorVerbIconTrayPtr> mVerbTrays;
    /* 1Ch */    int field_1C;
    /* 20h */    IWindowPtr mWinParent;
    /* 24h */    IWindowPtr mWinVerbTray;
    /* 28h */    eastl::map<IWindowPtr, cSPEditorVerbIconTrayPtr> mWindowsToVerbTrays;
    /* 44h */    eLayoutJustification mJustification;   //kJustificationNONE
    /* 48h */    bool mAnimateValues;    //true
    /* 4Ch */    eLayoutStyle mLayoutStyle; //kFill
    /* 50h */    bool field_50;  //false
    };
    ASSERT_SIZE(cSPVerbTrayCollection, 0x58);
}

