#pragma once
#include "../rust/unity.hpp"
#include "../rust/features/player_esp.hpp"
#include "../settings.hpp"
#include "../utils/string_format.h"
#include <windows.h>
#include <string>

#define rgba(r,g,b,a) gui222::Color(r / 255, g / 255, b / 255, a)
namespace gui {
	float menu_alpha;
	bool main_menu_open = false;
	struct CColor
	{
		float r;
		float g;
		float b;
		float a;

		CColor()
		{
			r = 0;
			g = 0;
			b = 0;
			a = 0;
		}

		CColor(float r, float g, float b, float a)
		{
			this->r = r;
			this->g = g;
			this->b = b;
			this->a = a;
		}

		CColor GetUnityColor()
		{
			return CColor(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
		}
	};
	namespace methods {
		static auto dont_destroy_on_load = reinterpret_cast<void(*)(uintptr_t target)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Object"), _("DontDestroyOnLoad"), 0, _(""), _("UnityEngine"))));

		static auto create_with_shader_fn = reinterpret_cast<void(*)(uintptr_t self, uintptr_t shader)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Material"), _("CreateWithShader"), 0, _(""), _("UnityEngine"))));
		
		static auto create = reinterpret_cast<void(*)(uintptr_t self, rust::classes::string shader)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GameObject"), _("Internal_CreateGameObject"), 0, _(""), _("UnityEngine"))));

		static auto AddComponent = reinterpret_cast<void(*)(uintptr_t shader)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GameObject"), _("AddComponent"), 0, _(""), _("UnityEngine"))));


		static auto get_whiteTexture = reinterpret_cast<uintptr_t(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Texture2D"), _("get_whiteTexture"), 0, _(""), _("UnityEngine"))));

		static auto get_skin = reinterpret_cast<uintptr_t(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("get_skin"), 0, _(""), _("UnityEngine"))));

		static auto set_fontSize = reinterpret_cast<void(*)(uintptr_t label, int size)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUIStyle"), _("set_fontSize"), -1, _(""), _("UnityEngine"))));

		static auto set_color = reinterpret_cast<void(*)(gui222::Color)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("set_color"), -1, _(""), _("UnityEngine"))));
		static auto Label = reinterpret_cast<void(*)(rust::classes::Rect position, uintptr_t content, uintptr_t style)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("Label"), 3, _("content"), _("UnityEngine"), 2)));

		static auto _Label = reinterpret_cast<void(*)(rust::classes::Rect, rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("Label"), 2, _("text"), _("UnityEngine"), 2)));
		static auto ptr_Label = reinterpret_cast<void(*)(rust::classes::Rect, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("Label"), 2, _("text"), _("UnityEngine"), 2)));

		static auto set_alignment = reinterpret_cast<void(*)(uintptr_t label, uintptr_t value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUIStyle"), _("set_alignment"), -1, _(""), _("UnityEngine"))));

		static auto get_current = reinterpret_cast<uintptr_t(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Event"), _("get_current"), 0, _(""), _("UnityEngine"))));

		static auto gui_content_temp = reinterpret_cast<uintptr_t(*)(rust::classes::string*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUIContent"), _("Temp"), 1, _("t"), _("UnityEngine"), 1)));

		static auto gui_content_temp_ptr = reinterpret_cast<uintptr_t(*)(uintptr_t*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUIContent"), _("Temp"), 1, _("t"), _("UnityEngine"), 1)));

		static auto set_skin = reinterpret_cast<void(*)(uintptr_t skin)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("set_skin"), 0, _(""), _("UnityEngine"))));

		static auto get_type = reinterpret_cast<rust::classes::EventType(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Event"), _("get_type"), 0, _(""), _("UnityEngine"))));

		static auto LoadAllAssets = reinterpret_cast<uintptr_t(*)(uintptr_t bundle, uintptr_t type)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("AssetBundle"), _("LoadAllAssets"), 1, _("type"), _("UnityEngine"), 1)));

		static auto LoadFromFile = reinterpret_cast<uintptr_t(*)(rust::classes::string path)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("AssetBundle"), _("LoadFromFile"), 1, _("path"), _("UnityEngine"), 1)));

		static auto DrawTexture = reinterpret_cast<void (*)(rust::classes::Rect, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("DrawTexture"), 2, _("image"), _("UnityEngine"), 2)));

		static auto Box = reinterpret_cast<void (*)(rust::classes::Rect, rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("Box"), 2, _("text"), _("UnityEngine"), 2)));

		static auto DrawLine = reinterpret_cast<void (*)(Vector, Vector, gui222::Color)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Debug"), _("DrawLine"), 3, _("color"), _("UnityEngine"), 3)));

		static auto set_gizmos_color = reinterpret_cast<void(*)(gui222::Color)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Gizmos"), _("set_color"), -1, _(""), _("UnityEngine"))));

		static auto HorizontalSlider = reinterpret_cast<float(*)(rust::classes::Rect position, float value, float leftValue, float rightValue)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("HorizontalSlider"), 4, _(""), _("UnityEngine"))));

		static auto PushMatrix = reinterpret_cast<void(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GL"), _("PushMatrix"), 0, _(""), _("UnityEngine"))));

		static auto SetPass = reinterpret_cast<bool(*)(uintptr_t xui, int pass)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Material"), _("SetPass"), 0, _(""), _("UnityEngine"))));

		static auto Begin = reinterpret_cast<void(*)(int mode)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GL"), _("Begin"), 0, _(""), _("UnityEngine"))));

		static auto Color = reinterpret_cast<void(*)(gui222::Color color)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GL"), _("Color"), 0, _(""), _("UnityEngine"))));

		static auto Vertex = reinterpret_cast<void(*)(Vector v)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GL"), _("Vertex"), 0, _(""), _("UnityEngine"))));

		static auto Vertex2 = reinterpret_cast<void(*)(float, float, float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GL"), _("Vertex3"), 0, _(""), _("UnityEngine"))));

		static auto End = reinterpret_cast<void(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GL"), _("End"), 0, _(""), _("UnityEngine"))));

		static auto PopMatrix = reinterpret_cast<void(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GL"), _("PopMatrix"), 0, _(""), _("UnityEngine"))));


		static auto Line = reinterpret_cast<void (*)(Vector, Vector, col, float, bool, bool)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("DDraw"), _("Line"), 1, _(""), _("UnityEngine"))));

		static auto add_component = reinterpret_cast<void(*)(uintptr_t self, uintptr_t componentType)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GameObject"), _("Internal_AddComponentWithType"), 0, _(""), _("UnityEngine"))));
	}

	uintptr_t white_texture;

	void init_gui() {
		methods::PopMatrix = reinterpret_cast<void(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GL"), _("PopMatrix"), 0, _(""), _("UnityEngine"))));

		methods::End = reinterpret_cast<void(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GL"), _("End"), 0, _(""), _("UnityEngine"))));

		methods::Vertex = reinterpret_cast<void(*)(Vector v)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GL"), _("Vertex"), 0, _(""), _("UnityEngine"))));

		methods::Vertex2 = reinterpret_cast<void(*)(float, float, float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GL"), _("Vertex3"), 0, _(""), _("UnityEngine"))));


		methods::Color = reinterpret_cast<void(*)(gui222::Color color)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GL"), _("Color"), 0, _(""), _("UnityEngine"))));

		methods::Begin = reinterpret_cast<void(*)(int mode)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GL"), _("Begin"), 0, _(""), _("UnityEngine"))));

		methods::SetPass = reinterpret_cast<bool(*)(uintptr_t xui, int pass)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Material"), _("SetPass"), 0, _(""), _("UnityEngine"))));

		methods::PushMatrix = reinterpret_cast<void(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GL"), _("PushMatrix"), 0, _(""), _("UnityEngine"))));

		methods::dont_destroy_on_load = reinterpret_cast<void(*)(uintptr_t target)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Object"), _("DontDestroyOnLoad"), 0, _(""), _("UnityEngine"))));

		methods::create_with_shader_fn = reinterpret_cast<void(*)(uintptr_t self, uintptr_t shader)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Material"), _("CreateWithShader"), 0, _(""), _("UnityEngine"))));

		methods::create = reinterpret_cast<void(*)(uintptr_t self, rust::classes::string shader)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GameObject"), _("Internal_CreateGameObject"), 0, _(""), _("UnityEngine"))));

		methods::AddComponent = reinterpret_cast<void(*)(uintptr_t shader)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GameObject"), _("AddComponent"), 0, _(""), _("UnityEngine"))));

		methods::ptr_Label = reinterpret_cast<void(*)(rust::classes::Rect, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("Label"), 2, _("text"), _("UnityEngine"), 2)));

		methods::gui_content_temp_ptr = reinterpret_cast<uintptr_t(*)(uintptr_t*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUIContent"), _("Temp"), 1, _("t"), _("UnityEngine"), 1)));

		methods::HorizontalSlider = reinterpret_cast<float(*)(rust::classes::Rect position, float value, float leftValue, float rightValue)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("HorizontalSlider"), 4, _(""), _("UnityEngine"))));

		methods::get_whiteTexture = reinterpret_cast<uintptr_t(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Texture2D"), _("get_whiteTexture"), 0, _(""), _("UnityEngine"))));

		methods::get_skin = reinterpret_cast<uintptr_t(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("get_skin"), 0, _(""), _("UnityEngine"))));

		methods::set_fontSize = reinterpret_cast<void(*)(uintptr_t label, int size)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUIStyle"), _("set_fontSize"), -1, _(""), _("UnityEngine"))));

		methods::set_color = reinterpret_cast<void(*)(gui222::Color)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("set_color"), -1, _(""), _("UnityEngine"))));

		methods::Label = reinterpret_cast<void(*)(rust::classes::Rect position, uintptr_t content, uintptr_t style)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("Label"), 3, _("content"), _("UnityEngine"), 2)));

		methods::_Label = reinterpret_cast<void(*)(rust::classes::Rect, rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("Label"), 2, _("text"), _("UnityEngine"), 2)));

		methods::set_alignment = reinterpret_cast<void(*)(uintptr_t label, uintptr_t value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUIStyle"), _("set_alignment"), -1, _(""), _("UnityEngine"))));

		methods::get_current = reinterpret_cast<uintptr_t(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Event"), _("get_current"), 0, _(""), _("UnityEngine"))));

		methods::gui_content_temp = reinterpret_cast<uintptr_t(*)(rust::classes::string*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUIContent"), _("Temp"), 1, _("t"), _("UnityEngine"), 1)));

		methods::set_skin = reinterpret_cast<void(*)(uintptr_t skin)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("set_skin"), 0, _(""), _("UnityEngine"))));

		methods::get_type = reinterpret_cast<rust::classes::EventType(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Event"), _("get_type"), 0, _(""), _("UnityEngine"))));

		methods::LoadAllAssets = reinterpret_cast<uintptr_t(*)(uintptr_t bundle, uintptr_t type)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("AssetBundle"), _("LoadAllAssets"), 1, _("type"), _("UnityEngine"), 1)));

		methods::LoadFromFile = reinterpret_cast<uintptr_t(*)(rust::classes::string path)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("AssetBundle"), _("LoadFromFile"), 1, _("path"), _("UnityEngine"), 1)));

		methods::DrawTexture = reinterpret_cast<void (*)(rust::classes::Rect, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("DrawTexture"), 2, _("image"), _("UnityEngine"), 2)));

		methods::Box = reinterpret_cast<void (*)(rust::classes::Rect, rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("Box"), 2, _("text"), _("UnityEngine"), 2)));

		methods::DrawLine = reinterpret_cast<void (*)(Vector, Vector, gui222::Color)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Debug"), _("DrawLine"), 3, _("color"), _("UnityEngine"), 3)));

		methods::set_gizmos_color = reinterpret_cast<void(*)(gui222::Color)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Gizmos"), _("set_color"), 1, _(""), _("UnityEngine"))));

		methods::Line = reinterpret_cast<void (*)(Vector, Vector, col, float, bool, bool)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("DDraw"), _("Line"), 6, _(""), _("UnityEngine"))));

		methods::add_component = reinterpret_cast<void(*)(uintptr_t self, uintptr_t componentType)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GameObject"), _("Internal_AddComponentWithType"), 0, _(""), _("UnityEngine"))));

		white_texture = methods::get_whiteTexture();
	}

	uintptr_t label, skin;
	bool open;
	bool InsertPressed;

	float tick_time_when_called;

	void outline_box(vector2 pos, vector2 size, gui222::Color clr)
	{
		methods::set_color(clr.GetUnityColor());
		methods::DrawTexture(rust::classes::Rect(pos.x, pos.y, 1, size.y), white_texture);
		methods::DrawTexture(rust::classes::Rect(pos.x + size.x, pos.y, 1, size.y), white_texture);
		methods::DrawTexture(rust::classes::Rect(pos.x, pos.y, size.x, 1), white_texture);
		methods::DrawTexture(rust::classes::Rect(pos.x, pos.y + size.y, size.x, 1), white_texture);
	}

	void horizontal_line(vector2 pos, float size, gui222::Color clr)
	{
		methods::set_color(clr.GetUnityColor());

		methods::DrawTexture(rust::classes::Rect(pos.x, pos.y, size, 1), white_texture);
	}

	void vertical_line(vector2 pos, float size, gui222::Color clr)
	{
		methods::set_color(clr.GetUnityColor());

		methods::DrawTexture(rust::classes::Rect(pos.x, pos.y, 1, size), white_texture);
	}

	void fill_box(rust::classes::Rect pos, gui222::Color clr)
	{
		methods::set_color(clr);
		methods::DrawTexture(pos, white_texture);
	}
	void fill_box2(rust::classes::Rect pos, gui222::Color clr)
	{
		methods::set_color(clr.GetUnityColor());
		methods::DrawTexture(pos, white_texture);
	}

	void init() {
		if (label && skin)
			return;

		skin = methods::get_skin();
		label = mem::read<uintptr_t>(skin + 0x38);

		methods::set_alignment(label, 0);
		methods::set_fontSize(label, 12);
		methods::set_color(gui222::Color(1, 1, 1, 1));
	}
	void Label22(rust::classes::Rect pos, rust::classes::string text, gui222::Color clr, bool centered = false, bool m_bOutlined = true, float size = 12) {

		uintptr_t content = methods::gui_content_temp(&text);

		      //prepare style	

		if (centered)
			methods::set_alignment(label, 0x4);
		else
			methods::set_alignment(label, 0x0);


		if (m_bOutlined)
		{
			methods::set_fontSize(label, size + 0.6);
			methods::set_color(gui222::Color(0, 0, 0, 255));
			methods::Label(rust::classes::Rect{ pos.x - 1, pos.y - 1, - 2, - 2 }, content, label);
			methods::Label(rust::classes::Rect{ pos.x + 1, pos.y + 1, + 3, + 3 }, content, label);
			methods::Label(rust::classes::Rect{ pos.x - 1, pos.y + 1, - 3, + 3 }, content, label);
			methods::Label(rust::classes::Rect{ pos.x + 1, pos.y - 1, + 3, - 3 }, content, label);
		}
		methods::set_fontSize(label, size);
		methods::set_color(clr);
		methods::Label(pos, content, label);
	}
	void DrawTextout(float x, float y, rust::classes::string m_szText, int m_iSize, gui222::Color m_Color, bool m_bOutlined, int m_iAlignment, bool m_bCentered, float m_flWidth, float m_flHeight)
	{
		uintptr_t content = methods::gui_content_temp(&m_szText);

		methods::set_fontSize(label, m_iSize);

		methods::set_alignment(label, m_iAlignment);

		float w = 0.0f;
		float h = 0.0f;

		if (!m_iAlignment && m_flHeight == 0.0f && m_flWidth == 0.0f)
		{
			methods::set_fontSize(label, m_iSize);
			if (m_bCentered)
				x -= w / 2.0f;
		}
		else
		{
			w = m_flWidth;
			h = m_flHeight;
		}

		if (m_bOutlined)
		{
			gui222::Color m_BlackColor = gui222::Color(0, 0, 0, 255);
			methods::set_color(m_BlackColor);
			methods::Label(rust::classes::Rect(x - 1, y - 1, w, h), content, label);
			methods::Label(rust::classes::Rect(x + 1, y + 1, w, h), content, label);
			methods::Label(rust::classes::Rect(x - 1, y + 1, w, h), content, label);
			methods::Label(rust::classes::Rect(x + 1, y - 1, w, h), content, label);
		}

		methods::set_color(m_Color);
		methods::Label(rust::classes::Rect(x, y, w, h), content, label);
	}
	void Text(float x, float y, float m_flWidth, float m_flHeight, rust::classes::string text, gui222::Color clr, bool centered = false, bool m_bOutlined = true, float size = 12) {

		uintptr_t content = methods::gui_content_temp(&text);

		//prepare style	

		if (centered)
			methods::set_alignment(label, 0x4);
		else
			methods::set_alignment(label, 0x0);

		float w = 0.0f;
		float h = 0.0f;

		if (!methods::set_alignment && m_flHeight == 0.0f && m_flWidth == 0.0f)
		{
			methods::set_fontSize(label, size);
			if (centered)
				x -= w / 2.0f;
		}
		else
		{
			w = m_flWidth;
			h = m_flHeight;
		}
		if (m_bOutlined)
		{
			methods::set_color(gui222::Color(0, 0, 0, 255));
			methods::Label(rust::classes::Rect{ x - 1, y - 1, w, h }, content, label);
			methods::Label(rust::classes::Rect{ x + 1, y + 1, w, h }, content, label);
			methods::Label(rust::classes::Rect{ x - 1, y + 1, w, h }, content, label);
			methods::Label(rust::classes::Rect{ x + 1, y - 1, w, h }, content, label);
		}
		
		methods::set_color(clr.GetUnityColor());
		methods::Label(rust::classes::Rect{ x, y, w, h }, content, label);
	}
	void Label(rust::classes::Rect pos, rust::classes::string text, gui222::Color clr, bool centered = false, float size = 12) {
		methods::set_color(clr);

		uintptr_t content = methods::gui_content_temp(&text);

		methods::set_fontSize(label, size);          //prepare style	

		if (centered)
			methods::set_alignment(label, 0x4);
		else
			methods::set_alignment(label, 0x0);
		methods::Label(pos, content, label);
	}

	void Label(rust::classes::Rect pos, uintptr_t text, gui222::Color clr, bool centered = false, float size = 12) {

		methods::set_color(clr);

		methods::set_fontSize(label, size);

		methods::ptr_Label(pos, text);
	}

	uintptr_t pizdec;
	void DrawFov(gui222::Color color, vector2 Center, float Radius) {
		pizdec = il2cpp::methods::object_new(il2cpp::init_class(_("Material"), _("UnityEngine")));
		methods::create_with_shader_fn(pizdec, Find(_(L"Hidden/Internal-Colored")));
		SetInt(pizdec, _(L"_SrcBlend"), 5);
		SetInt(pizdec, _(L"_DstBlend"), 10);
		SetInt(pizdec, _(L"_Cull"), 0);
		SetInt(pizdec, _(L"_ZWrite"), 0);
		gui::methods::dont_destroy_on_load(pizdec);

		gui::methods::PushMatrix();
		gui::methods::SetPass(pizdec, 0);
		gui::methods::Begin(1.5);
		gui::methods::Color(color.GetUnityColor());
		for (float num = 0.f; num < 6.2831855f; num += 0.05f) {
			gui::methods::Vertex(Vector(m_cos(num) * Radius + Center.x, m_sin(num) * Radius + Center.y, 0));
			gui::methods::Vertex(Vector(m_cos(num + 0.05f) * Radius + Center.x, m_sin(num + 0.05f) * Radius + Center.y, 0));
		}
		gui::methods::End();
		gui::methods::PopMatrix();
	}

	void OnKeyUp(rust::classes::KeyCode key) {
		if (key == rust::classes::KeyCode::Insert) {
			InsertPressed = false;
		}
	}

	bool m_bOpened;
	void OnKeyDown(rust::classes::KeyCode key) {
		if (!InsertPressed && key == rust::classes::KeyCode::Insert) {
			InsertPressed = true;
			open = !open;
			m_bOpened = !m_bOpened;
		}
	}

	int active_tab = 0;
	vector2 tab_size;
	int g_iCurrentTab = 0;
	void DrawHorizontalLine(float x, float y, float m_flWidth, gui222::Color m_Color)
	{
		methods::set_color(m_Color.GetUnityColor());
		methods::DrawTexture(rust::classes::Rect(x, y, m_flWidth, 1.0f), white_texture);
	}

	void HorizontalLine(vector2 pos, float size, gui222::Color clr)
	{
		methods::set_color(clr.GetUnityColor());
		methods::DrawTexture(rust::classes::Rect(pos.x, pos.y, size, 1), white_texture);
	}


	void DrawverticalLine(float x, float y, float m_flWidth, gui222::Color clr)
	{
		methods::set_color(clr.GetUnityColor());

		methods::DrawTexture(rust::classes::Rect(x, y, 20, m_flWidth), white_texture);
	}
	enum TextAnchor
	{
		UpperLeft = 0,
		UpperCenter = 1,
		UpperRight = 2,
		MiddleLeft = 3,
		MiddleCenter = 4,
		MiddleRight = 5,
		LowerLeft = 6,
		LowerCenter = 7,
		LowerRight = 8
	};
	void DoTab2(rust::classes::EventType m_iEventType, vector2 m_vecMenuPos, vector2 m_vecMousePos, const wchar_t* m_wszName, int m_iTabId, vector2 m_vecTabSize = vector2(150.0f, 20.0f))
	{
		if (m_iEventType == rust::classes::EventType::MouseDown)
			if (rust::classes::Rect(m_vecMenuPos.x + m_vecTabSize.x * m_iTabId, m_vecMenuPos.y,m_vecTabSize.x, m_vecTabSize.y).Contains(m_vecMousePos))
				Vars::User::activetab = m_iTabId;

		if (m_iEventType == rust::classes::EventType::Repaint)
		{
			//if (Vars::User::activetab == m_iTabId)
				DrawHorizontalLine(m_vecMenuPos.x + m_iTabId * m_vecTabSize.x, m_vecMenuPos.y + 2.f, m_vecTabSize.x, m_iTabId == Vars::User::activetab ? gui222::Color(255, 255, 255, menu_alpha) : gui222::Color(52, 52, 52, menu_alpha));
		//	engine::gui::rect(window_pos.x + tab_size + 25.f, window_pos.y + (i * 100) + 35.f, 0, 100.f, m_iTabId == Vars::User::activetab ? gui222::Color(255, 255, 255, menu_alpha ) : gui222::Color(52, 52, 52, menu_alpha ));
			DrawTextout(m_vecMenuPos.x + m_iTabId * m_vecTabSize.x, m_vecMenuPos.y, m_wszName, 12, gui222::Color(255, 255, 255, menu_alpha), true, TextAnchor::MiddleCenter, false, m_vecTabSize.x, m_vecTabSize.y);
		}
	}


	void DoButton(rust::classes::EventType event, vector2 menupos, vector2& cur, vector2 mouse, const wchar_t* name, bool* IO) {
		const float button_size = 16;
		if (event == rust::classes::EventType::MouseDown) {
			if (rust::classes::Rect(menupos.x + cur.x, menupos.y + cur.y, button_size, button_size).Contains(mouse)) {
				*IO = !*IO;
			}
		}

		if (event == rust::classes::EventType::Repaint) {
			gui::outline_box(vector2(menupos.x + cur.x, menupos.y + cur.y), vector2(button_size, button_size), gui222::Color(169, 124, 252, menu_alpha));
			gui::Label(rust::classes::Rect(menupos.x + cur.x + button_size + 3, menupos.y + cur.y, 200, button_size), (name), gui222::Color(1, 1, 1, menu_alpha), false, 10.f);

			if (*IO) {
				//gui::fill_box(rust::classes::Rect(menupos.x + cur.x, menupos.y + cur.y, button_size, button_size), Color(0, 191, 255, 1));
				gui::fill_box2(rust::classes::Rect(menupos.x + cur.x + 2.0f, menupos.y + cur.y + 2.0f, button_size - 3.0f, button_size - 3.0f), gui222::Color(169, 124, 252, menu_alpha));
			}
		}
		cur.y += button_size + 5.f;
	}

	void DoSlider(rust::classes::EventType m_iEventType, vector2 m_vecMenuPos, vector2& m_vecCursorPos, vector2 m_vecMousePos,const wchar_t* m_wszLabel, float* m_flValue, float m_flMin, float m_flMax)
	{
		bool m_bDrawValue = false;

		if (rust::classes::Rect(m_vecMenuPos.x + 11.0f, m_vecMenuPos.y + m_vecCursorPos.y + 21.0f, 170.f, 10).Contains(m_vecMousePos))
		{
			m_bDrawValue = true;

			if (m_iEventType == rust::classes::EventType::MouseDrag)
			{
				float m_flFilled = (m_vecMousePos.x - m_vecMenuPos.x - 11.0f) * 100.0f / 170.f;
				*m_flValue = (m_flMax - m_flMin) * m_flFilled / 100.0f;

				if (*m_flValue > m_flMax)
					*m_flValue = m_flMax;
				if (*m_flValue < m_flMin)
					*m_flValue = m_flMin;
			}
		}

		float m_flLength = 170.f / 100.0f * (100.0f * (*m_flValue) / (m_flMax - m_flMin));

		DrawTextout(m_vecMenuPos.x + m_vecCursorPos.x, m_vecMenuPos.y + m_vecCursorPos.y, m_wszLabel,12, gui222::Color(169, 124, 252, menu_alpha), true, TextAnchor::MiddleCenter, false, 600, 20);

		m_vecCursorPos.y += 20.0f;

		gui::outline_box(vector2(m_vecMenuPos.x + 10.0f, m_vecMenuPos.y + m_vecCursorPos.y), vector2(170.f, 7), gui222::Color(169, 124, 252, menu_alpha));

		gui::fill_box2(rust::classes::Rect(m_vecMenuPos.x + 11.0f, m_vecMenuPos.y + m_vecCursorPos.y + 1.0f,m_flLength, 6), gui222::Color(169, 124, 252, menu_alpha));

		if (m_bDrawValue)
		{
			char m_szValue[64];
			wchar_t m_wszValue[64];
			itoa(static_cast<int>(*m_flValue), m_szValue, 10);
			AnsiToUnicode(m_szValue, m_wszValue);

			DrawTextout(m_vecMenuPos.x + 10.0f, m_vecMenuPos.y + m_vecCursorPos.y - 1.0f,m_wszValue, 12, gui222::Color(255, 255, 255, menu_alpha), true, TextAnchor::MiddleCenter, false, 569, 15);
		}

		m_vecCursorPos.y += 20.0f;
	}
	bool g_bMousePressed = false;
	void Draw_line(vector2 start, vector2 end, gui222::Color color) {
		pizdec = il2cpp::methods::object_new(il2cpp::init_class(_("Material"), _("UnityEngine")));
		methods::create_with_shader_fn(pizdec, Find(_(L"Hidden/Internal-Colored")));
		SetInt(pizdec, _(L"_SrcBlend"), 5);
		SetInt(pizdec, _(L"_DstBlend"), 10);
		SetInt(pizdec, _(L"_Cull"), 0);
		SetInt(pizdec, _(L"_ZWrite"), 0);
		gui::methods::dont_destroy_on_load(pizdec);

		gui::methods::PushMatrix();
		gui::methods::SetPass(pizdec, 0);
		gui::methods::Begin(1);
		gui::methods::Color(color.GetUnityColor());

		gui::methods::Vertex(Vector(start.x, start.y, 0));
		gui::methods::Vertex(Vector(end.x, end.y, 0));

		gui::methods::End();
		gui::methods::PopMatrix();
	}

	void rect(float x, float y, float w, float h, gui222::Color clr)
	{
		gui::methods::Color(clr.GetUnityColor());
		gui::methods::DrawTexture({ x, y, 1, h }, white_texture);
		gui::methods::DrawTexture({ x + w, y + 1, 1, h }, white_texture);
		gui::methods::DrawTexture({ x, y, w + 1, 1 }, white_texture);
		gui::methods::DrawTexture({ x, y + h, w, 1 }, white_texture);
	}

	void Rect2(vector2 pos, vector2 size, gui222::Color clr)
	{
		methods::set_color(clr.GetUnityColor());
		methods::DrawTexture(rust::classes::Rect(pos.x, pos.y, 1, size.y), white_texture);
		methods::DrawTexture(rust::classes::Rect(pos.x + size.x, pos.y, 1, size.y), white_texture);
		methods::DrawTexture(rust::classes::Rect(pos.x, pos.y, size.x, 1), white_texture);
		methods::DrawTexture(rust::classes::Rect(pos.x, pos.y + size.y, size.x, 1), white_texture);
	}

	inline auto gradient_filled_rect(float x, float y, float w, float h, gui222::Color col, gui222::Color  col2) -> void
	{
		gui::methods::Begin(1);
		gui::methods::Color(col.GetUnityColor());
		gui::methods::Vertex({ x, y, 0 });
		gui::methods::Vertex({ x + w, y, 0 });
		gui::methods::Color(col2.GetUnityColor());
		gui::methods::Vertex({ x + w, y + h, 0 });
		gui::methods::Vertex({ x, y + h, 0 });
		gui::methods::Color(col.GetUnityColor());
		gui::methods::Vertex({ x, y, 0 });
		gui::methods::End();;
	}
	void DoColorPicker(rust::classes::EventType m_iEventType, vector2 m_vecMenuPos, vector2& m_vecCursorPos, vector2 m_vecMousePos,const wchar_t* m_wszLabel, gui222::Color* m_pColor)
	{
		DrawTextout(m_vecMenuPos.x + m_vecCursorPos.x, m_vecMenuPos.y + m_vecCursorPos.y, m_wszLabel, 12, m_pColor->GetUnityColor(), true, TextAnchor::MiddleCenter, false, 600, 20);

		m_vecCursorPos.y += 15.0f;

		DoSlider(m_iEventType, m_vecMenuPos, m_vecCursorPos, m_vecMousePos, _(L"R"), &m_pColor->r, 0.0f, 255.0f);
		DoSlider(m_iEventType, m_vecMenuPos, m_vecCursorPos, m_vecMousePos, _(L"G"), &m_pColor->g, 0.0f, 255.0f);
		DoSlider(m_iEventType, m_vecMenuPos, m_vecCursorPos, m_vecMousePos, _(L"B"), &m_pColor->b, 0.0f, 255.0f);
	}
	static bool wakeup{ false };
	static bool sex{ false };
	vector2 window_pos{ 50, 50 }, mouse_pos, next_item_pos;
	vector2 window_sizemain;
	vector2 old_mouse_pos;
	bool mouse_state, insert_state;
	rust::classes::EventType menu_event;
	bool old_mouse_state, old_insert_state;

	vector2 widget_mouse_pos, old_widget_mouse_pos;
	bool widget_state, old_widget_state;
	float color_picker_alpha;
	bool is_menu_open{ true };
	bool interacting;
	bool is_mouse_in_box(const vector2& pos1, const vector2& pos2) {
		if (old_mouse_pos.x < pos1.x || old_mouse_pos.y < pos1.y)
			return false;

		if (old_mouse_pos.x > pos2.x || old_mouse_pos.y > pos2.y)
			return false;

		return true;
	}
	bool window(wchar_t* title, const vector2& pos, const vector2& window_size, bool always_open)
	{
		if (!sex) {
			window_pos = pos;
			sex = true;
		}
		auto mouse = get_mousePosition();
		auto width = unity::get_width();
		auto height = unity::get_height();
		window_sizemain = window_size;

		menu_event = methods::get_type(methods::get_current());
		const auto key_code = unity::get_keyCode(methods::get_current());

		insert_state = menu_event == rust::classes::EventType::KeyDown && key_code == rust::classes::KeyCode::Insert;

		mouse_pos.x = get_mousePosition().x;
		mouse_pos.y = unity::get_height() - get_mousePosition().y;
		mouse_state = GetMouseButton(0);
		if (insert_state && !old_insert_state && !always_open)
			is_menu_open = !is_menu_open;

		if (is_menu_open)
		{
			menu_alpha = min(menu_alpha + 7, 255);
		} 

		if (!is_menu_open) {
			menu_alpha = max(menu_alpha - 7, 0);
			if (menu_alpha == 0)
				return false;
		}

		if (is_mouse_in_box({ window_pos.x, window_pos.y }, { window_pos.x + window_size.x, window_pos.y + 20 }) && mouse_state && main_menu_open) {
			window_pos.x += mouse_pos.x - old_mouse_pos.x;
			window_pos.y += mouse_pos.y - old_mouse_pos.y;
		}

		if (menu_event == rust::classes::EventType::Repaint)
		{
			gui::fill_box2({ window_pos.x, window_pos.y, window_size.x + 1, window_size.y + 1 }, { 24, 24, 24, menu_alpha });
			gui::fill_box2({ window_pos.x, window_pos.y, window_size.x + 1, 15 }, { 28, 28, 28, menu_alpha });
			gui::outline_box({ window_pos.x, window_pos.y }, { window_size.x + 1, window_size.y + 1 }, { 0, 0, 252, menu_alpha });
			gui::Text(window_pos.x + 5.f, window_pos.y - 1, 300, 20, title, { 255, 255, 255, menu_alpha }, false, true, 11.f);
		}
		return true;
	}
	int table = 0;

	void tab_Cc(const wchar_t* name, int id, vector2 tab_size = vector2(80.f, 80.f)) {
		if (menu_event == rust::classes::EventType::MouseDown)
			if (is_mouse_in_box({ window_pos.x + 25.f, window_pos.y + (id * 100) + 35.f }, { window_pos.x + tab_size.x + 25.f, window_pos.y + (id * 100) + 35.f + tab_size.y }) && mouse_state)
				Vars::User::activetab = id;
		if (menu_event == rust::classes::EventType::Repaint) {
			vertical_line(vector2(window_pos.x + tab_size.x, window_pos.y + (id * 100) + 35.f ), tab_size.y, id == Vars::User::activetab ? gui222::Color(0, 0, 252, menu_alpha) : gui222::Color(52, 52, 52, menu_alpha));
			Text(window_pos.x + 5.f, window_pos.y + (id * 100) + 35.f, tab_size.x, tab_size.y, (name), gui222::Color(255, 255, 255, menu_alpha), true, true);
		}
	}
	int subtabs = 0;
	void sub_tabs(const wchar_t* name, int id) {
		const float tab_size = 170;
		if (menu_event == rust::classes::EventType::MouseDown)
			if (is_mouse_in_box({ window_pos.x + (id * tab_size) + 115, window_pos.y + 30 }, { window_pos.x + (id * tab_size) + tab_size + 115, window_pos.y + 45 }) && mouse_state)
				subtabs = id;
		if (menu_event == rust::classes::EventType::Repaint)
		{
			
			HorizontalLine(vector2(window_pos.x + (id * tab_size) + 115, window_pos.y + 45), tab_size, id == subtabs ? gui222::Color(0, 0, 252, menu_alpha) : gui222::Color(52, 52, 52, menu_alpha));
	
			Text(window_pos.x + (id * tab_size) + tab_size / 2 - 150 + 115, window_pos.y + 25, 300, 20, name, gui222::Color(255, 255, 255, menu_alpha), true, false);
		}
	}

	void checkbox(const wchar_t* title, bool& value) {


		if (is_mouse_in_box({ next_item_pos.x - 6, next_item_pos.y }, { next_item_pos.x - 6 + 15, next_item_pos.y + 15 }) && mouse_state && !old_mouse_state && !interacting)
			value = !value;

		if (menu_event == rust::classes::EventType::Repaint)
		{
			fill_box2({ next_item_pos.x - 6, next_item_pos.y + 1, 16, 16 }, { 24, 24, 24, menu_alpha });
			if (value)
				fill_box2({ next_item_pos.x - 6, next_item_pos.y + 1, 16, 16 }, { 221, 255, 0, menu_alpha });

			outline_box({ next_item_pos.x - 7, next_item_pos.y }, { 17, 17 }, { 0, 0, 252, menu_alpha });
			Text(next_item_pos.x + 15.f, next_item_pos.y + 1, 300, 20, title, { 255, 255, 255, menu_alpha }, false, true);
		}

		next_item_pos.y += 22;
	}
	void slider(const wchar_t* title, float& value, int min, int max, const wchar_t* suffix)
	{
		next_item_pos.x -= 6;

		if (menu_event == rust::classes::EventType::Repaint)
		{
			if (is_mouse_in_box({ next_item_pos.x + 1, next_item_pos.y + 16 }, { next_item_pos.x + 141, next_item_pos.y + 22 }) && mouse_state && !interacting) {
				value = float((old_mouse_pos.x - (next_item_pos.x + 1)) * (max - min) / 140);
			}
			char m_szValue[64];
			wchar_t m_wszValue[64];
			itoa(static_cast<float>(value), m_szValue, 10);
			AnsiToUnicode(m_szValue, m_wszValue);
			Text(next_item_pos.x + 1, next_item_pos.y - 2, 300, 20, m_wszValue, { 255, 255, 255, menu_alpha }, false, false);
			fill_box2({ next_item_pos.x, next_item_pos.y + 16, 140, 5 }, { 61, 61, 61, menu_alpha });
			fill_box2({ next_item_pos.x + 1, next_item_pos.y + 16, static_cast<float>((value * 140) / max) - 1, 5 }, { 221, 255, 0, menu_alpha });
		}

		next_item_pos.x += 6;
		next_item_pos.y += 28;
	}

	void combobox(const wchar_t* title, const vector2& pos, const vector2& size)
	{
		outline_box({ window_pos.x + pos.x, window_pos.y + pos.y }, { size.x, size.y }, gui222::Color{ 52, 52, 52, menu_alpha });
		Text(window_pos.x + pos.x + 6.f, window_pos.y + pos.y - 10.f, 300, 20, title, { 255, 255, 255, menu_alpha }, false, true);
		next_item_pos = { window_pos.x + pos.x + 15, window_pos.y + pos.y + 17 };
	}

	void FullRect(rust::classes::Rect pos, gui222::Color clr)
	{
		methods::set_color(clr.GetUnityColor());
		methods::DrawTexture(pos, white_texture);
	}

	void end_window() {
		old_insert_state = insert_state;
		old_mouse_pos = mouse_pos;
		old_mouse_state = mouse_state;
	}


	void RenderRadarBackground(float Pos_x, float Pos_Y, float Rad)
	{
		if (settings::Radar::Enable)
		{
			DrawFov({ 0, 0, 0 , 255 }, { Pos_x + Rad / 2, Pos_Y + Rad / 2 }, Rad / 2);
			Draw_line({ Pos_x + Rad / 2, Pos_Y }, { Pos_x + Rad / 2,Pos_Y + Rad }, { 255,255,255,255 });
			Draw_line({ Pos_x, Pos_Y + Rad / 2 }, { Pos_x + Rad, Pos_Y + Rad / 2 }, { 255,255,255,255 });
		}
	}


	void render()
	{
		init();
		if (local_player)
			tick_time_when_called = local_player->get_last_sent_ticket_time();
		auto mouse = get_mousePosition();
		auto width = unity::get_width();
		auto height = unity::get_height();
		menu_event = methods::get_type(methods::get_current());
		float xs = unity::get_width() / 2, ys = unity::get_height() / 2;
		if (menu_event == rust::classes::EventType::KeyDown || menu_event == rust::classes::EventType::KeyUp) {	
			rust::classes::KeyCode cur = unity::get_keyCode(methods::get_current());
			if (menu_event == rust::classes::EventType::KeyDown)
				OnKeyDown(cur);
			else
				OnKeyUp(cur);
		}

		if (menu_event == rust::classes::EventType::Repaint) {
			{
				if (settings::weapon::Fov)
				{
					DrawFov(gui222::Color(255, 0, 0, 255), vector2(width / 2, height / 2), settings::weapon::aimbotfov);
				}
				if (settings::misc::Crosshair) {

					Draw_line({ xs, ys }, { xs + 4, ys + 4 }, gui222::Color(0, 0, 0, 255));
					Draw_line({ xs, ys }, { xs + 4, ys - 4 }, gui222::Color(0, 0, 0, 255));
					Draw_line({ xs, ys }, { xs - 4, ys - 4 }, gui222::Color(0, 0, 0, 255));
					Draw_line({ xs, ys }, { xs - 4, ys + 4 }, gui222::Color(0, 0, 0, 255));
					Draw_line({ xs + 4, ys + 4 }, { xs + 4 + 4, ys + 4 + 4 }, gui222::Color(255, 0, 0, 255));
					Draw_line({ xs + 4, ys - 4 }, { xs + 4 + 4, ys - 4 - 4 }, gui222::Color(255, 0, 0, 255));
					Draw_line({ xs - 4, ys - 4 }, { xs - 4 - 4, ys - 4 - 4 }, gui222::Color(255, 0, 0, 255));
					Draw_line({ xs - 4, ys + 4 }, { xs - 4 - 4, ys + 4 + 4 }, gui222::Color(255, 0, 0, 255));
				}


				FullRect(rust::classes::Rect(xs / 2.f + 250, 70.f, 428.f * (settings::flyhack / settings::max_flyhack), 10), {255,0,0,255});
				Rect2(vector2(xs / 2 + 250, 70.f), vector2(428, 10), { 0,0,0,255 });

				FullRect(rust::classes::Rect(xs / 2 + 250, 100, 428 * (settings::hor_flyhack / settings::max_hor_flyhack), 10), { 255,0,0,255 });
				Rect2(vector2(xs / 2 + 250, 100.f), vector2(428, 10), {0,0,0,255});

				if (settings::Radar::Enable)
				{
					RenderRadarBackground(settings::Radar::Pos_X, settings::Radar::Pos_Y, settings::Radar::Radar_Size);
				}



				if (settings::misc::reloadcooldown) {
					if (local_player->get_active_weapon()) {
						if (local_player->get_active_weapon()->get_base_projetile()) {
							if (local_player->get_active_weapon()->get_base_projetile()->HasReloadCooldown()) {
								float min = local_player->get_active_weapon()->get_base_projetile()->nextReloadTime() - get_time();
								float max = local_player->get_active_weapon()->get_base_projetile()->CalculateCooldownTime(local_player->get_active_weapon()->get_base_projetile()->nextReloadTime(), local_player->get_active_weapon()->get_base_projetile()->reloadTime()) - get_time();
								Rect2(vector2{ xs - 41, ys - 82 }, vector2{ 80, 5 }, gui222::Color(0, 0, 0, 255));
								FullRect(rust::classes::Rect{ xs - 40, ys - 81.5f, 156 * (min / max), 4.3 }, gui222::Color(255, 0, 0, 255));
							}
							else {}
						}
						else {}
					}
					else {}
				}





				esp::ESPLoop();
			}
		}
		main_menu_open = window(_(L"Titanium Cheats"), { 50, 50 }, { 460, 350 }, false);

		if (main_menu_open)
		{
			tab_Cc(_(L"AimBot"), 0);//RageBot
			tab_Cc(_(L"Visuals"), 1);
			tab_Cc(_(L"Misc"), 2);
			switch (Vars::User::activetab)
			{
			case 0:
				combobox(_(L"aim"), { 120, 45 }, { 160, 285 });
				{
					checkbox(_(L"AimBot"), settings::aimbot);
					checkbox(_(L"RecoilControlSystem"), settings::RecoilControlSystem);
					checkbox( _(L"Draw Fov"), settings::weapon::Fov);
					  slider( _(L"Fov"), settings::weapon::aimbotfov, 0.0f, 500.0f, _(L"%d"));
					checkbox(_(L"Psilent"), settings::weapon::psilent);
					checkbox(_(L"Crosshair"), settings::misc::Crosshair);
	
				}

				combobox(_(L"weapon"), { 290, 45 }, { 160, 290 });
				{
					
					checkbox( _(L"Removals"), settings::weapon::weapon_removals);
					if (settings::weapon::weapon_removals) {
		                checkbox(_(L"Thick bullet"), settings::weapon::thick_bullet);
						checkbox(_(L"Instant eoka"), settings::weapon::eoka);
						checkbox( _(L"No Recoil"), settings::weapon::norecoil);
						checkbox( _(L"No Spread"), settings::weapon::nospread);
						checkbox( _(L"No Sway"),settings::weapon::nosway);
						checkbox( _(L"Automatic"), settings::weapon::automatic);
						checkbox(_(L"reload indecator"), settings::misc::reloadcooldown);
					}
					checkbox(_(L"FastShoot"), settings::weapon::fastshoot);
				}
				break;
			case 1:
				sub_tabs(_(L"Player"), 0);
				sub_tabs(_(L"Misc"), 1);
				switch (subtabs)
				{
				case 0:
					combobox(_(L"players"), { 120, 55 }, { 160, 290 }); {
						checkbox(_(L"Players"), settings::visuals::player_esp);
						checkbox(_(L"Box"), settings::visuals::full_box);
						if (settings::visuals::full_box)
						{
							settings::visuals::corner_box = false;
						}

						checkbox(_(L"Corner Box"), settings::visuals::corner_box);
						if (settings::visuals::corner_box)
						{
							settings::visuals::full_box = false;
						}
						checkbox(_(L"Fill Box"), settings::visuals::fill_box);				
						checkbox(_(L"Name Esp"), settings::visuals::nameesp);
						checkbox(_(L"Wounded Flag"), settings::visuals::woundedflag);
						checkbox(_(L"Weapon Esp"), settings::visuals::weaponesp);
						checkbox(_(L"distance"), settings::visuals::distance);
						checkbox(_(L"Side Healthbar"), settings::visuals::sidehealth);

					}

					combobox(_(L"chams"), { 290, 55 }, { 160, 120 });
					{
						checkbox(_(L"Chams"), settings::visuals::chams);
						if (settings::visuals::chams)
							checkbox(_(L"Rainbow Chams"), settings::visuals::rainbow_chams);
					}
					combobox(_(L"Other"), { 290, 184 }, { 160, 146 });
					{
						checkbox(_(L"Sleeper"), settings::visuals::sleeper_esp);
						checkbox(_(L"NPC"), settings::visuals::npc_esp);
						checkbox(_(L"Corpse"), settings::visuals::corpses);
					}
					break;
				case 1:
					combobox(_(L"world"), { 120, 55 }, { 160, 285 });
					{
						checkbox( _(L"Misc"), settings::visuals::misc_esp);
						if (settings::visuals::misc_esp)
						{
							checkbox( _(L"Materials"), settings::visuals::materials);
							if (settings::visuals::materials) {
								checkbox( _(L"Stone Ore"), settings::visuals::stone_ore);
								checkbox( _(L"Metal Ore"), settings::visuals::metal_ore);
								checkbox( _(L"Sulfur Ore"), settings::visuals::sulfur_ore);
								checkbox( _(L"Cloth"), settings::visuals::cloth);
							}
							checkbox( _(L"Vehicles"), settings::visuals::vehicle);
							if (settings::visuals::vehicle) {
								checkbox( _(L"Vehicles"), settings::visuals::vehicles);
								checkbox( _(L"Helicopter"), settings::visuals::heli_esp);
							}

							checkbox(_(L"AutoPickup"), settings::misc::AutoPickup);
							checkbox(_(L"AutoFarmBot"), settings::misc::AutoFarmBot);
							checkbox(_(L"AutoFarmOre"), settings::misc::AutoFarmOre);
							checkbox(_(L"AutoFarmTree"), settings::misc::AutoFarmTree);
							checkbox(_(L"DoorKnocker"), settings::misc::DoorKnocker);

						}

					}

					combobox(_(L"screen"), { 290, 55 }, { 160, 285 });
					{
						checkbox(_(L"workbench"), settings::visuals::Backpack);
						checkbox( _(L"Dropped Items"), settings::visuals::dropped_items);
						checkbox( _(L"Stashes"), settings::visuals::stash);
						checkbox( _(L"Airdrops"), settings::visuals::airdrops);
						checkbox( _(L"Traps"), settings::visuals::traps);
						checkbox( _(L"Tool Cupboard"), settings::visuals::tc_esp);
						checkbox(_(L"Enable"), settings::Radar::Enable);
						if (settings::Radar::Enable)
						{
							checkbox(_(L"Radar Player"), settings::Radar::ShowRadarPlayer);
							checkbox(_(L"Radar Sleeper"), settings::Radar::ShowRadarSleeper);
							slider(_(L"Radar_X"), settings::Radar::Pos_X, 0.f, 3000.f, _(L"%d"));
							slider(_(L"Radar_Y"), settings::Radar::Pos_Y, 0.f, 2500.f, _(L"%d"));

						}
					}
					break;
				}
				break;
			case 2:
				combobox(_(L"Misc"), { 120, 45 }, { 160, 285 });
				{
					checkbox(_(L"Always sprint"), settings::misc::always_sprint);
					checkbox(_(L"Infinite Jump"), settings::misc::infinite_jump);
					checkbox(_(L"Spiderman"), settings::misc::spiderman);
					checkbox(_(L"Big Jump"), settings::misc::gravity);
					checkbox(_(L"SilentWalk(Mouse3)"), settings::misc::silentwalk);
					checkbox(_(L"Spinbot"), settings::misc::spinbot);
					checkbox(_(L"Fake_lag"), settings::misc::fake_lag);
					checkbox(_(L"Admin Mode"), settings::misc::admin_mode);
					checkbox(_(L"No Collisions"), settings::misc::no_playercollision);
					checkbox(_(L"Tod Sky"), settings::misc::todsky);
					checkbox(_(L"DayTime"), settings::visuals::Day);
					if (settings::visuals::Day)
					{
						slider(_(L"DayTime"), settings::visuals::DayTime, 0.f, 24.f, _(L"%d"));
						
					}
				}

				combobox(_(L"World"), { 290, 45 }, { 160, 285 });
				{
					checkbox( _(L"Player FOV"), settings::misc::playerfovtoggle);
					if (settings::misc::playerfovtoggle) {
						slider( _(L"PlayerFov"), settings::misc::playerfov, 0.0f, 180.0f, _(L"%d"));
						checkbox( _(L"Zoom FOV(Press Z)"), settings::misc::zoomtoggle);
					}
					checkbox(_(L"TakeDamage(Press P)"), settings::misc::TakeFallDamage);
					checkbox(_(L"LongNeck(Press Y)"), settings::misc::eyeoffset);
				
				}
				break;
			}
		}
		end_window();
		return;
	}

}

float unity::get_fov(Vector Pos) {
	esp::matrix = unity::get_view_matrix();

	Vector ScreenPos = WorldToScreen(Pos);
	if (ScreenPos.is_empty())
		return 1000;
	return get_2d_dist(vector2(unity::get_width() / 2, unity::get_height() / 2), ScreenPos);
}

void ColorConvertHSVtoRGB(float h, float s, float v, float& out_r, float& out_g, float& out_b)
{
	if (s == 0.0f)
	{
		// gray
		out_r = out_g = out_b = v;
		return;
	}

	h = my_fmod(h, 1.0f) / (60.0f / 360.0f);
	int   i = (int)h;
	float f = h - (float)i;
	float p = v * (1.0f - s);
	float q = v * (1.0f - s * f);
	float t = v * (1.0f - s * (1.0f - f));

	switch (i)
	{
	case 0: out_r = v; out_g = t; out_b = p; break;
	case 1: out_r = q; out_g = v; out_b = p; break;
	case 2: out_r = p; out_g = v; out_b = t; break;
	case 3: out_r = p; out_g = q; out_b = v; break;
	case 4: out_r = t; out_g = p; out_b = v; break;
	case 5: default: out_r = v; out_g = p; out_b = q; break;
	}
}

gui222::Color HSV(float h, float s, float v, float a = 1.0f) { float r, g, b; ColorConvertHSVtoRGB(h, s, v, r, g, b); return gui222::Color(r, g, b, a); }

void esp::draw_heli(float x, float y, float w, float h) {
	gui::outline_box({ x - w / 2, y - h / 2 }, { w, h }, { 255, 255, 255, 255 });
	gui::fill_box({ x - w / 2, y - h / 2, w ,h }, { 0.2,0.2,0.2,0.3 });
	gui::outline_box({ x - w / 2 - 1, y - h / 2 - 1 }, { w + 2, h + 2 }, { 0, 0, 0, 1 });
}

void esp::draw_tool_cupboard(vector2 w2s_position, wchar_t* new_str_text, gui222::Color color, rust::list<PlayerNameID*>* authorizedPlayers_list)
{
	auto label = [&](float y, wchar_t* text)
	{
		gui::Text(w2s_position.x, w2s_position.y + 2, 150, 20, text, color, false, true, 12);
	};

	
	gui::Text(w2s_position.x, w2s_position.y + 2, 150, 20, new_str_text, color, false, true, 12);
	float info_y = 12;

	authorizedPlayers_list->for_each([&](PlayerNameID* authorizedPlayer, int32_t idx) {
		if (authorizedPlayer)
		{
			auto user = authorizedPlayer->get_username();
			label(info_y, user);

			LOG("Username: %ls", user);
			info_y += 30;
		}
		});
}
void esp::draw_item(vector2 w2s_position, wchar_t* label, gui222::Color color, wchar_t* name) { // vector4 because color gui im mretard dont talk about it
	
	if (label) {
		gui::Text(w2s_position.x, w2s_position.y + 2, 150, 20, label, color, false, true, 12);
	}
	else {
		gui::Text(w2s_position.x, w2s_position.y + 2, 150, 20, name, color, false, true, 12);
	}
}
void esp::draw_name(Vector position, wchar_t* name)
{
	if (name)
	{
		gui::Label(rust::classes::Rect{ position.x + 2.0f + 1, position.y - 4 + 1, 150, 20 }, name, gui222::Color(0, 0, 0, 120), false, 12);
		gui::Label(rust::classes::Rect{ position.x + 2.0f, position.y - 4, 150, 20 }, name, gui222::Color(255, 255, 255, 220), false, 12);
	}
}

void esp::draw_weapon_icon(weapon* item, vector2 w2s_position) {

	auto sprite = get_iconSprite(item);
	if (!sprite)
		return;

	auto texture = get_texture(sprite);
	if (!texture)
		return;

	auto rect = get_rect(sprite);
	if (texture) {
		gui::methods::set_color({ 1, 1, 1, 1 });
		gui::methods::DrawTexture({ w2s_position.x + 2.0f + 1, w2s_position.y - 4 + 13 + 1, rect.wid / 7, rect.hei / 7 }, texture);
		//gui::Label({ w2s_position.x + 2.0f + 1, w2s_position.y - 4 + 13 + 1, rect.wid / 7, rect.hei / 7 }, il2cpp::methods::new_string(_("")), gui222::Color(196, 124, 0, 255));
	}
}



void esp::miscvis(DWORD64 ObjectClass, char* buff, bool boolean, bool showDistance, float drawDistance, const char* substring, const wchar_t* targettext, gui222::Color Col) {
	if (boolean && m_strstr(buff, substring)) {
		DWORD64 gameObject = safe_read(ObjectClass + 0x30, DWORD64);
		DWORD64 transform = safe_read(gameObject + 0x8, DWORD64);
		DWORD64 vector = safe_read(transform + 0x38, DWORD64);
		Vector game_Pos = safe_read(vector + 0x90, Vector);
		vector2 screen_Pos;
		if (esp::out_w2s(game_Pos, screen_Pos)) {
			if ((int)Calc3D_Dist(local_player->GetBoneByID(head), game_Pos) <= drawDistance) {
				gui::Text(screen_Pos.x - 40, screen_Pos.y, 150, 20, targettext, Col, true, 12);
				if (showDistance) {
					int distation = (int)Calc3D_Dist(local_player->GetBoneByID(head), game_Pos);
					char m_szHealth[256];
					wchar_t m_wszHealth[256];
					itoa(static_cast<int>(distation), m_szHealth, 10);
					AnsiToUnicode(m_szHealth, m_wszHealth);
					gui::Text(screen_Pos.x - 40, screen_Pos.y + 10, 150, 20, m_wszHealth, Col, 12);
				}
			}
		}
	}
}


void esp::RadarPlayer(base_player* player)
{
	if (local_player)
	{
		if (settings::Radar::Enable)
		{
			if (settings::Radar::ShowRadarPlayer || settings::Radar::ShowRadarSleeper)
			{
				if (!player->IsDead() && player->GetHealth() >= 0.2f)
				{
					const Vector LocalPos = local_player->get_bone_transform(48)->get_bone_position();
					const Vector PlayerPos = player->get_bone_transform(48)->get_bone_position();
					const float Distance = Distance3D(LocalPos, PlayerPos);
					const float y = LocalPos.x - PlayerPos.x;
					const float x = LocalPos.z - PlayerPos.z;
					Vector eulerAngles = Math::EulerAngles(local_player->Radar_eyes()->get_rotation());
					const float num = m_atan2(y, x) * 57.29578f - 270.f - eulerAngles.y;
					float PointPos_X = Distance * m_cos(num * 0.0174532924f);
					float PointPos_Y = Distance * m_sin(num * 0.0174532924f);
					PointPos_X = PointPos_X * (settings::Radar::Radar_Size / settings::Radar::Radar_Range) / 2.f;
					PointPos_Y = PointPos_Y * (settings::Radar::Radar_Size / settings::Radar::Radar_Range) / 2.f;
					const gui222::Color teammate_color = gui222::Color(0, 0.23, 1, 1); //blue
					const gui222::Color player_color = gui222::Color(255, 0, 0, 255); //blue
					bool is_teammate = player->is_teammate(local_player);
					if (!player->HasFlags(16) && settings::Radar::ShowRadarPlayer)
					{
						if (Distance <= settings::Radar::Radar_Range)
						{
							gui::FullRect({ settings::Radar::Pos_X + settings::Radar::Radar_Size / 2.f + PointPos_X - 3.f, settings::Radar::Pos_Y + settings::Radar::Radar_Size / 2.f + PointPos_Y - 3.f, 5, 5 }, { 40,212,101,255 });
						}
					}
					else if (player->HasFlags(16) && settings::Radar::ShowRadarSleeper)
					{
						if (Distance <= settings::Radar::Radar_Range)
						{
							gui::FullRect({ settings::Radar::Pos_X + settings::Radar::Radar_Size / 2.f + PointPos_X - 3.f, settings::Radar::Pos_Y + settings::Radar::Radar_Size / 2.f + PointPos_Y - 3.f, 5, 5 }, { 255,0,0,255 });
						}
					}
				}
			}
		}
	}
}





void esp::draw_player(base_player* player)
{
	if (!local_player)
		return;
	//   esp colors
	auto safezone_color = gui222::Color{ 0.99609375, 0.9453125, 0, 1.0 };
	const gui222::Color visible_color = gui222::Color(23, 224, 235, 255); //green
	const gui222::Color invisible_color = gui222::Color(255, 0, 0, 255); //red
	const gui222::Color teammate_color = gui222::Color(0, 0.23, 1, 1); //blue
	const gui222::Color BoxFillColor = gui222::Color(0.33, 0.33, 0.33, 0.5); //gray
	const gui222::Color Wounded = gui222::Color(255, 255, 255, 255);
	bounds_t bounds;

	struct bone_t {
		Vector screen;
		int8_t     index;
		bool       on_screen;
		Vector world_position;
		bool visible;
	};

	std::array<bone_t, 20> bones = {
		bone_t{ Vector{}, 17, false, Vector{}, false }, bone_t{ Vector{}, 18, false, Vector{}, false },
		bone_t{ Vector{}, 15, false, Vector{}, false }, bone_t{ Vector{}, 14, false, Vector{}, false },
		bone_t{ Vector{}, 1, false, Vector{}, false },  bone_t{ Vector{}, 2, false, Vector{}, false },
		bone_t{ Vector{}, 3, false, Vector{}, false },  bone_t{ Vector{}, 6, false, Vector{}, false },
		bone_t{ Vector{}, 5, false, Vector{}, false },  bone_t{ Vector{}, 21, false, Vector{}, false },
		bone_t{ Vector{}, 23, false, Vector{}, false }, bone_t{ Vector{}, 48, false, Vector{}, false },
		bone_t{ Vector{}, 24, false, Vector{}, false }, bone_t{ Vector{}, 25, false, Vector{}, false },
		bone_t{ Vector{}, 26, false, Vector{}, false }, bone_t{ Vector{}, 27, false, Vector{}, false },
		bone_t{ Vector{}, 55, false, Vector{}, false }, bone_t{ Vector{}, 56, false, Vector{}, false },
		bone_t{ Vector{}, 57, false, Vector{}, false }, bone_t{ Vector{}, 76, false, Vector{}, false }
	};

	bool is_visible = false;

	bool is_teammate = player->is_teammate(local_player);

	auto camera_position = unity::get_camera_pos();

	const auto get_bounds = [&](bounds_t& out, float expand = 0) -> bool {
		bounds = { FLT_MAX, FLT_MIN, FLT_MAX, FLT_MIN };

		for (auto& [bone_screen, bone_idx, on_screen, world_position, visible] : bones) {

			auto transform = player->get_bone_transform(bone_idx);

			world_position = transform->get_bone_position();

			if (bone_idx == 48) // lol
				world_position.y += 0.2f;

			bone_screen = WorldToScreen(world_position);
			if (bone_screen.x < bounds.left)
				bounds.left = bone_screen.x;
			if (bone_screen.x > bounds.right)
				bounds.right = bone_screen.x;
			if (bone_screen.y < bounds.top)
				bounds.top = bone_screen.y;
			if (bone_screen.y > bounds.bottom)
				bounds.bottom = bone_screen.y;
			on_screen = true;
		}

		if (bounds.left == FLT_MAX)
			return false;
		if (bounds.right == FLT_MIN)
			return false;
		if (bounds.top == FLT_MAX)
			return false;
		if (bounds.bottom == FLT_MIN)
			return false;

		bounds.left -= expand;
		bounds.right += expand;
		bounds.top -= expand;
		bounds.bottom += expand;

		out = bounds;

		return true;
	};

	if (get_bounds(bounds, 4)) {

		if (!is_visible)
			is_visible = player->is_visible(camera_position, bones[16].world_position);

		gui222::Color clr = !is_teammate ? (is_visible ? visible_color : invisible_color) : teammate_color;
		if (HasPlayerFlag(player, rust::classes::PlayerFlags::SafeZone))
			clr = safezone_color;

		if (HasPlayerFlag(player, rust::classes::PlayerFlags::Wounded))
			clr = Wounded;

		float box_width = bounds.right - bounds.left;
		float box_height = bounds.bottom - bounds.top;

		wchar_t* name = player->get_player_name();
		auto player_weapon = player->get_active_weapon();

		if (settings::visuals::fill_box && settings::visuals::boxesp)
		{
			gui::fill_box2(rust::classes::Rect(bounds.left, bounds.top, box_width, box_height), gui222::Color(0, 0, 0, 135));
		}

		if (settings::visuals::full_box && settings::visuals::boxesp) {
			//full box
			gui::outline_box(vector2{ bounds.left - 1, bounds.top - 1 }, vector2{ box_width + 2, box_height + 2 }, gui222::Color(0, 0, 0, 120));
			gui::outline_box(vector2{ bounds.left, bounds.top }, vector2{ box_width, box_height }, clr);
			//full box
		}

		if (settings::visuals::corner_box && settings::visuals::boxesp) {
			//corner box


			float X = bounds.left, Y = bounds.top, W = bounds.right - bounds.left, H = bounds.bottom - bounds.top;
			float lineW = (W / 5);
			float lineH = (H / 6);
			float lineT = 1;

			gui::Draw_line({ X, Y, }, { X, Y + lineH }, clr);
			gui::Draw_line({ X, Y }, { X + lineW, Y }, clr);
			gui::Draw_line({ X + W - lineW, Y }, { X + W, Y }, clr);
			gui::Draw_line({ X + W, Y }, { X + W, Y + lineH }, clr);
			gui::Draw_line({ X, Y + H - lineH }, { X, Y + H }, clr);
			gui::Draw_line({ X, Y + H }, { X + lineW, Y + H }, clr);
			gui::Draw_line({ X + W - lineW, Y + H }, { X + W, Y + H }, clr);
			gui::Draw_line({ X + W, Y + H - lineH }, { X + W, Y + H }, clr);


			const auto cur_health = player->get_health();
			const auto max_health = (100);
			const auto health_pc = min(cur_health / max_health, 1);
			const auto health_color =
				HSV((health_pc * .25f), 1, .875f * 1);

			const auto     height = (bounds.bottom - bounds.top) * health_pc;
			int curpos = 0;
			if (settings::visuals::sidehealth) {
				gui::fill_box2(rust::classes::Rect(bounds.left - 5, bounds.top, 4, box_height), gui222::Color(0, 0, 0, 180));
				gui::fill_box2(rust::classes::Rect(bounds.left - 4, bounds.top + box_height - height + 1, 2, height), gui222::Color(169, 124, 252, 255));
			}

			if (player_weapon)
			{
				auto weapon_name = player_weapon->get_weapon_name();
				if (weapon_name)
				{
					// WEAPON NAME ESP
					if (settings::visuals::weaponesp) {
						auto half = (bounds.right - bounds.left) / 2;
						gui::Text(bounds.left - 80.f, bounds.bottom, 80.f + half * 2 + 80.f, 20, weapon_name, gui222::Color(255, 255, 255, 255), true, true, 9);
						curpos += 12;
					}
				}
			}

			if (settings::visuals::distance)
			{
				auto half = (bounds.right - bounds.left) / 2;
				auto transform = player->get_bone_transform(48);
				auto position = transform->get_bone_position();
				auto distance = local_player->get_bone_transform(48)->get_bone_position().Distance(position);
				char m_szHealth[256];
				wchar_t m_wszHealth[256];
				itoa(static_cast<int>(distance), m_szHealth, 10);
				AnsiToUnicode(m_szHealth, m_wszHealth);
				gui::Text(bounds.left - 80.f, bounds.bottom + curpos, 80.f + half * 2 + 80.f, 20, m_wszHealth, gui222::Color(255, 255, 255, 255), true, true, 9);
				curpos += 12;
			}
			auto camera_pos = unity::get_camera_pos();
			aim_target target = local_player->get_aimbot_target(camera_pos);
			float xs2 = unity::get_width() / 2, ys2 = unity::get_height();
			if (settings::weapon::snaplines)
				if (target.player && target.visible && !target.teammate)
					gui::Draw_line({ bounds.left + ((bounds.right - bounds.left) / 2), bounds.bottom }, { xs2, ys2 }, gui222::Color(255, 0, 0, 255));
			if (name)
			{
				if (settings::visuals::nameesp) {
					auto half = (bounds.right - bounds.left) / 2;
					auto transform = player->get_bone_transform(48);
					auto position = transform->get_bone_position();
					if (settings::visuals::woundedflag) {

						const wchar_t* woundedlol = L"Wounded";

						if (HasPlayerFlag(player, rust::classes::PlayerFlags::Wounded)) {

							gui::Text(bounds.left - 80.f, bounds.top - 33.f, 80.f + half * 2 + 80.f, 20, woundedlol, gui222::Color(255, 0, 0, 255), true, true, 9);
						}

					}
					gui::Text(bounds.left - 80.f, bounds.top - 18.f, 80.f + half * 2 + 80.f, 20, name, gui222::Color(255, 255, 255, 255), true, true, 9);

				}
				// PLAYER NAME
			}
		}


		if (settings::visuals::npc_esp)
		{
			if (!is_visible)
				is_visible = player->is_visible(camera_position, bones[16].world_position);

			gui222::Color clr = !is_teammate ? (is_visible ? visible_color : invisible_color) : teammate_color;
			if (HasPlayerFlag(player, rust::classes::PlayerFlags::SafeZone))
				clr = safezone_color;

			if (HasPlayerFlag(player, rust::classes::PlayerFlags::Wounded))
				clr = Wounded;

			float box_width = bounds.right - bounds.left;
			float box_height = bounds.bottom - bounds.top;

			wchar_t* name = player->get_player_name();
			auto player_weapon = player->get_active_weapon();

		

			if (settings::visuals::npc_esp && player->GetSteamID() < 1000000000) {
				//full box
				gui::outline_box(vector2{ bounds.left - 1, bounds.top - 1 }, vector2{ box_width + 2, box_height + 2 }, gui222::Color(0, 0, 0, 120));
				gui::outline_box(vector2{ bounds.left, bounds.top }, vector2{ box_width, box_height }, clr);
				//full box
			}

			if (settings::visuals::npc_esp && player->GetSteamID() < 1000000000) {
				//corner box
				const auto cur_health = player->get_health();
				const auto max_health = ( 100);
				const auto health_pc = min(cur_health / max_health, 1);
				const auto health_color =
					HSV((health_pc * .25f), 1, .875f * 1);

				const auto     height = (bounds.bottom - bounds.top) * health_pc;
				int curpos = 0;
				if (settings::visuals::npc_esp) {
					gui::fill_box2(rust::classes::Rect(bounds.left - 5, bounds.top, 4, box_height), gui222::Color(0, 0, 0, 180));
					gui::fill_box2(rust::classes::Rect(bounds.left - 4, bounds.top + box_height - height + 1, 2, height), gui222::Color(169, 124, 252, 255));
				}

				if (player_weapon)
				{
					auto weapon_name = player_weapon->get_weapon_name();
					if (weapon_name)
					{
						// WEAPON NAME ESP
						if (settings::visuals::weaponesp && player->GetSteamID() < 1000000000) {
							auto half = (bounds.right - bounds.left) / 2;
							gui::Text(bounds.left - 80.f, bounds.bottom, 80.f + half * 2 + 80.f, 20, weapon_name, gui222::Color(255, 255, 255, 255), true, true, 9);
							curpos += 12;
						}
					}
				}

				if (settings::visuals::npc_esp && player->GetSteamID() < 1000000000)
				{
					auto half = (bounds.right - bounds.left) / 2;
					auto transform = player->get_bone_transform(48);
					auto position = transform->get_bone_position();
					auto distance = local_player->get_bone_transform(48)->get_bone_position().Distance(position);
					char m_szHealth[255];
					wchar_t m_wszHealth[255];
					itoa(static_cast<int>(distance), m_szHealth, 10);
					AnsiToUnicode(m_szHealth, m_wszHealth);
					gui::Text(bounds.left - 80.f, bounds.bottom + curpos, 80.f + half * 2 + 80.f, 20, m_wszHealth, gui222::Color(255, 255, 255, 255), true, true, 9);
					curpos += 12;
				}
			
				if (name)
				{
					if (player->GetSteamID() < 1000000000) {
						auto half = (bounds.right - bounds.left) / 2;
						auto transform = player->get_bone_transform(48);
						auto position = transform->get_bone_position();
						

						gui::Text(bounds.left - 80.f, bounds.top - 18.f, 80.f + half * 2 + 80.f, 20, name, gui222::Color(255, 255, 255, 255), true, true, 9);

					}
					// PLAYER NAME
				}
			}
		}
	}

}