//
// Created by Liyf on 2017/5/27.
//

#include "float3.h"

#include <cmath>

float3::float3(double x, double y, double z) : x(x), y(y), z(z) {}

float3::float3() {
    x = 0;
    y = 0;
    z = 0;
}

float3& float3::operator=(const float3 &f) {
    x = f.x;
    y = f.y;
    z = f.z;
    return *this;
}

float3 float3::operator+(const float3 &f) const {
    return float3(x + f.x, y + f.y, z + f.z);
}

float3 float3::operator*(double r) const {
    return float3(r * x, r * y, r * z);
}

bool float3::operator==(const float3 &rhs) const {
    return x == rhs.x &&
           y == rhs.y &&
           z == rhs.z;
}

bool float3::operator!=(const float3 &rhs) const {
    return !(rhs == *this);
}

float3 float3::operator-(const float3 &f) const {
    return float3(x - f.x, y - f.y, z - f.z);
}

double float3::dot(const float3 &f) const {
    return x * f.x + y * f.y + z * f.z;
}

float3 float3::cross(const float3 &f) const {
    return float3(y * f.z - z * f.y, z * f.x - x * f.z, x * f.y - y * f.x);
}

float3 float3::normalize() const {
    double mod = sqrtf(dot(*this));
    return *this * (1 / mod);
}

double float3::operator*(const float3 &f) const {
    return dot(f);
}

float3 operator*(double r, const float3 &f) {
    return f * r;
}
