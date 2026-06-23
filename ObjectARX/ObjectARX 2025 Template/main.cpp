#include "pch.h"
#include "aced.h"
#include "rxregsvc.h"

void initApp()
{
    acedRegCmds->addCommand(
        L"MY_COMMAND_GROUP",
        L"HELLO",
        L"HELLO",
        ACRX_CMD_MODAL,
        []()
        {
            acutPrintf(L"\nHello from ObjectARX!");
        });
}

void unloadApp()
{
    acedRegCmds->removeGroup(L"MY_COMMAND_GROUP");
}

extern "C"
AcRx::AppRetCode acrxEntryPoint(AcRx::AppMsgCode msg, void* pkt)
{
    switch (msg)
    {
    case AcRx::kInitAppMsg:
        acrxUnlockApplication(pkt);
        acrxRegisterAppMDIAware(pkt);
        initApp();
        break;

    case AcRx::kUnloadAppMsg:
        unloadApp();
        break;
    }

    return AcRx::kRetOK;
}