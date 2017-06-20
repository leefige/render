//
// Created by Liyf on 2017/6/14.
//

#ifndef RENDER_PATHTRACING_H
#define RENDER_PATHTRACING_H

#include "Render.h"
#include "Object.h"
#include "Light.h"
#include <vector>

class PathTracing: public Render {
    bool* completeThread;

public:
    Color tracing(Light light, int depth, vector<Object *> &objs);
    void rendering(int h, int w, float3 fx, float3 fy, float3 pos, float3 direct,
                   vector<Object *> &objs, Film &film, int samples);
};

#endif //RENDER_PATHTRACING_H
