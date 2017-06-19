//
// Created by Liyf on 2017/5/27.
//

#ifndef RENDER_MATERIAL_H
#define RENDER_MATERIAL_H

#include "Color.h"

enum ReflectType {DIFFUSE, SPECULAR, REFRACTIVE};

class Material {
public:
    ReflectType ref_type;
    Color color;
    Color emit;
    bool isPure;

    Material(ReflectType ref, const Color& co, const Color& em = Color()):
            ref_type(ref), color(co), emit(em), isPure(1) {}
    virtual ~Material(){}

    virtual Color getColor() = 0;
    virtual Color getColor(double x, double y) = 0;
    virtual Color getEmit() = 0;
    virtual ReflectType getRefType() = 0;
};


#endif //RENDER_MATERIAL_H
