//
// Created by Liyf on 2017/5/27.
//

#ifndef RENDER_OBJECT_H
#define RENDER_OBJECT_H

#define M_PI 3.1415926535898

#include "Light.h"
#include "Color.h"
#include "Material.h"

class Object {
public:
    float3 pos;
    float3 n;
    bool isIn;
    double nt;
    Material* mater;

    Object(const float3 &pos, Material* mat) :pos(pos), mater(mat), nt(1.5) {}

    virtual double inter(Light light) = 0;
    virtual Color getColor() { return mater->getColor();}
    virtual Color getColor(double x, double y) { return mater->getColor(x, y);}
    virtual Color getEmit() { return mater->getEmit();}
    virtual ReflectType getRefType() { return mater->getRefType();}
};

#endif //RENDER_OBJECT_H
