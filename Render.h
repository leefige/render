//
// Created by Liyf on 2017/6/13.
//

#ifndef RENDER_RAYTRACING_H
#define RENDER_RAYTRACING_H

#define MAX_DISTANCE 1e30

#include "Light.h"
#include "Object.h"
#include "Film.h"
#include <vector>

using namespace std;

class Render {
public:

    virtual void rendering(int h, int w, float3 fx, float3 fy, float3 pos, float3 direct,
                           vector<Object *> &objs, Film &film, int samples) = 0;

    bool inter(Light light, int &obj_index, double &distance, vector<Object *> &objs) {
        double d;
        distance = MAX_DISTANCE;
        int i = 0;
        for (Object* obj: objs) {
            d = obj->inter(light);
            if (d > 0 && d < distance) {
                distance = d;
                obj_index = i;
            }
            i++;
        }
        return distance < MAX_DISTANCE;
    }
};

#endif //RENDER_RAYTRACING_H
