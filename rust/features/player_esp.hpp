#pragma once
#include <array>
#include <cstdint>
#include "../../memory/il2cpp.hpp"
#include "../../settings.hpp"
#include "../classes.hpp"
#include "../rust.hpp"







namespace gui222
{
	class Color {
	public:
		float r;
		float g;
		float b;
		float a;

		Color()
		{
			r = 0;
			g = 0;
			b = 0;
			a = 0;
		}

		Color(float r, float g, float b, float a)
		{
			this->r = r;
			this->g = g;
			this->b = b;
			this->a = a;
		}

		Color GetUnityColor()
		{
			return Color(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
		}
	};

}



namespace esp {

	uintptr_t client_entities;
	base_player* TargetAimBotPlayer = nullptr;
	VMatrix matrix;

	struct bounds_t {
		float left, right, top, bottom;
	};

	struct rust_str
	{
		char zpad[128];
	};

	bool out_w2s(const Vector& position, vector2& screen_pos) {
		if (!matrix.m) {
			return false;
		}

		vector2 out;
		const auto temp = matrix.transpose();

		auto translation_vector = Vector{ temp[3][0], temp[3][1], temp[3][2] };
		auto up = Vector{ temp[1][0], temp[1][1], temp[1][2] };
		auto right = Vector{ temp[0][0], temp[0][1], temp[0][2] };

		float w = translation_vector.Dot(position) + temp[3][3];

		if (w < 0.098f) {
			return false;
		}

		float x = up.Dot(position) + temp._24;
		float y = right.Dot(position) + temp._14;

		out.x = (static_cast<float>(unity::get_width()) / 2) * (1 + y / w);
		out.y = (static_cast<float>(unity::get_height()) / 2) * (1 - x / w);

		screen_pos = out;

		return true;
	}

	inline float GetFov(base_player* Entity)
	{

		vector2 ScreenPos;
		if (!out_w2s(Entity->get_bone_transform(48)->get_bone_position(), ScreenPos)) return 1000.f;
		return Calc2D_Dist_2(vector2(unity::get_width() / 2, unity::get_height() / 2), ScreenPos);
	}


	inline float GetGravity(const int ammoid)
	{
		switch (ammoid)
		{
		case 14241751: //fire arrow
			return 1.f;
		case -1234735557: //arrow normal
			return 0.75f;
		case 215754713: //arrow bone
			return 0.75f;
		case -1023065463: //hv arrow
			return 0.5f;
		case -2097376851: //nails
			return 0.75f;
		case -1321651331: //5.56 exp
			return 1.25f;
		default:
			return 1.f;
		}
	}

	float GetBulletSpeed()
	{
		switch (local_player->get_active_weapon()->GetID() + local_player->get_active_weapon()->LoadedAmmo())
		{
		case 377132179: // bolt 5.56
			return 656.f;
		case 3300368691: // bolt 5.56 hv
			return 788.f;
		case 266647104: // bolt 5.56 inc
			return 394.f;
		case 2193765803: // bolt 5.56 ex
			return 394.f;
		case -1989533551: // l96 5.56
			return 1125.f;
		case 933702961: // l96 5.56 hv
			return 1350.f;
		case -2100018626: // l96 5.56 inc
			return 675.f;
		case -172899927: // l96 5.56 ex
			return 675.f;
		case -3280745144: // l96 5.56
			return 488.f;
		case -357508632: // l96 5.56 hv
			return 585.f;
		case -3391230219: // l96 5.56 inc
			return 293.f;
		case -1464111520: // l96 5.56 ex
			return 293.f;
		case 2104286852: // mp5a4 5.56
			return  240.f;
		case -372837868: // mp5a4 5.56 hv
			return 320.f;
		case 1370543430: // mp5a4 5.56 inc
			return 180.f;
		case -1182964415: //m39 5 56
			return 469.f;
		case  1740272097: //m39 hv
			return 563.f;
		case -1293449490: //m39 inc
			return 281.f;
		case 633669209: //m39 exp
			return 281.f;
		case -3023721433: //lr300 5 56
			return 375.f;
		case -100484921: //lr300 hv
			return 450.f;
		case -3134206508: //lr300 inc
			return 225.f;
		case -1207087809: //lr300 exp
			return 225.f;
		case -2116029401: //sar 5 56
			return 375.f;
		case 807207111: //sar hv
			return 450.f;
		case -2226514476: //sar inc
			return 225.f;
		case -299395777: //sar exp
			return 225.f;
		case 334613342: //ak 5 56
			return 375.f;
		case 3257849854: //ak hv
			return 450.f;
		case 224128267: //ak inc
			return 225.f;
		case 2151246966: //ak exp
			return 225.f;

		case 2582410286: // smg 5.56
			return  240.f;
		case 105285566: // smg 5.56 hv
			return 320.f;
		case 1848666864: // smg 5.56 inc
			return 180.f;
		case -972644648: //thompson
			return 300.f;
		case -1867233915: //thompson hv
			return 400.f;
		case -1706388070: //thompson inc
			return 225.f;
		case 1435640691: //revolver
			return 300.f;
		case -1041484029: //revolver hv
			return 400.f;
		case 701897269: //revolver inc
			return 225.f;
		case 2159699936: //python
			return 300.f;
		case -317424784: //python hv
			return 400.f;
		case 1425956514: //python inc
			return 225.f;
		case 1604605561: //semi-pistol
			return 300.f;
		case -872519159: //semi-pistol hv
			return 400.f;
		case 870862139: //semi-pistol inc
			return 225.f;
		case -66834942: //m92
			return 300.f;
		case -2543959662: //m92 hv
			return 400.f;
		case -800578364: //m92 inc
			return 225.f;
		case 730496837: //Crossbow
			return 75.f;
		case -1008823712: //Crossbow hv
			return 120.f;
		case 229996464: //Crossbow bone
			return 68.f;
		case 1979474145: //Crossbow fire
			return 60.f;

		case -350311508: //Compound Bow
			return 55.f;
		case 1907489512: //Compound Bow hv
			return 80.f;
		case 1100178762: //Compound Bow bone
			return 45.f;
		case 1443579727: //Compound Bow fire
			return 40.f;
		case 208844170: //Hunting Bow
			return 50.f;
		case 420514264: //Hunting Bow hv
			return 80.f;
		case 1659334440: //Hunting Bow bone
			return 45.f;
		case 1457821478: //Hunting Bow fire
			return 40.f;
		case -143473650: //Nailgun
			return 45.f;
		default:
			return 100.f;
		}
	}

	

	Vector ClosestPoint(base_player* player, Vector vec) {
		typedef Vector(__stdcall* CPoint)(base_player*, Vector);
		Vector result = ((CPoint)(mem::game_assembly_base + O::BaseEntity::ClosestPoint))(player, vec);
		return result;
	}



	inline Vector Prediction(Vector LP_Pos, base_player* Player)
	{
		auto active = local_player->get_active_weapon();
		const int ammo = active->LoadedAmmo();
		Vector BonePos = Player->get_bone_transform(48)->get_bone_position();
		const float Dist = Distance3D(LP_Pos, BonePos);
		if (Dist > 0.001f) {
			float speed = GetBulletSpeed();
			if (speed == NULL)
				speed = 250.f;
			const float BulletTime = Dist / speed;
			const Vector vel = Player->GetVelocity();
			const Vector PredictVel = vel * BulletTime * 0.75f;
			BonePos += PredictVel;
			const float gravity = GetGravity(ammo);
			BonePos.y += (4.905f * BulletTime * BulletTime) * gravity;
		}

		return BonePos;
	}

	inline void Normalize(float& Yaw, float& Pitch)
	{
		if (Pitch < -89)
			Pitch = -89;
		else if (Pitch > 89)
			Pitch = 89;
		if (Yaw < -360)
			Yaw += 360;
		else if (Yaw > 360)
			Yaw -= 360;
	}


	inline void Target(base_player* player)
	{
		const auto Local = local_player->get_bone_transform(46)->get_bone_position();
		Vector PlayerPos;
		if (settings::Prediction)
		{
			PlayerPos = Prediction(Local, player);
		}
		else
		{
			PlayerPos = player->get_bone_transform(46)->get_bone_position();
		}
		auto Offset = CalcAngle(Local, PlayerPos) - local_player->GetVA();
		Normalize(Offset.y, Offset.x);
		const auto RecoilToAngles = local_player->GetRA();
		auto AngleToAim = local_player->GetVA() + Offset;
		if (settings::RecoilControlSystem)
		{
			AngleToAim = AngleToAim - RecoilToAngles;
		}
		Normalize(AngleToAim.y, AngleToAim.x);
		local_player->SetVA(AngleToAim);
	}

	void draw_heli(float x, float y, float w, float h);

	void draw_tool_cupboard(vector2 w2s_position, wchar_t* label, gui222::Color color, rust::list<PlayerNameID*>* authorizedPlayers_list);

	void miscvis(DWORD64 ObjectClass, char* buff, bool boolean, bool showDistance, float drawDistance, const char* substring, const wchar_t* targettext, gui222::Color Col);

	void draw_item(vector2 w2s_position, wchar_t* label, gui222::Color color, wchar_t* name = _(L""));

	void draw_player(base_player* player);

	void draw_name(Vector position, wchar_t* name);

	void RadarPlayer(base_player* player);

	void draw_weapon_icon(weapon* item, vector2 w2s_position);

	uintptr_t shader;



	void ESPLoop() {

		float FOV = 1000000.f;
		base_player* AimEntity = 0;
		bool LP_isValid = false;
		uintptr_t ClientEntities = il2cpp::value(_("BaseNetworkable"), _("clientEntities"), false);
		uintptr_t ClientEntities_list = mem::read<uintptr_t>(ClientEntities + 0x10);
		uintptr_t ClientEntities_values = mem::read<uintptr_t>(ClientEntities_list + 0x28);
		int EntityCount = mem::read<int>(ClientEntities_values + 0x10);
		if (!EntityCount) return;
		uintptr_t EntityBuffer = mem::read<uintptr_t>(ClientEntities_values + 0x18);
		weapon* weapon_1 = local_player->get_active_weapon();
		uintptr_t active = mem::read<uintptr_t>((uintptr_t)weapon_1 + O::Item::heldEntity);
		char* classname = weapon_1->ClassName();
		bool weaponmelee = weapon_1 && classname && (m_strstr(classname, _("BaseMelee")) || m_strstr(classname, _("Jackhammer")));
		for (int i = 0; i < EntityCount; i++) {
			uintptr_t Entity = mem::read<uintptr_t>(EntityBuffer + 0x20 + (i * 0x8)); if (Entity <= 100000) continue;
			uintptr_t Object = mem::read<uintptr_t>(Entity + 0x10); if (Object <= 100000) continue;
			uintptr_t ObjectClass = mem::read<uintptr_t>(Object + 0x30); if (ObjectClass <= 100000) continue;
			pUncStr name = mem::read<pUncStr>(ObjectClass + 0x60); if (!name) continue;
			char* buff = name->stub;
			WORD tag = *reinterpret_cast<WORD*>(ObjectClass + 0x54);

			DWORD64 ent = safe_read(Object + 0x28, UINT64);

			if (m_strstr(buff, _("Local"))) {
				base_player* Player = *reinterpret_cast<base_player**>(Object + 0x28);
				if (!*reinterpret_cast<uintptr_t*>(Player + 0x50) || *reinterpret_cast<bool*>(Player + 0x18) || !*reinterpret_cast<uintptr_t*>(Player + playerModel)) continue;
				if (Player != local_player) {}
				Vector pos = Player->Position();
				local_player = Player;
				LP_isValid = true;
			}


			else if (m_strstr(buff, _("player.prefab")))
			{
				base_player* Player = mem::read<base_player*>(Object + 0x28);
				if (!*reinterpret_cast<uintptr_t*>(Player + 0x50) || *reinterpret_cast<bool*>(Player + 0x18) || !*reinterpret_cast<uintptr_t*>(Player + 0x4C0)) continue;
				if (!Player->IsValid()) continue;
				esp::matrix = unity::get_view_matrix();
				if (Player->is_sleeping() && !settings::visuals::sleeper_esp) continue;
				if (get_IsNpc(Player->get_player_model())) {if (!settings::visuals::npc_esp) continue; }
				if (settings::weapon::silent_melee && weaponmelee) {
					AimResult target = TargetMeleeTest((base_player*)ent, active);
					DoMeleeAttack(target, active, true);
				}
	
				draw_player(Player);
				RadarPlayer(Player);

				float CurFOV = 9999999.f;
				if (settings::visuals::chams) {
					base_player* Player = mem::read<base_player*>(Object + 0x28);
					auto _multiMesh = mem::read<uintptr_t>(Player->get_player_model() + 0x2D0); //SkinnedMultiMesh _multiMesh;
					if (_multiMesh) {
						auto render = get_Renderers(_multiMesh);

						for (int i = 0; i < render->get_size(); i++) {

							auto renderer = render->get_value(i);

							if (renderer) {
								auto material = get_material(renderer);
								if (material) {
									if (!shader)
										shader = Find(_(L"Hidden/Internal-Colored"));
									unity::set_shader(material, shader);

									SetColor(material, _(L"_Color"), col(1, 0, 0, 1));
								}
							}
						}
					}
				}


			

				if (LP_isValid)
				{
					if ((FOV > (CurFOV = GetFov(Player)))) {
						if (CurFOV <= settings::misc::playerfov) {
							aim_target target;
							FOV = CurFOV; AimEntity = Player; target.player = Player;
							if (settings::aimbot)
							{
								const float Distance = Distance3D(local_player->get_bone_transform(48)->get_bone_position(), Player->get_bone_transform(48)->get_bone_position());
								if (Distance > settings::AimLimitDistance)
									return;
								if (unity::GetKey(rust::classes::KeyCode::Mouse1))
								{
									Target(Player);
								}
							}
						}
					}

				}
				else local_player = nullptr;
			}
			else if (settings::misc::AutoFarmTree && weaponmelee && (m_strstr((char*)safe_read(safe_read(ent, DWORD64) + 0x10, DWORD64), _("TreeEntity")))) {
				char* name = (char*)safe_read(safe_read(ent, DWORD64) + 0x10, DWORD64);
				UINT64 gameObject = safe_read(ObjectClass + 0x30, UINT64);
				UINT64 Trans = safe_read(gameObject + 0x8, UINT64);
				UINT64 Vec = safe_read(Trans + 0x38, UINT64);
				Vector pos = safe_read(Vec + 0x90, Vector); //TODO Hit tree marker
				Vector local = ClosestPoint(local_player, pos);
				if (Calc3D_Dist(local, pos) >= 3.f) { continue; }
				AimResult target = AimResult();
				target.valid = true;
				target.pos = pos;
				target.entity = (base_player*)ent;
				DoMeleeAttack(target, active, false);
			}
			else if (settings::misc::AutoFarmOre && weaponmelee && (m_strstr((char*)safe_read(safe_read(ent, DWORD64) + 0x10, DWORD64), _("OreHotSpot")))) {
				char* name = (char*)safe_read(safe_read(ent, DWORD64) + 0x10, DWORD64);
				UINT64 gameObject = safe_read(ObjectClass + 0x30, UINT64);
				UINT64 Trans = safe_read(gameObject + 0x8, UINT64);
				UINT64 Vec = safe_read(Trans + 0x38, UINT64);
				Vector pos = safe_read(Vec + 0x90, Vector);
				typedef Vector(__stdcall* CPoint)(base_player*, Vector);
				Vector local = ((CPoint)(mem::game_assembly_base + O::BaseEntity::ClosestPoint))(local_player, pos);
				if (Calc3D_Dist(local, pos) >= 3.f) { continue; }
				AimResult target = AimResult();
				target.valid = true;
				target.pos = pos;
				target.entity = (base_player*)ent;
				DoMeleeAttack(target, active, false);
			}
			else if (settings::misc::AutoPickup && m_strstr(buff, _("/collectable/"))) {
				uintptr_t ent = *reinterpret_cast<uintptr_t*>(Object + 0x28);
				uintptr_t gameObject = *reinterpret_cast<uintptr_t*>(ObjectClass + 0x30);
				uintptr_t Trans = *reinterpret_cast<uintptr_t*>(gameObject + 0x8);
				uintptr_t Vec = *reinterpret_cast<uintptr_t*>(Trans + 0x38);
				Vector pos = *reinterpret_cast<Vector*>(Vec + 0x90);
				typedef Vector(__stdcall* CPoint)(base_player*, Vector);
				Vector local = ((CPoint)(mem::game_assembly_base + O::BaseEntity::ClosestPoint))(local_player, pos);
				if (Calc3D_Dist(local, pos) < 3.f) { PickupItem(ent); }
			}
			else if (settings::misc::DoorKnocker && m_strstr((char*)safe_read(safe_read(ent, DWORD64) + 0x10, DWORD64), _("Door"))) {
				UINT64 gameObject = safe_read(ObjectClass + 0x30, UINT64);
				UINT64 Trans = safe_read(gameObject + 0x8, UINT64);
				UINT64 Vec = safe_read(Trans + 0x38, UINT64);
				Vector pos = safe_read(Vec + 0x90, Vector);
				typedef Vector(__stdcall* CPoint)(base_player*, Vector);
				Vector local = ((CPoint)(mem::game_assembly_base + O::BaseEntity::ClosestPoint))(local_player, pos);
				if (ent && Calc3D_Dist(local, pos) < 3.f) { EbynMozga(ent); }
			}

			miscvis(ObjectClass, buff, settings::visuals::stone_ore, settings::visuals::showDistance, 300, _("stone-ore.prefab"), _(L"Stone-Ore"), gui222::Color(255, 255, 255, 255));
			miscvis(ObjectClass, buff, settings::visuals::sulfur_ore, settings::visuals::showDistance, 300, _("sulfur-ore.prefab"), _(L"Sulfur-ore"), gui222::Color(242, 228, 24, 255));
			miscvis(ObjectClass, buff, settings::visuals::metal_ore, settings::visuals::showDistance, 300, _("metal-ore.prefab"), _(L"Metal-ore"), gui222::Color(255,0,0,255));


		}

		return;
	}
}


