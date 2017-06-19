//
// Created by Liyf on 2017/5/27.
//

#ifndef RENDER_SCENE_H
#define RENDER_SCENE_H

#include "Object.h"
#include <vector>

#define M_PI 3.1415926535898

using namespace std;

class Scene {
public:
    vector<Object*> objs;

    void addObj(Object* obj) {
        objs.push_back(obj);
    }
};

#endif //RENDER_SCENE_H
