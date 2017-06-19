//
// Created by Liyf on 2017/6/19.
//

#ifndef RENDER_PURECOLOR_H
#define RENDER_PURECOLOR_H


#include "Material.h"

class PureColor : public Material {
public:

    PureColor(ReflectType ref, const Color& co, const Color& em = Color()):
        Material(ref, co, em) {}

    Color getColor() { return color;}
    Color getColor(double x, double y) { return getColor();}
    Color getEmit() { return emit;}
    ReflectType getRefType() { return ref_type;}
};

#endif //RENDER_PURECOLOR_H
