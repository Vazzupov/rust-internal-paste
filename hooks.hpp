#pragma once
#include "memory/il2cpp.hpp"
#include "settings.hpp"
#include "offsets.h"
#include <math.h>
#include "Keybind.h"
Vector m_debugcam_toggle_pos;
Vector m_debugcam_pos;



namespace hooks {
	namespace orig {
		static auto baseplayer_client_input = reinterpret_cast<void (*)(base_player*, input_state*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("ClientInput"), -1, _(""), _(""))));
		static auto BaseProjectile_OnSignal = reinterpret_cast<void (*)(base_projectile*, int, rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("OnSignal"), 2, _(""), _(""))));
		static auto playerwalkmovement_client_input = reinterpret_cast<void (*)(playerwalkmovement*, uintptr_t, modelstate*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerWalkMovement"), _("ClientInput"), -1, _(""), _(""))));
		static auto VisUpdateUsingCulling = reinterpret_cast<void (*)(void* ,float, bool)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("VisUpdateUsingCulling"), 1, _(""), _(""))));
		static auto DoFixedUpdate = reinterpret_cast<void (*)(playerwalkmovement*, modelstate*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerWalkMovement"), _("DoFixedUpdate"), -1, _(""), _(""))));
		static auto blocksprint = reinterpret_cast<void (*)(base_player*, float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("BlockSprint"), 1, _(""), _(""))));
		static auto OnNetworkMessage = reinterpret_cast<void (*)(uintptr_t, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Client"), _("OnNetworkMessage"), 1, _(""), _(""))));
		static auto CheckCapsule = reinterpret_cast<bool(*)(Vector, Vector, float, int, rust::classes::QueryTriggerInteraction)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Physics"), _("CheckCapsule"), 0, _(""), _("UnityEngine"))));
		static auto Run = reinterpret_cast<rust::classes::string (*)(uintptr_t, uintptr_t, rust::classes::string, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("ConsoleSystem"), _("Run"), 3, _(""), _(""))));
		uintptr_t playerprojectileattack;
		uintptr_t serverrpc_projectileshoot;
		uintptr_t serverrpc_processattack;
	}

	static auto serverrpc_projecileshoot = rb::pattern::find_rel(//
		_("GameAssembly.dll"), _("4C 8B 0D ? ? ? ? 48 8B 75 28"));

	static auto serverrpc_uint = rb::pattern::find_rel(
		_("GameAssembly.dll"), _("74 3A 4C 8B 0D ? ? ? ? 48 8B CB"));

	static auto set_sprinting = reinterpret_cast<void (*)(modelstate*, bool value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("ModelState"), _("set_sprinting"), -1, _(""), _(""))));

	static auto draw_get = reinterpret_cast<void (*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("DDraw"), _("Get"), 0, _(""), _("UnityEngine"))));

	static auto set_flying = reinterpret_cast<void (*)(modelstate * model_state, bool value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("ModelState"), _("set_flying"), 1, _(""), _(""))));

	static auto GetSpeed = reinterpret_cast<float (*)(base_player * baseplayer, float running, float ducking)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("GetSpeed"), 2, _(""), _(""))));

	static auto get_ducked = reinterpret_cast<bool (*)(modelstate*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("ModelState"), _("get_ducked"), 0, _(""), _(""))));

	static auto IsSwimming = reinterpret_cast<bool (*)(base_player*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("IsSwimming"), 0, _(""), _(""))));

	static auto ServerRPC = reinterpret_cast<void (*)(uintptr_t, rust::classes::string funcName)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("ServerRPC"), 1, _("funcName"), _(""), 1)));

	static auto OnLand = reinterpret_cast<void (*)(base_player*, float fVelocity)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("OnLand"), 1, _("fVelocity"), _(""), 1)));

	static auto DoHit = reinterpret_cast<bool (*)(base_projectile*, HitTest*, Vector, Vector)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Projectile"), _("DoHit"), 4, _(""), _(""))));

	static auto Update = reinterpret_cast<void (*)(void* instance)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PerformanceUI"), _("Update"), 0, _(""), _("Facepunch"))));

	static auto CheckCapsule = reinterpret_cast<bool(*)(Vector, Vector, float, int, rust::classes::QueryTriggerInteraction)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Physics"), _("CheckCapsule"), 0, _(""), _("UnityEngine"))));


	void init_hooks() {
		orig::OnNetworkMessage = reinterpret_cast<void (*)(uintptr_t, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Client"), _("OnNetworkMessage"), 1, _(""), _(""))));
		orig::BaseProjectile_OnSignal = reinterpret_cast<void (*)(base_projectile*, int, rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("OnSignal"), 2, _(""), _(""))));
		orig::baseplayer_client_input = reinterpret_cast<void (*)(base_player*, input_state*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("ClientInput"), -1, _(""), _(""))));
		orig::playerwalkmovement_client_input = reinterpret_cast<void (*)(playerwalkmovement*, uintptr_t, modelstate*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerWalkMovement"), _("ClientInput"), -1, _(""), _(""))));
		orig::VisUpdateUsingCulling = reinterpret_cast<void (*)(void*, float, bool)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("VisUpdateUsingCulling"), -1, _(""), _(""))));
		orig::DoFixedUpdate = reinterpret_cast<void (*)(playerwalkmovement*, modelstate*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerWalkMovement"), _("DoFixedUpdate"), -1, _(""), _(""))));
		orig::blocksprint = reinterpret_cast<void (*)(base_player*, float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("BlockSprint"), 1, _(""), _(""))));
		serverrpc_projecileshoot = rb::pattern::find_rel(
			_("GameAssembly.dll"), _("4C 8B 0D ? ? ? ? 48 8B 75 28"));

		serverrpc_uint = rb::pattern::find_rel(
			_("GameAssembly.dll"), _("74 3A 4C 8B 0D ? ? ? ? 48 8B CB"));

	
		 Update = reinterpret_cast<void (*)(void* instance)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PerformanceUI"), _("Update"), 0, _(""), _("Facepunch"))));

		set_sprinting = reinterpret_cast<void (*)(modelstate*, bool value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("ModelState"), _("set_sprinting"), -1, _(""), _(""))));

		draw_get = reinterpret_cast<void (*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("DDraw"), _("Get"), 0, _(""), _("UnityEngine"))));

		set_flying = reinterpret_cast<void (*)(modelstate * model_state, bool value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("ModelState"), _("set_flying"), 1, _(""), _(""))));

		GetSpeed = reinterpret_cast<float (*)(base_player * baseplayer, float running, float ducking)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("GetSpeed"), 2, _(""), _(""))));

		get_ducked = reinterpret_cast<bool (*)(modelstate*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("ModelState"), _("get_ducked"), 0, _(""), _(""))));

		IsSwimming = reinterpret_cast<bool (*)(base_player*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("IsSwimming"), 0, _(""), _(""))));

		ServerRPC = ServerRPC = reinterpret_cast<void (*)(uintptr_t, rust::classes::string funcName)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("ServerRPC"), 1, _("funcName"), _(""), 1)));

		OnLand = reinterpret_cast<void (*)(base_player*, float fVelocity)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("OnLand"), 1, _("fVelocity"), _(""), 1)));

		DoHit = reinterpret_cast<bool (*)(base_projectile*, HitTest*, Vector, Vector)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Projectile"), _("DoHit"), 4, _(""), _(""))));

		CheckCapsule = reinterpret_cast<bool(*)(Vector, Vector, float, int, rust::classes::QueryTriggerInteraction)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Physics"), _("CheckCapsule"), 0, _(""), _("UnityEngine"))));
	}

	double CalcBulletDrop(double height, double DepthPlayerTarget, float velocity, float gravity) {

		auto camera_pos = unity::get_camera_pos();
		aim_target target = local_player->get_aimbot_target(camera_pos);
		auto transform = target.player->get_bone_transform(48);
		auto position = transform->get_bone_position();
		auto distance = local_player->get_bone_transform(48)->get_bone_position().Distance(position);
		double pitch = (m_atan2(height, DepthPlayerTarget));
		double BulletVelocityXY = velocity * m_cos(pitch);
		double Time = DepthPlayerTarget / BulletVelocityXY;

		if (distance < 249.f)
		{
			double TotalVerticalDrop = (0.509f * gravity * Time * Time);
			return TotalVerticalDrop * 10;
		}

		if (distance >= 250.f)
		{
			double TotalVerticalDrop = (0.480f * gravity * Time);
			return TotalVerticalDrop * 10;
		}



		
	}


	static bool wakeup{ true };
	uintptr_t game_object;
	void hk_performance_ui_update(void* instance) {
		if (wakeup)
		{
			game_object = il2cpp::methods::object_new(il2cpp::init_class(_("GameObject"), _("UnityEngine")));
			gui::methods::create(game_object, _(L""));
			gui::methods::add_component(game_object, il2cpp::type_object(_(""), _("DevControls")));
			gui::methods::dont_destroy_on_load(game_object);
			wakeup = false;
		}
		Update(instance);
	}




	void Prediction(Vector local, Vector& target, Vector targetvel, float bulletspeed, float gravity) {
		float Dist = local.Distance(target);
		float BulletTime = Dist / bulletspeed;

		Vector vel = Vector(targetvel.x, 0, targetvel.z) * 0.75f;

		Vector PredictVel = vel * BulletTime;

		target += PredictVel;

		double height = target.y - local.y;
		Vector dir = target - local;
		float DepthPlayerTarget = my_sqrt(powFFFFFFFFFFFFFFFFFFFFFF(dir.x) + powFFFFFFFFFFFFFFFFFFFFFF(dir.z));

		float drop = CalcBulletDrop(height, DepthPlayerTarget, bulletspeed, gravity);

		target.y += drop;
	}



	void hk_serverrpc_projectileshoot(int64_t rcx, int64_t rdx, int64_t r9, int64_t projectileShoot, int64_t arg5) {
		do {
			if (!local_player)
				break;

			auto weapon = local_player->get_active_weapon();
			const int ammo = weapon->LoadedAmmo();

			if (!weapon)
				break;

			auto baseprojectile = local_player->get_active_weapon()->get_base_projetile();
			if (!baseprojectile)
				break;

			auto wep_class_name = *(const char**)(*(uintptr_t*)(uintptr_t)baseprojectile + 0x10);
			if (*(int*)(wep_class_name + 4) == 'eleM' || *(int*)(wep_class_name) == 'ddaP')
				break;

			base_projectile* projectile_list = *reinterpret_cast<base_projectile**>(
				*reinterpret_cast<uintptr_t*>((uintptr_t)baseprojectile + 0x358) + 0x10); //createdProjectiles;

			esp::matrix = unity::get_view_matrix();
			auto camera_pos = unity::get_camera_pos();

			aim_target target = local_player->get_aimbot_target(camera_pos);

			uintptr_t shoot_list = *(uintptr_t*)(*(uintptr_t*)(projectileShoot + 0x18) + 0x10);

			auto size = *(int*)(*(uintptr_t*)(projectileShoot + 0x18) + 0x18);

			Vector aimbot_velocity;


			Vector aim_angle;
			Vector rpc_position;


			for (int i = 0; i < size; i++) {
				auto projectile = *(uintptr_t*)(shoot_list + 0x20 + i * 0x8);

				rpc_position = *reinterpret_cast<Vector*>(projectile + 0x18);
				auto original_vel = *reinterpret_cast<Vector*>(projectile + 0x24);
				
				if (target.player && target.visible && !target.teammate) {
					typedef Vector(__stdcall* BodyF)(DWORD64);
					aimbot_velocity = ((BodyF)(mem::game_assembly_base + O::PlayerEyes::BodyForward))(safe_read(local_player + O::BasePlayer::eyes, DWORD64));
					Prediction(rpc_position, target.pos, target.velocity, esp::GetBulletSpeed(), esp::GetGravity(ammo));
					aim_angle = target.pos - rpc_position;
					aimbot_velocity = (aim_angle).Normalized() * esp::GetBulletSpeed();

					*reinterpret_cast<Vector*>(projectile + 0x24) = aimbot_velocity;
				}
			}

			for (int i = 0; i < projectile_list->get_size(); i++) {
				auto projectile = *(base_projectile**)((uintptr_t)projectile_list + 0x20 + i * 0x8);

				if (!projectile)
					continue;
				if (!keybinds::psilentb || unity::GetKey(keybinds::psilentk)) {
					if (settings::weapon::psilent) {
						if (target.player && !target.teammate) {
							if (!settings::weapon::psilentvis || target.visible) {
								projectile->set_current_velocity(aimbot_velocity);
								projectile->set_Initial_Velocity(aimbot_velocity);
							}
						}
					}
				}

				
				if (settings::weapon::mods) {

					auto ItemModProjectile = projectile->get_item_mod_projectile();

					ItemModProjectile->projectileSpread() = 0;
					ItemModProjectile->projectileVelocitySpread() = 0;
				}

				if (settings::weapon::thick_bullet)
					projectile->set_projectile_thickness(settings::weapon::thickness);
				else
					projectile->set_projectile_thickness(projectile->thickness);
				

			}
		} while (0);

		reinterpret_cast<void (*)(int64_t, int64_t, int64_t, int64_t, int64_t)>(hooks::orig::serverrpc_projectileshoot)(rcx, rdx, r9, projectileShoot, arg5);
	}

	bool is_lagging;

	bool flying = false, is_speeding = false;



	float nextActionTime = 0, period = 1.4721;



	uintptr_t client_entities;

	void hk_dofixedupdate(playerwalkmovement * base_movement, modelstate * modelstate) {
		float speed = (safe_read(base_movement + 0x146, bool) /*swim*/ || safe_read(base_movement + 0x44, float) /* crouch */ > 0.5f) ? 1.7f : (safe_read(base_movement + 0x148, bool) /*jump*/ ? 8.f : 5.5f);// playermovmen
		Vector vel = safe_read(base_movement + 0x34, Vector);
		speed = max(speed, vel.Length());
		if (settings::misc::always_sprint) {
			float len = vel.Length();
			if (len > 0.f) {
				vel = Vector(vel.x / len * speed, vel.y, vel.z / len * speed);
				safe_write(base_movement + 0x34, vel, Vector);
			}
			modelstate->set_flag(rust::classes::ModelState_Flag::Sprinting);
		}

		if (settings::misc::AutoFarmBot) {

			if (settings::visuals::stone_ore)
			{
				Vector vel = safe_read(base_movement + 0x34, Vector);
				AimResult closest = AimResult::get_closest_object(local_player->get_bone_transform(48)->get_bone_position(), _("stone-ore.prefab"));
				if (closest.valid) {
					Vector direction = (closest.pos - local_player->get_bone_transform(48)->get_bone_position()).Normalized() * speed;
					safe_write(base_movement + 0x34, Vector(direction.x, vel.y, direction.z), Vector);
				}
			}
			else if(settings::visuals::metal_ore)
			{
				Vector vel = safe_read(base_movement + 0x34, Vector);
				AimResult closest = AimResult::get_closest_object(local_player->get_bone_transform(48)->get_bone_position(), _("metal-ore.prefab"));
				if (closest.valid) {
					Vector direction = (closest.pos - local_player->get_bone_transform(48)->get_bone_position()).Normalized() * speed;
					safe_write(base_movement + 0x34, Vector(direction.x, vel.y, direction.z), Vector);
				}
			}
			else if (settings::visuals::sulfur_ore)
			{
				Vector vel = safe_read(base_movement + 0x34, Vector);
				AimResult closest = AimResult::get_closest_object(local_player->get_bone_transform(48)->get_bone_position(), _("sulfur-ore.prefab"));
				if (closest.valid) {
					Vector direction = (closest.pos - local_player->get_bone_transform(48)->get_bone_position()).Normalized() * speed;
					safe_write(base_movement + 0x34, Vector(direction.x, vel.y, direction.z), Vector);
				}
			}

		}
		orig::DoFixedUpdate(base_movement, modelstate);
	}

	void hk_blocksprint(base_player* player, float duration) {
		if (!settings::misc::always_sprint && settings::misc::Movement)
			return hooks::orig::blocksprint(player, duration);

		return;
	}
	
	void hk_FakeVisUpdateUsingCulling(void* baseplayer, float dist, bool visibility = false)
	{
		if (settings::visuals::chams )
			return orig::VisUpdateUsingCulling(baseplayer, 300.f, true);

		return orig::VisUpdateUsingCulling(baseplayer, dist, visibility);
	}



	void hk_playerwalkmovement_ClientInput(playerwalkmovement* player_walk_movement, uintptr_t inputstate, modelstate* model_state) {
		orig::playerwalkmovement_client_input(player_walk_movement, inputstate, model_state);

		set_sprinting(model_state, true);

		flying = player_walk_movement->get_flying();

		if (!keybinds::silentwalkb || unity::GetKey(keybinds::silentwalkk)) {
			if (settings::misc::silentwalk) {
				set_onLadder(model_state, true);
			}
		}
		model_state->remove_flag(rust::classes::ModelState_Flag::Flying);
	}

	uintptr_t do_fixed_update_ptr, client_input_ptr;


	float flyhackDistanceVertical = 0.f;
	float flyhackDistanceHorizontal = 0.f;
	float flyhackPauseTime;
	void TestFly() {
		flyhackPauseTime = max(0.f, flyhackPauseTime - get_deltaTime());
		bool inAir = false;
		float radius = local_player->GetRadius();
		float height = local_player->GetHeight(false);
		Vector vector = (local_player->lastSentTick()->position() + local_player->get_player_model2()->position()) * 0.5f;
		Vector vector2 = vector + Vector(0.f, radius - 2.f, 0.f);
		Vector vector4 = vector + Vector(0.f, height - radius, 0.f);
		float radius2 = radius - 0.05f;
		bool capsule = CheckCapsule(vector2, vector4, radius2, 1503731969, rust::classes::QueryTriggerInteraction::Ignore);
		inAir = !capsule;
		if (inAir) {
			bool flag = false;

			Vector vector4 = local_player->get_player_model2()->position() - local_player->lastSentTick()->position();
			float num3 = abs(vector4.y);
			float num4 = vector4.Magnitude2D();
			if (vector4.y >= 0.f) {
				flyhackDistanceVertical += vector4.y;
				flag = true;
			}
			if (num3 < num4) {
				flyhackDistanceHorizontal += num4;
				flag = true;
			}
			if (flag) {
				float num5 = max((flyhackPauseTime > 0.f) ? 10 : 1.5, 0.f);
				float num6 = local_player->GetJumpHeight() + num5;
				float num7 = max((flyhackPauseTime > 0.f) ? 10 : 1.5, 0.f);
				float num8 = 5.f + num7;
			}
		}
		else {
			flyhackDistanceHorizontal = 0.f;
			flyhackDistanceVertical = 0.f;
		}
	}



	void hk_baseplayer_ClientInput(base_player* baseplayer, input_state* state) {
		if (!do_fixed_update_ptr)
			do_fixed_update_ptr = mem::hook_virtual_function(_("PlayerWalkMovement"), _("DoFixedUpdate"), &hk_dofixedupdate);
		
		if(!client_input_ptr)
			client_input_ptr = mem::hook_virtual_function(_("PlayerWalkMovement"), _("ClientInput"), &hk_playerwalkmovement_ClientInput);



		static uintptr_t* serverrpc_projecshoot;
		if (!serverrpc_projecshoot) {
			auto method_serverrpc_projecshoot = *reinterpret_cast<uintptr_t*>(hooks::serverrpc_projecileshoot);

			if (method_serverrpc_projecshoot) {
				serverrpc_projecshoot = **(uintptr_t***)(method_serverrpc_projecshoot + 0x30);

				hooks::orig::serverrpc_projectileshoot = *serverrpc_projecshoot;
		
				*serverrpc_projecshoot = reinterpret_cast<uintptr_t>(&hooks::hk_serverrpc_projectileshoot);
			}
		}



		if (baseplayer) {

			if (settings::gongetflyhack) {
				TestFly();
				float num5 = max((flyhackPauseTime > 0.f) ? 10 : 1.5, 0.f);
				float num6 = 3.f + num5;
				settings::max_flyhack = num6;
				if (flyhackDistanceVertical <= num6) {
					settings::flyhack = flyhackDistanceVertical;
				}

				float num7 = max((flyhackPauseTime > 0.f) ? 10 : 1.5, 0.f);
				float num8 = 6.f + num7;
				settings::max_hor_flyhack = num8;
				if (flyhackDistanceHorizontal <= num8) {
					settings::hor_flyhack = flyhackDistanceHorizontal;
				}
				if (flyhackDistanceVertical > num6) {
					baseplayer->get_movement2()->groundAngle(Vector(0,0,0));
					baseplayer->get_movement2()->groundAngleNew228(Vector(0, 0, 0));
					baseplayer->get_movement2()->TargetMovementk__BackingField(Vector(0, 0, 0));
				}

				if (flyhackDistanceHorizontal > num8) {
					baseplayer->get_movement2()->groundAngle(Vector(0, 0, 0));
					baseplayer->get_movement2()->groundAngleNew228(Vector(0, 0, 0));
					baseplayer->get_movement2()->TargetMovementk__BackingField(Vector(0, 0, 0));
				}
			}

			



			auto baseprojectile = local_player->get_active_weapon();
			DWORD64 active = baseprojectile->entity();
			if (unity::GetKey(rust::classes::KeyCode::Mouse4)) {
				reinterpret_cast<void(*)(uintptr_t, rust::classes::Signal, rust::classes::string)>(mem::game_assembly_base + 8989088)(active, rust::classes::Signal::Attack, rust::classes::string(_(L"")));//public void SendSignalBroadcast(BaseEntity.Signal signal, string arg = "") { }
			}

			if (settings::misc::attack_on_mountables) {
				auto mountable = baseplayer->get_mountable();
				if (mountable)
					mountable->canwielditem() = true;
			}

			bool kyslol = false;

			if (settings::misc::TakeFallDamage && unity::GetKey(rust::classes::KeyCode::P)) {

					OnLand(baseplayer, -8.0001f - 100);
			}



			if (settings::misc::admin_mode)
				baseplayer->set_admin_flag(rust::classes::PlayerFlags::IsAdmin);

			if (settings::misc::spiderman && settings::misc::Movement) {
				baseplayer->SpiderMan();

			}

			if (settings::misc::playerfovtoggle) {
				baseplayer->fov();

			}

		
				
			baseplayer->todsky();



			if (!keybinds::fakelagb || unity::GetKey(keybinds::fakelagk)) {
				if (!is_lagging && !flying && settings::misc::fake_lag && !is_speeding) {
					baseplayer->set_client_tick_interval(0.5f);
					is_lagging = true;
				}
			}
			else if (is_lagging && flying || is_lagging && is_speeding) {
				local_player->set_client_tick_interval(0.03f);
				is_lagging = false;
			}
			else if (is_lagging && !settings::misc::fake_lag) {
				local_player->set_client_tick_interval(0.03f);
				is_lagging = false;
			}


			if (auto movement = baseplayer->get_movement()) {
				if (settings::misc::spiderman) {
					movement->set_ground_angles_new(0);

				}

			}

			if (settings::misc::eyeoffset) {
				baseplayer->Giraffe();

			}

			if (auto movement = baseplayer->get_movement()) {
				if (settings::misc::infinite_jump && settings::misc::Movement) {
					movement->set_land_time(0);
					movement->set_jump_time(0);
					movement->set_ground_time(100000);
				}

				if (settings::misc::gravity && settings::misc::Movement)
					movement->set_gravity_multiplier(1.75f);
				else
					movement->set_gravity_multiplier(2.35f);

				if (settings::misc::always_sprint && settings::misc::Movement) {
					if (auto modelstate = baseplayer->get_model_state()) {
						modelstate->set_flag(rust::classes::ModelState_Flag::OnGround);
						mem::write<float>((uint64_t)movement + 0x4C, 1); //private float <Grounded>k__BackingField; // 0x4C
					}
				}
			}

			auto item = baseplayer->get_active_weapon();


			if (!keybinds::speedhackb || unity::GetKey(keybinds::speedhackk)) {
				if (settings::misc::speedhack && settings::misc::Movement) {
					set_timeScale(settings::misc::speedhackspeed);
					is_speeding = true;
				}
			}



			else if (!keybinds::speedkeyb || unity::GetKey(rust::classes::KeyCode::Mouse0)) {
				if (settings::weapon::fastshoot) {
					set_timeScale(1.2);
					is_speeding = true;
				}
			}
			else {
				set_timeScale(1);
				is_speeding = false;
			}

			if (item) {
				auto baseprojectile = item->get_base_projetile();
				if (baseprojectile) {
					auto wep_class_name = *(const char**)(*(uintptr_t*)(uintptr_t)baseprojectile + 0x10);
					if (!(*(int*)(wep_class_name + 4) == 'eleM' && *(int*)(wep_class_name) == 'esaB')) {
					
						if (*(int*)(wep_class_name) == 'esaB' && *(int*)(wep_class_name + 4) == 'jorP' || *(int*)(wep_class_name) == 'nilF') {
							if (item->is_weapon()) {
								const auto item_id = item->get_item_definition_id();	
								DWORD64 heldentity = item->entity();
							

								switch (item_id) {
								case -75944661:
									if (settings::weapon::eoka) {
										mem::write<bool>((uint64_t)baseprojectile + 0x370, true);
										mem::write<float>((uint64_t)baseprojectile + 0x360, 1.f);
									}					
									break;
								default:
									if (settings::weapon::weapon_removals) {	
									
										if (settings::weapon::automatic)
											baseprojectile->is_automatic() = true;
										if (settings::weapon::nospread)
											baseprojectile->set_no_spread();
										if (settings::weapon::norecoil)
											baseprojectile->set_recoil(0, 0, 0, 0);
										if (settings::weapon::nosway)
											baseprojectile->set_no_sway();
										}
									break;
									
								}
							}
						}
					}
				}
			}


			unity::IgnoreLayerCollision(rust::classes::layer::PlayerMovement, rust::classes::layer::Water, !settings::misc::no_playercollision);
			unity::IgnoreLayerCollision(rust::classes::layer::PlayerMovement, rust::classes::layer::Tree, settings::misc::no_playercollision);
			unity::IgnoreLayerCollision(rust::classes::layer::PlayerMovement, rust::classes::layer::AI, settings::misc::no_playercollision);

			draw_get();

			auto tick_time = baseplayer->get_last_sent_ticket_time();
			if (tick_time > gui::tick_time_when_called + 10) {
				unity::camera = unity::get_main_camera();
				gui::tick_time_when_called = tick_time;
			}
		}

		orig::baseplayer_client_input(baseplayer, state);

		auto model_state = baseplayer->get_model_state();

		

		if (settings::misc::spinbot) {
			state->set_aim_angles(Vector(100, my_rand() % 999 + -999, 100));
		}
	}
}