//
// Created by Liyf on 2017/5/27.
//

#ifndef RAY_TRACING_SPHERE_H
#define RAY_TRACING_SPHERE_H

#include "Object.h"
#include "Grain.h"
#include <cmath>

class Sphere: public Object {
public:
    double r;

    Sphere(const float3& pos, double r, Material* mat);

    double inter(Light light);
    Color getColor();
};

#endif //RENDER_SPHERE_H
