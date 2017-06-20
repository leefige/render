//
// Created by Liyf on 2017/6/14.
//

#ifndef RENDER_PATHTRACING_H
#define RENDER_PATHTRACING_H

#include "Render.h"
#include "Object.h"
#include "Light.h"
#include <vector>

#define MAX_THREADS 8

class PathTracing: public Render {
    bool* completeThread;
    int h, w;
    float3 fx, fy, pos, direct;
    vector<Object *> *objs;
    Film *film;
    int samples;

public:
    Color tracing(Light light, int depth, vector<Object *> &objs);
    void rendering(int h, int w, float3 fx, float3 fy, float3 pos, float3 direct,
                   vector<Object *> &objs, Film &film, int samples);

    void
    sampling(int x, int y, int threadID);

    void multiSampling(int &y, int &x, bool &isFin);
};

#endif //RENDER_PATHTRACING_H
