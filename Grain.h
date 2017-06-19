//
// Created by Liyf on 2017/5/27.
//

#ifndef RENDER_GRAIN_H
#define RENDER_GRAIN_H

#include <opencv2/opencv.hpp>
#include "Material.h"

using namespace cv;

class Grain : public Material {
    Mat grain;
public:
    Grain(ReflectType ref, char* pic_path):
    Material(ref, Color())
    {
        grain = imread(pic_path);
        isPure = 0;
    }

    Color getEmit() { return Color();}
    ReflectType getRefType() { return ref_type;}

    Color getColor()
    {
        return Color();
    }

    Color getColor(double x, double y)
    {
        int xpos = int(x * grain.rows);
        int ypos = int(y * grain.cols);
        Vec3b color = grain.at<Vec3b>(xpos, ypos);
        return Color(color[2], color[1], color[0]);
    }
};


#endif //RENDER_GRAIN_H
