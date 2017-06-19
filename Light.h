//
// Created by Liyf on 2017/5/27.
//

#ifndef RENDER_LIGHT_H
#define RENDER_LIGHT_H

#include "float3.h"

struct Light {
    float3 pos, direct;

    Light(const float3 &pos, const float3 &direct) : pos(pos), direct(direct) {}
};

#endif //RENDER_LIGHT_H
