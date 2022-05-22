#pragma once
#include <cmath>
#include <cfloat>
#include "../memory/memory.hpp"
#include "../offsets.h"
#define M_PI_2 1.57079632679489661923
#define M_PI 3.14159265358979323846
#define RAD_TO_DEG 180 / 3.141592654f
#define M_RADPI	57.295779513082f
#define M_PI_F ((float)(M_PI))
#define RAD2DEG(x) ((float)(x) * (float)(180.f / M_PI_F))

#define powFFFFFFFFFFFFFFFFFFFFFF(n) (n)*(n)
#define abs(a) ((a) >= 0) ? (a) : -(a)
class vector2
{
public:
	float x;
	float y;
	vector2()
	{}
	vector2(float x, float y)
		: x(x), y(y)
	{}

	inline vector2 operator-(const vector2& v) const {
		return vector2(x - v.x, y - v.y);
	}

	inline vector2 operator+(const vector2& v) const {
		return vector2(x + v.x, y + v.y);
	}

};
struct weapon_stats_t {
	float initial_velocity;
	float gravity_modifier;
	float drag;
	float initial_distance;
};
enum ammo_types : int32_t {
	shotgun = -1685290200,
	shotgun_slug = -727717969,
	shotgun_fire = -1036635990,
	shotgun_handmade = -588596902,
	rifle_556 = -1211166256,
	rifle_556_hv = 1712070256,
	rifle_556_fire = 605467368,
	rifle_556_explosive = -1321651331,
	pistol = 785728077,
	pistol_hv = -1691396643,
	pistol_fire = 51984655,
	arrow_wooden = -1234735557,
	arrow_hv = -1023065463,
	arrow_fire = 14241751,
	arrow_bone = 215754713,
	nailgun_nails = -2097376851
};

enum weapon_types : int32_t {
	spear_stone = 1602646136,
	spear_wooden = 1540934679
};


typedef double(__stdcall* _sqrt)(double);
typedef double(__stdcall* COS)(double);
typedef double(__stdcall* ASIN)(double);
typedef double(__stdcall* ATAN2)(double, double);
typedef double(__stdcall* ABS)(double);

double my_sqrt(double d) {
	return ((_sqrt)(mem::game_assembly_base + O::System_Math::Sqrt))(d);
};
double m_asin(double d) {
	return ((ASIN)(mem::game_assembly_base + O::System_Math::Asin))(d);
}
double m_atan2(double y, double x) {
	return ((ATAN2)(mem::game_assembly_base + O::System_Math::Atan2))(y, x);
}
double m_sin(double d) {
	return ((COS)(mem::game_assembly_base + O::System_Math::Sin))(d);
}
double m_cos(double d) {
	return ((COS)(mem::game_assembly_base + O::System_Math::Cos))(d);
}
double m_abs(double d) {
	return ((ABS)(mem::game_assembly_base + O::System_Math::Abs))(d);
}


class Vector
{
public:
	float x;
	float y;
	float z;

	inline Vector();
	inline Vector(float x, float y, float z);

	inline Vector operator+(const Vector& vector) const;
	inline Vector operator-(const Vector& vector) const;
	inline Vector operator-() const;
	inline Vector operator*(float number) const;
	inline Vector operator/(float number) const;

	inline 	Vector& operator+=(const Vector& vector);
	inline Vector& operator-=(const Vector& vector);
	inline Vector& operator*=(float number);
	inline Vector& operator/=(float number);

	inline bool operator==(const Vector& vector) const;
	inline bool operator!=(const Vector& vector) const;

	inline float Dot(const Vector& vector)
	{
		return x * vector.x + y * vector.y + z * vector.z;
	}

	inline float Distance(const Vector& vector)
	{
		return my_sqrt((x - vector.x) * (x - vector.x) +
			(y - vector.y) * (y - vector.y) +
			(z - vector.z) * (z - vector.z));
	}

	inline float Length()
	{
		return my_sqrt(x * x + y * y + z * z);
	}

	inline Vector Normalized()
	{
		float m_flLength = Length();
		return Vector(x / m_flLength, y / m_flLength, z / m_flLength);
	}

	inline float operator[](int i) const {
		return ((float*)this)[i];
	}

	bool is_empty() { return x == 0 && y == 0 && z == 0; }

	inline float Magnitude2D()
	{
		return my_sqrt(this->x * this->x + this->z * this->z);
	}

	static Vector Zero() {
		return Vector(0.0f, 0.0f, 0.0f);
	}
	Vector Normalize()
	{
		Vector out = *this;
		auto l = Length();
		if (l == 0)
			return *this;
		;
		out.x /= l;
		out.y /= l;
		out.z /= l;
		return out;
	}

	Vector midPoint(Vector v2)
	{
		return Vector((x + v2.x) / 2, (y + v2.y) / 2, (z + v2.z) / 2);
	}

};

inline Vector::Vector()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

inline Vector::Vector(float x, float y, float z)
	: x(x), y(y), z(z)
{
}

inline Vector& Vector::operator+=(const Vector& vector)
{
	x += vector.x;
	y += vector.y;
	z += vector.z;

	return *this;
}

inline Vector& Vector::operator-=(const Vector& vector)
{
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;

	return *this;
}

inline Vector& Vector::operator*=(float number)
{
	x *= number;
	y *= number;
	z *= number;

	return *this;
}

inline Vector& Vector::operator/=(float number)
{
	x /= number;
	y /= number;
	z /= number;

	return *this;
}

inline bool Vector::operator==(const Vector& vector) const
{
	return x == vector.x && y == vector.y && z == vector.z;
}

inline bool Vector::operator!=(const Vector& vector) const
{
	return x != vector.x || y != vector.y || z != vector.z;
}

inline Vector Vector::operator+(const Vector& vector) const
{
	return Vector(x + vector.x, y + vector.y, z + vector.z);
}

inline Vector Vector::operator-(const Vector& vector) const
{
	return Vector(x - vector.x, y - vector.y, z - vector.z);
}

inline Vector Vector::operator-() const
{
	return Vector(-x, -y, -z);
}

inline Vector Vector::operator*(float number) const
{
	return Vector(x * number, y * number, z * number);
}

inline Vector Vector::operator/(float number) const
{
	return Vector(x / number, y / number, z / number);
}







class VMatrix
{
public:
	VMatrix()
		: m{ { 0, 0, 0, 0 },
			 { 0, 0, 0, 0 },
			 { 0, 0, 0, 0 },
			 { 0, 0, 0, 0 } }
	{}

	VMatrix(const VMatrix&) = default;

	VMatrix transpose() {
		VMatrix m;

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				m.m[i][j] = this->m[j][i];

		return m;
	}



	bool is_empty() {
		if (!m[3][0] && !m[3][1] && !m[3][2] && !m[2][1] && !m[2][0] && !m[2][2])
			return true;

		return false;
	}

	Vector operator*(const Vector& vec) {
		VMatrix m;

		m[3][0] = vec.x;
		m[3][1] = vec.y;
		m[3][2] = vec.z;

		m[0][0] = 1;
		m[1][1] = 1;
		m[2][2] = 1;


		m[0][3] = 0.0f;
		m[1][3] = 0.0f;
		m[2][3] = 0.0f;
		m[3][3] = 1.0f;

		auto result = m * (*this);

		return Vector{ result[3][0], result[3][1], result[3][2] };
	}

	VMatrix operator*(const VMatrix& _m2) {
		auto _m = *this;

		VMatrix out;
		out[0][0] = _m[0][0] * _m2[0][0] + _m[0][1] * _m2[1][0] + _m[0][2] * _m2[2][0] + _m[0][3] * _m2[3][0];
		out[0][1] = _m[0][0] * _m2[0][1] + _m[0][1] * _m2[1][1] + _m[0][2] * _m2[2][1] + _m[0][3] * _m2[3][1];
		out[0][2] = _m[0][0] * _m2[0][2] + _m[0][1] * _m2[1][2] + _m[0][2] * _m2[2][2] + _m[0][3] * _m2[3][2];
		out[0][3] = _m[0][0] * _m2[0][3] + _m[0][1] * _m2[1][3] + _m[0][2] * _m2[2][3] + _m[0][3] * _m2[3][3];
		out[1][0] = _m[1][0] * _m2[0][0] + _m[1][1] * _m2[1][0] + _m[1][2] * _m2[2][0] + _m[1][3] * _m2[3][0];
		out[1][1] = _m[1][0] * _m2[0][1] + _m[1][1] * _m2[1][1] + _m[1][2] * _m2[2][1] + _m[1][3] * _m2[3][1];
		out[1][2] = _m[1][0] * _m2[0][2] + _m[1][1] * _m2[1][2] + _m[1][2] * _m2[2][2] + _m[1][3] * _m2[3][2];
		out[1][3] = _m[1][0] * _m2[0][3] + _m[1][1] * _m2[1][3] + _m[1][2] * _m2[2][3] + _m[1][3] * _m2[3][3];
		out[2][0] = _m[2][0] * _m2[0][0] + _m[2][1] * _m2[1][0] + _m[2][2] * _m2[2][0] + _m[2][3] * _m2[3][0];
		out[2][1] = _m[2][0] * _m2[0][1] + _m[2][1] * _m2[1][1] + _m[2][2] * _m2[2][1] + _m[2][3] * _m2[3][1];
		out[2][2] = _m[2][0] * _m2[0][2] + _m[2][1] * _m2[1][2] + _m[2][2] * _m2[2][2] + _m[2][3] * _m2[3][2];
		out[2][3] = _m[2][0] * _m2[0][3] + _m[2][1] * _m2[1][3] + _m[2][2] * _m2[2][3] + _m[2][3] * _m2[3][3];
		out[3][0] = _m[3][0] * _m2[0][0] + _m[3][1] * _m2[1][0] + _m[3][2] * _m2[2][0] + _m[3][3] * _m2[3][0];
		out[3][1] = _m[3][0] * _m2[0][1] + _m[3][1] * _m2[1][1] + _m[3][2] * _m2[2][1] + _m[3][3] * _m2[3][1];
		out[3][2] = _m[3][0] * _m2[0][2] + _m[3][1] * _m2[1][2] + _m[3][2] * _m2[2][2] + _m[3][3] * _m2[3][2];
		out[3][3] = _m[3][0] * _m2[0][3] + _m[3][1] * _m2[1][3] + _m[3][2] * _m2[2][3] + _m[3][3] * _m2[3][3];

		return out;
	}

	float* operator[](size_t i) { return m[i]; }
	const float* operator[](size_t i) const { return m[i]; }

	union {
		struct {
			float _11, _12, _13, _14;
			float _21, _22, _23, _24;
			float _31, _32, _33, _34;
			float _41, _42, _43, _44;
		};
		float m[4][4];
	};
};

class vector4
{
public:
	float x;
	float y;
	float z;
	float w;

	vector4()
	{}

	vector4(float x, float y, float z, float w)
		: x(x), y(y), z(z), w(w)
	{}

	Vector forward()
	{
		Vector  point = { 0, 0, 1 };
		float num = x * 2;
		float num2 = y * 2;
		float num3 = z * 2;
		float num4 = x * num;
		float num5 = y * num2;
		float num6 = z * num3;
		float num7 = x * num2;
		float num8 = x * num3;
		float num9 = y * num3;
		float num10 = w * num;
		float num11 = w * num2;
		float num12 = w * num3;
		Vector  result;
		result.x = (1 - (num5 + num6)) * point.x + (num7 - num12) * point.y +
			(num8 + num11) * point.z;
		result.y = (num7 + num12) * point.x + (1 - (num4 + num6)) * point.y +
			(num9 - num10) * point.z;
		result.z = (num8 - num11) * point.x + (num9 + num10) * point.y +
			(1 - (num4 + num5)) * point.z;
		return result;
	}


	inline float dot(const vector4& vector)
	{
		return x * vector.x + y * vector.y + z * vector.z + w * vector.w;
	}

	inline float distance(const vector4& vector)
	{
		return sqrtf(
			(x - vector.x) * (x - vector.x) +
			(y - vector.y) * (y - vector.y) +
			(z - vector.z) * (z - vector.z) +
			(w - vector.w) * (w - vector.w));
	}

	bool operator==(const vector4& vector) const
	{
		return x == vector.x && y == vector.y && z == vector.z && w == vector.w;
	}

	bool operator!=(const vector4& vector) const
	{
		return x != vector.x || y != vector.y || z != vector.z || w != vector.w;
	}

	vector4 operator+(const vector4& vector) const
	{
		return vector4(x + vector.x, y + vector.y, z + vector.z, w + vector.w);
	}

	vector4 operator-(const vector4& vector) const
	{
		return vector4(x - vector.x, y - vector.y, z - vector.z, w - vector.w);
	}

	vector4 operator-() const
	{
		return vector4(-x, -y, -z, -w);
	}

	vector4 operator*(float number) const
	{
		return vector4(x * number, y * number, z * number, w * number);
	}

	vector4 operator/(float number) const
	{
		return vector4(x / number, y / number, z / number, w / number);
	}

	vector4& operator+=(const vector4& vector)
	{
		x += vector.x;
		y += vector.y;
		z += vector.z;
		w += vector.w;
		return *this;
	}

	vector4& operator-=(const vector4& vector)
	{
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
		w -= vector.w;
		return *this;
	}

	vector4& operator*=(float number)
	{
		x *= number;
		y *= number;
		z *= number;
		w *= number;
		return *this;
	}

	vector4& operator/=(float number)
	{
		x /= number;
		y /= number;
		z /= number;
		w /= number;
		return *this;
	}
};

struct matrix
{
	vector4 vec0;
	vector4 vec1;
	vector4 vec2;
	vector4 vec3;
};










__forceinline float Calc3D_Dist(const Vector& Src, const Vector& Dst) {
	return my_sqrt(powFFFFFFFFFFFFFFFFFFFFFF(Src.x - Dst.x) + powFFFFFFFFFFFFFFFFFFFFFF(Src.y - Dst.y) + powFFFFFFFFFFFFFFFFFFFFFF(Src.z - Dst.z));
}

__forceinline float Dot(const Vector& Vec1, const Vector& Vec2) {
	return Vec1[0] * Vec2[0] + Vec1[1] * Vec2[1] + Vec1[2] * Vec2[2];
}




__forceinline float Calc2D_Dist_2(const vector2& Src, const vector2& Dst) {
	return my_sqrt(powFFFFFFFFFFFFFFFFFFFFFF(Src.x - Dst.x) + powFFFFFFFFFFFFFFFFFFFFFF(Src.y - Dst.y));
}


__forceinline float Distance3D(const Vector& Src, const Vector& Dst)
{
	return my_sqrt(powFFFFFFFFFFFFFFFFFFFFFF((Src.x - Dst.x), 2) + powFFFFFFFFFFFFFFFFFFFFFF((Src.y - Dst.y), 2) + powFFFFFFFFFFFFFFFFFFFFFF((Src.z - Dst.z), 2));
}


__forceinline vector2 CalcAngle(const Vector& Src, const Vector& Dst) {
	Vector dir = Src - Dst;

	return vector2{ RAD2DEG(m_asin(dir.y / dir.Length())), RAD2DEG(-m_atan2(dir.x, -dir.z)) };
}


class Quaternion {
public:
	float x, y, z, w;

	Quaternion() {
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
		this->w = 0.0f;
	}

	Quaternion(float x, float y, float z, float w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	Quaternion operator*(Quaternion rhs) {
		return Quaternion(
			this->w * rhs.x + this->x * rhs.w + this->y * rhs.z - this->z * rhs.y,
			this->w * rhs.y + this->y * rhs.w + this->z * rhs.x - this->x * rhs.z,
			this->w * rhs.z + this->z * rhs.w + this->x * rhs.y - this->y * rhs.x,
			this->w * rhs.w - this->x * rhs.x - this->y * rhs.y - this->z * rhs.z
		);
	}

	float Dot(Quaternion b) {
		return x * x + y * y + z * z + w * w;
	}

	Vector operator*(Vector point) {
		float num = this->x * 2.f;
		float num2 = this->y * 2.f;
		float num3 = this->z * 2.f;
		float num4 = this->x * num;
		float num5 = this->y * num2;
		float num6 = this->z * num3;
		float num7 = this->x * num2;
		float num8 = this->x * num3;
		float num9 = this->y * num3;
		float num10 = this->w * num;
		float num11 = this->w * num2;
		float num12 = this->w * num3;
		Vector result;
		result.x = (1.f - (num5 + num6)) * point.x + (num7 - num12) * point.y + (num8 + num11) * point.z;
		result.y = (num7 + num12) * point.x + (1.f - (num4 + num6)) * point.y + (num9 - num10) * point.z;
		result.z = (num8 - num11) * point.x + (num9 + num10) * point.y + (1.f - (num4 + num5)) * point.z;
		return result;
	}
};

namespace Math {

	void Normalize(float& Yaw, float& Pitch) {
		if (Pitch < -89) Pitch = -89;
		else if (Pitch > 89) Pitch = 89;
		if (Yaw < -360) Yaw += 360;
		else if (Yaw > 360) Yaw -= 360;
	}
	float NormalizeAngle(float angle) {
		while (angle > 360.0f) {
			angle -= 360.0f;
		}
		while (angle < 0.0f) {
			angle += 360.0f;
		}
		return angle;
	}

	Vector NormalizeAngles(Vector angles) {
		angles.x = NormalizeAngle(angles.x);
		angles.y = NormalizeAngle(angles.y);
		return angles;
	}



	Vector EulerAngles(Quaternion q1) {
		float num = q1.w * q1.w;
		float num2 = q1.x * q1.x;
		float num3 = q1.y * q1.y;
		float num4 = q1.z * q1.z;
		float num5 = num2 + num3 + num4 + num;
		float num6 = q1.x * q1.w - q1.y * q1.z;
		Vector vector;
		if (num6 > 0.4995f * num5) {
			vector.y = 2.0f * m_atan2(q1.y, q1.x);
			vector.x = 1.57079637f;
			vector.z = 0.0f;
			return NormalizeAngles(vector * 57.2958f);
		}
		if (num6 < -0.4995f * num5) {
			vector.y = -2.0f * m_atan2(q1.y, q1.x);
			vector.x = -1.57079637f;
			vector.z = 0.0f;
			return NormalizeAngles(vector * 57.2958f);
		}
		Quaternion quaternion = Quaternion(q1.w, q1.z, q1.x, q1.y);
		vector.y = m_atan2(2.0f * quaternion.x * quaternion.w + 2.0f * quaternion.y * quaternion.z, 1.0f - 2.0f * (quaternion.z * quaternion.z + quaternion.w * quaternion.w));
		vector.x = m_asin(2.0f * (quaternion.x * quaternion.z - quaternion.w * quaternion.y));
		vector.z = m_atan2(2.0f * quaternion.x * quaternion.y + 2.0f * quaternion.z * quaternion.w, 1.0f - 2.0f * (quaternion.y * quaternion.y + quaternion.z * quaternion.z));
		return NormalizeAngles(vector * 57.2958f);
	}
}


char* itoa(int m_iValue, char* m_pBuffer, int m_iRadix)
{
	auto xtoa = [](int a1, char* a2, int a3, bool a4) -> char
	{
		char* v5; // r10
		char* v6; // r8
		char* v7; // r11
		char* v8; // r9
		unsigned int v9; // edx
		char v10; // al
		char result; // al
		char v12; // cl

		v5 = a2;
		if (a4)
		{
			v5 = a2 + 1;
			*a2 = 45;
			a1 = -a1;
		}
		v6 = v5;
		do
		{
			v7 = v5 + 1;
			v8 = v5;
			v9 = a1 % a3;
			a1 /= a3;
			v10 = 87;
			if (v9 <= 9)
				v10 = 48;
			*v5++ = v9 + v10;
		} while (a1);
		*v7 = 0;
		do
		{
			result = *v6;
			v12 = *v8;
			*v8-- = *v6;
			*v6++ = v12;
		} while (v6 < v8);
		return result;
	};

	bool v3; // r9

	v3 = false;
	if (m_iRadix == 10 && m_iValue < 0)
		v3 = true;
	xtoa(m_iValue, m_pBuffer, m_iRadix, v3);
	return m_pBuffer;
}

void AnsiToUnicode(const char* m_szAnsi, wchar_t* m_pBuffer)
{
	for (int i = 0; ; ++i)
	{
		m_pBuffer[i] = static_cast<char>(m_szAnsi[i]);

		if (!m_szAnsi[i])
			return;
	}
}