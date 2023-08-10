# vec2
2D euclidean vector class using float values

## features
- ### dual cartesian / polar representation
```c++
vec2 v1{4.21f,7.5f};
float x = v1.x();
float y = v1.y();
float length = v1.magnitude();
float angle = v1.angle();

const float pi = 3.14159274101257324219;
vec2 v2 = vec2::from_polar(0,pi/6.0f);
```
- ### vector sum and difference
```c++
vec2 v1{3,4};
vec2 v2{5,6};
vec3 v3{1,1};
vec2 v4 = v1 + v2 - v3;         // v4 is (7,9)
```
- ### multiplication and division by a scalar
```c++
vec2 v1{4,10};
vec2 v2 = 1 * 3.0f;             // v2 is (12,30)
v2 /= 2.0 f;                    // v2 is now (6,15)  
```
- ### rotation
```c++
const float pi = 3.14159274101257324219;
vec2 v1{1,1};
vec2 v2 = v1 << (pi/2.0f);      // counter-clockwise rotation: v2 is (-1,1)
vec2 v3 = v1 >> (pi/2.0f);      // clockwise rotation: v3 is (1,-1)
```
- ### opposite vector
```c++
    vec2 v = - vec2{4,-8}           // v is (-4,8)
```
- ### normalization
```c++
vec2 v{-12,0};
v.normalize();                  // v is now (-1,0)
```
- ### scalar product (aka dot product)
```c++
vec2 v1{4,6};
vec2 v2{2.5,7};
float p = v1 * v2;              // p is 52.0 
```
- ### extraction to std::ostream
```c++
#include <iostream>

vec2 v;
std::cout << v;                 // output: (0,0)
```

## what is missing:
- equality / inequality operations are notoriously tricky to get right when dealing with floating point values.
If you need them, just implement them as free function operator overloads using a technique that suits your needs:
```c++
    bool operator==(const vec2 & v1, const vec2 & v2)
    {
        // your code here
    }

    bool operator!=(const vec2 & v1, const vec2 & v2)
    {
        return ! (v1 == v2);
    }
```
- relational operators (`<`,`<=`,`>`,`>=`) as they do not really have a widely accepted meaning for 2d vectors. If you need them, just implement them as free function operator overloads.


## License

Distributed under the MIT License. See LICENSE.txt for more information.


## Contact

[https://github.com/stray-kan/vec2d](https://github.com/stray-kan/vec2d)
