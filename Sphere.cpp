//
// Created by Liyf on 2017/5/27.
//


#include "Sphere.h"

#define eps 1e-4

double sgn(double x);

Sphere::Sphere(const float3 &pos, double r, Material *mat) : Object(pos, mat), r(r) {}

double Sphere::inter(Light light) {
    float3 v = pos - light.pos;
    double b = v * light.direct;
    double det = b * b - v * v + r * r;
    if (det < 0) return -1;
    else det = sqrt(det);
    double ans;
    if (b - det > eps)
        ans = b - det;
    else if (b + det > eps)
        ans = b + det;
    else
        ans =  -1;

    if (ans > eps) {
        n = (light.pos + light.direct * ans - pos).normalize();
        isIn = (light.direct * n > 0);
    }
    return ans;
}

Color Sphere::getColor() {
    if(mater->isPure)
    {
        return mater->getColor();
    }
    else
    {
        double a = acos(sgn(-(n * float3(0, 0, 1))));
        double b = sin(a) == 0 ? 1 : acos(sgn(min(max(n * float3(0, 1, 0) / sin(a), -1.0), 1.0)));
        double u = a / M_PI, v = b / 2 / M_PI;

        if (n * float3(1, 0, 0) < 0)
            v = 1 - v;
        return mater->getColor(u, v);
    }
}

double sgn(double x) {
    if (x > 1) return 1;
    if (x < -1) return -1;
    return x;
}
