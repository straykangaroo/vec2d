#ifndef VEC2_HPP
#define VEC2_HPP

#include <iosfwd>


/**
    2D euclidean vector class using float values.

    - dual cartesian / polar representation
    - available operations:
        - vector sum and difference
        - multiplication and division by a scalar
        - rotation
        - opposite vector
        - normalization
        - scalar product (aka dot product)
        - extraction to std::ostream
    
    - what is missing:
        - equality/inequality operations are notoriously tricky to implement with floating point values.
        If you need them, just implement them as free functions operator overloads using a technique that suits your needs:

        bool operator==(const vec2 & v1, const vec2 & v2)
        {
            // your code here
        }
        
        bool operator!=(const vec2 & v1, const vec2 & v2)
        {
            return ! (v1 == v2);
        }
        
        - relational operators (<,<=,>,>=) do not really have a widely accepted meaning for 2d vectors

*/
class vec2 {

public:
	// construct a zero-length ( i.e. [0,0] ) vector
	vec2();
	// construct from cartesian coordinates
    vec2(float x, float y);

    // return a vec2 built from polar coordinates. angle must be in radians.
	// @return	a vec2 built from polar coordinates
    static vec2 from_polar(float angle, float magnitude);

    // @return	x component
    float x() const;
    // @return	y component
    float y() const;

    // @return  this vector's angle in radians [-pi,pi]
    // @note    if x() == 0.0f && y() == 0.0f will return 0.0f
    float angle() const;
    // @return	magnitude
    float magnitude() const;

	// vector sum: add other to this vector
	// @return	this vector
    vec2 & operator+=(const vec2 & other);

    // vector difference: subtract other from this vector
    // @return	this vector
    vec2 & operator-=(const vec2 & other);

    // scalar multiplication: multiply this vector by a scalar
    // @return	this vector
    vec2 & operator*=(float a);

    // scalar division: divide this vector by a scalar (same as multiplying by 1/a)
    // @pre a != 0.0f
    vec2 & operator/=(float a);

    // vector rotation: rotate this vector counter-clockwise by angle [radians]
    // @return  this vector
    vec2 & operator<<=(float angle);

    // vector rotation: rotate this vector clockwise by angle [radians]
    // @return  this vector
    vec2 & operator>>=(float angle);

    // opposite vector
    // @return	the opposite vector
    vec2 operator-() const;

    // normalize this vector
    // @return  this vector
    vec2 & normalize();

private:
    float _x, _y;
};


// vector sum: add v1 and v2
vec2 operator+(vec2 v1, const vec2 & v2);
// vector subtraction: subtract v2 from v1
vec2 operator-(vec2 v1, const vec2 & v2);

// scalar product (aka dot product)
float operator*(const vec2 & v1, const vec2 & v2);

// scalar multiplication: multiply v by a
vec2 operator*(vec2 v, float a);
// scalar multiplication: multiply v by a
vec2 operator*(float a, const vec2 & v);

// scalar division: divide v by a (same as multiplying v by 1/a)
// @pre a != 0.0f
vec2 operator/(vec2 v, float a);

// rotate v by angle [radians] counter-clockwise
vec2 operator<<(vec2 v, float angle);

// rotate v by angle [radians] clockwise
vec2 operator>>(vec2 v, float angle);

// output v to os as (x,y)
std::ostream & operator<<(std::ostream & os, const vec2 & v);

// angle between two vectors. If one or both have zero length, return 0.0f
// @return  angle in [0,pi] [radians]
float angle_between(const vec2 & v1, const vec2 &v2);


#endif  // VEC2D_HPP
