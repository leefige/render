//
// Created by Liyf on 2017/5/27.
//

#ifndef RENDER_FLOAT3_H
#define RENDER_FLOAT3_H

#include <cmath>


class float3 {
public:
    double x, y, z;

    float3();
    float3(double x, double y, double z);

    /*------------------Operators---------------------*/

    bool operator==(const float3 &rhs) const;
    bool operator!=(const float3 &rhs) const;
    float3& operator = (const float3 &f);

    float3 operator + (const float3 & f) const;
    float3 operator - (const float3 & f) const;
    float3 operator * (double r) const;
    double operator *(const float3 &f) const;

    double dot(const float3 &f) const;
    float3 normalize() const;
    float3 cross(const float3 &f) const;
};

float3 operator * (double r, const float3& f);


#endif //RENDER_FLOAT3_H
