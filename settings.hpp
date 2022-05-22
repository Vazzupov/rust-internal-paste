#pragma once
namespace Vars {
	namespace User {
		float ScreenWidth = 1920;
		float ScreenHeight = 1080;

		bool Panic = false;

		bool MenuOpen = true;
		bool InsertPressed = false;

		int activetab = 0;

		int last_active_id = 0;

		float lastSentTickTime = 0.f;
	}
}
namespace settings {
	bool gongetflyhack = true;
	float flyhack = 0.f;
	float hor_flyhack = 0.f;
	float max_flyhack = 0.f;
	float max_hor_flyhack = 0.f;

	bool aimbot = false;
	bool Prediction = true;
	bool RecoilControlSystem = false;
	float AimLimitDistance = 300.f;

	namespace weapon {
		float RCSyaw = 0;
		float RCSpitch = 0;
		bool Fov = false;
		bool snaplines = false;
		bool rapid_fire = false;
		bool hitbox_override  = false;
		bool magic_bullet  = false;
		bool fastshoot = false;
		float aimbotfov = 500;
		float thickness = 0.9;
		bool random_hitbox  = false;
		bool silent_melee = false;
		bool weapon_removals  = false;
		bool eoka = false;
		bool always_shoot  = false;
		bool psilent = false;
		bool psilentvis = false;
		bool thick_bullet = false;
		bool legit_recoil = false;
		bool fast_bullet = false;
		bool ultraBullet = false;
		bool norecoil = false;
		bool nospread = false;
		bool nosway = false;
		bool automatic = false;
		bool mods = false;
	}

	namespace visuals {
		bool showDistance = true;
		bool Backpack = false;
		bool visblcheck = false;
		float esp_distance = 150.f;
		bool distance = false;
		bool fill_box = false;
		bool player_esp = false;
		bool rainbow_chams = false;
		bool hotbar_esp = false;
		bool chams = false;
		bool boxesp = true;
		bool spriteitem = false;
		bool cancer = false;
		bool misc_esp  = true;
		bool sleeper_esp  = false;
		bool heli_esp = false;
		bool outline = false;
		bool npc_esp = false;
		bool dropped_items = false;

		float VisRcolor = 1;
		float VisGcolor = 0.6;
		float VisBcolor = 0;
		float InvRcolor = 0.3828125;
		float InvGcolor = 0.109375;
		float InvBcolor = 0.30078125;
		float TeamRcolor = 0.984375;
		float TeamGcolor = 0.01171875;
		float TeamBcolor = 0.984375;
		bool stash = false;
		bool materials = false;
		bool sulfur_ore = false;
		bool stone_ore = false;
		bool metal_ore = false;
		bool weapon = false;
		bool midhealth = false;
		bool midname = false;
		bool traps = false;
		bool vehicles = false;
		bool airdrops = false;
		bool cloth = false;
		bool corpses = false;
		bool tc_esp = false;
		bool raid_esp = false;
		bool hackable_crate_esp = false;
		bool full_box = false;
		bool corner_box = false;
		bool bottomhealth = false;
		bool steamid = false;
		bool sidehealth = false;
		bool nameesp = false;
		bool woundedflag = false;

		bool weaponesp = false;
		bool vehicle = false;
		bool Day = false;
		float DayTime = 12.f;
	}

	namespace misc {
		bool DoorKnocker = false;
		bool AutoPickup = false;
		bool AutoFarmOre = false;
		bool AutoFarmTree = false;
		bool reloadcooldown = false;
		bool AutoFarmBot = false;
		bool activ_checkbox = false;
		bool todsky = false;
		float    m_idebugcam_speed = 1.f;
		float code_lock_code = 1000;
		bool playerfovtoggle = false;
		float playerfov = 90;
		bool zoomtoggle = false;
		float zoomfov = 10;
		bool Movement = true;
		bool eyeoffset = false;
		float playereyes = 1.4;
		bool spinbot  = false;
		bool always_shoot = false;
		bool attack_on_mountables = false;
		bool speedhack = false;
		bool hitsound = false;
		float speedhackspeed = 5;
		bool TakeFallDamage = false;
		bool silent_farm = false;
		bool auto_lock = false;
		bool always_sprint = false;
		bool gravity = false;
		bool infinite_jump = false;
		bool fake_lag = false;
		bool brightnight = false;
		float staramount = 350;
		bool admin_mode = false;
		bool view_offset  = false;
		bool instant_med  = false;
		bool instant_revive = false;
		bool no_playercollision = false;
		bool spiderman = false;
		bool Crosshair = true;
		bool silentwalk = false;
		bool interactive_debug = false;
		bool trollface = false;

	}


	namespace Radar
	{
		float ActiveSlotPos_X = 63.f;
		float ActiveSlotPos_Y = 315.f;
		bool ActiveSlot = true;



		bool Enable = false;
		bool ShowRadarBackground = false;
		bool ShowRadarPlayer = false;
		bool ShowRadarSleeper = false;
		bool ShowRadarStoneOre = false;
		bool ShowRadarMettalOre = false;
		bool ShowRadarSulfureOre = false;



		float Pos_X = 0;
		float Pos_Y = 0;
		float Radar_Size = 300;
		float Radar_Range = 300;

	}
}