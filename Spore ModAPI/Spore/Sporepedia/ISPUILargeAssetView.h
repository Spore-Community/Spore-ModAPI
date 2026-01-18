#pragma once

#include <Spore\UTFWin\IWindow.h>
#include <Spore\Object.h>
#include <EASTL\intrusive_ptr.h>
#include <EASTL\utility.h>

#define ISPUIAssetViewPtr eastl::intrusive_ptr<Sporepedia::ISPUILargeAssetView>

namespace Sporepedia
{
    class ISPUILargeAssetView
    {
		/* 00h */	virtual int AddRef();
		/* 04h */	virtual int Release();
		/* 08h */	virtual void* Dispose();
		/* 0Ch */	virtual void* AsInterface(InterfaceId interfaceID);
		/* 10h */	virtual int GetPriority();	//return 0
		/* 14h */	virtual uint32_t GetEventMask();	//return 0xc1
		/* 18h */	virtual bool func18h(int unk, UTFWin::IWindow* window);
		/* 1Ch */	virtual void LoadAssetViewLarge();
    };
    namespace Addresses(ISPUILargeAssetView)
    {
        DeclareAddress(AddRef);
        DeclareAddress(Release);
        DeclareAddress(Dispose);
        DeclareAddress(AsInterface);
        DeclareAddress(GetPriority);
        DeclareAddress(GetEventMask);
        DeclareAddress(func18h);
        DeclareAddress(LoadAssetViewLarge);
    }
}