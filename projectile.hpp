#pragma once

#include "rust/features/player_esp.hpp"
#include "rust/classes.hpp"

#include <windows.h>
#include "offsets.h"

//#define safe_read(Addr, Type) mem::read<Type>((DWORD64)Addr)
//#define safe_write(Addr, Data, Type) mem::write<Type>((DWORD64)Addr, Data);
//
//
//void SetRA() {
//    if (settings::weapon::legit_recoil) {
//        DWORD64 Input = safe_read(this + 0x4e0, DWORD64);
//        vector2 RA = { 0.f, 0.f };
//        safe_write(Input + 0x64, RA, vector2);
//    }
//}