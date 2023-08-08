#include "vec2.hpp"

#include <cassert>
#include <cmath>
#include <iostream>

vec2::vec2()
    : vec2(0.0f,0.0f)
{
}

vec2::vec2(float x, float y)
    : _x(x), _y(y)
{
}

vec2 vec2::from_polar(float angle, float magnitude)
{
    return {magnitude * std::cos(angle), magnitude * std::sin(angle)};
}

float vec2::x() const
{
    return _x;
}

float vec2::y() const
{
    return _y;
}

float vec2::angle() const
{
    return ( (_x == 0.0f && _y == 0.0f) ? 0.0f : std::atan2(_y,_x) );
}

float vec2::magnitude() const
{
    return std::hypot(_x,_y);
}

vec2 & vec2::operator+=(const vec2 & other)
{
    _x += other._x;
    _y += other._y;
    return *this;
}

vec2 & vec2::operator-=(const vec2 & other)
{
    _x -= other._x;
    _y -= other._y;
    return *this;
}

vec2 & vec2::operator*=(float a)
{
    _x *= a;
    _y *= a;
    return *this;
}

vec2 & vec2::operator/=(float a)
{
    assert( a != 0.0f );
    *this *= (1.0f / a);
    return *this;
}

vec2 & vec2::operator<<=(float angle)
{
    const auto cos = std::cos(angle);
    const auto sin = std::sin(angle);
    float new_x = _x * cos - _y * sin;
    float new_y = _x * sin + _y * cos;
    _x = new_x;
    _y = new_y;
    return *this;
}

vec2 & vec2::operator>>=(float angle)
{
    *this <<= -angle;
    return *this;
}

vec2 vec2::operator-() const
{
    return {-_x,-_y};
}

vec2 & vec2::normalize()
{
    *this /= magnitude();
    return *this;
}

// --non members--

vec2 operator+(vec2 v1, const vec2 & v2)
{
    v1 += v2;
    return v1;
}

vec2 operator-(vec2 v1, const vec2 & v2)
{
    v1 -= v2;
    return v1;
}

float operator*(const vec2 & v1, const vec2 & v2)
{
    return v1.x() * v2.x() + v1.y() * v2.y();
}

vec2 operator*(vec2 v, float a)
{
    v *= a;
    return v;
}

vec2 operator*(float a, const vec2 & v)
{
    return v * a;
}

vec2 operator/(vec2 v, float a)
{
    v /= a;
    return v;
}

vec2 operator<<(vec2 v, float angle)
{
    v <<= angle;
    return v;
}

vec2 operator>>(vec2 v, float angle)
{
    v >>= angle;
    return v;
}

std::ostream & operator<<(std::ostream & os, const vec2 & v)
{
    os << "(" << v.x() << "," << v.y() << ")";
    return os;
}

float angle_between(const vec2 & v1, const vec2 &v2)
{
    const float magn_1 = v1.magnitude();
    const float magn_2 = v2.magnitude();
    if ( magn_1 == 0.0f || magn_2 == 0.0f ) {
        return 0.0f;
    } else {
        return std::acos( v1 * v2 / magn_1 * magn_2 );
    }
}
