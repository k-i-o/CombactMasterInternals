#pragma once
#include "../includes.h"
#include "../kiero/minhook/include/MinHook.h"
#include "../il2cpp.h"

typedef void(__fastcall* setTargetRecoil_Orig)(void* __this, float recoil, void* method);
setTargetRecoil_Orig setTargetRecoil_Instance = nullptr;

void __fastcall setTargetRecoilDetour(CombatMaster_Battle_Gameplay_Player_PlayerMovement_o* __this, float recoil, void* method) {
    if (vars::EnableNoRecoil) {
        recoil = vars::recoilValue;
    }

    setTargetRecoil_Instance(__this, recoil, method);
}


void noRecoil() {                                                                        
    void* targetFunction = reinterpret_cast<void*>(reinterpret_cast<char*>(vars::offsets::GameAssembly) + vars::offsets::setTargetRecoilRVA);

    if (!vars::isSetTargetRecoilHooked) {
        if (MH_CreateHook(targetFunction, &setTargetRecoilDetour, reinterpret_cast<void**>(&setTargetRecoil_Instance)) == MH_OK) {
            MH_EnableHook(targetFunction);
            printf("Hook for SetRecoil enabled successfully.\n");
            vars::isSetTargetRecoilHooked = true;
        }
        else {
            printf("Failed to create and enable the hook for SetRecoil.\n");
        }
    }
}

//--------------

typedef void(__fastcall* set_ChargedAmmoLeft_Orig)(void* __this, int32_t recoil, void* method);
set_ChargedAmmoLeft_Orig set_ChargedAmmoLeft_Instance = nullptr;

void __fastcall set_ChargedAmmoLeftDetour(Photon_Bolt_PlayerCommandInput_o* __this, int32_t ammo, void* method) {
    if (vars::EnableInfiniteAmmo) {
        ammo = ammo+10;
    }

    //Call the original function so it resumes/functions like normal.
    set_ChargedAmmoLeft_Instance(__this, ammo, method);
}

void infiniteAmmo() {
    void* targetFunction = reinterpret_cast<void*>(reinterpret_cast<char*>(vars::offsets::GameAssembly) + vars::offsets::set_ChargedAmmoLeftRVA);

    if (!vars::isInfiniteAmmoHooked) {
        if (MH_CreateHook(targetFunction, &set_ChargedAmmoLeftDetour, reinterpret_cast<void**>(&set_ChargedAmmoLeft_Instance)) == MH_OK) {
            MH_EnableHook(targetFunction);
            printf("Hook for InfiniteAmmo enabled successfully.\n");
            vars::isInfiniteAmmoHooked = true;
        }
        else {
            printf("Failed to create and enable the hook for InfiniteAmmo.\n");
        }
    }
}

