#include <Windows.h>
#include <intrin.h>
#include <cstdint>
#include <dxgi.h>
#include <time.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

#include "rust/rust.hpp"
#include "projectile.hpp"
#include "memory/memory.hpp"
#include "memory/lazy_importer.hpp"
#include "memory/il2cpp.hpp"
#include "utils/no_crt.hpp"
#include "utils/xorstr.hpp"
#include "utils/pattern/pattern.hpp"
#include "gui/OnGUI.hpp"
#include "rust/unity.hpp"
#include "rust/features/player_esp.hpp"
#include "hooks.hpp"
bool has_initialized = false;

bool DllMain(uintptr_t hmodule)
{


	if (!has_initialized) {
		mem::game_assembly_base = LI_MODULE_SAFE_(_("GameAssembly.dll"));
		mem::unity_player_base = LI_MODULE_SAFE_(_("UnityPlayer.dll"));	
		il2cpp::init();
		unity::init_unity();
		gui::init_gui();
		hooks::init_hooks();
		init_bp();
		has_initialized = true;
	}

	il2cpp::hook(&hooks::hk_performance_ui_update, _("Update"), _("PerformanceUI"), _("Facepunch"), 0);
	il2cpp::hook(&gui::render, _("OnGUI"), _("DevControls"), _(""), 0);
	mem::hook_virtual_function(_("BasePlayer"), _("ClientInput"), &hooks::hk_baseplayer_ClientInput);
	mem::hook_virtual_function(_("BasePlayer"), _("VisUpdateUsingCulling"), &hooks::hk_FakeVisUpdateUsingCulling);



	
	return true;
}
