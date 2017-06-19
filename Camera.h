//
// Created by Liyf on 2017/6/17.
//

#ifndef RENDER_CAMERA_H
#define RENDER_CAMERA_H

#include "Scene.h"
#include "Film.h"
#include "float3.h"
#include "Render.h"
#include <opencv2/opencv.hpp>

using namespace cv;

class Camera {
    int w, h;
    float3 pos;
    float3 direct;
    double f_len;
    int samples;

    Film film;
    Render* render;

    uchar regularizeColor(double x) const;

public:
    Camera(int width, int height, const float3 &pos, const float3 &dir, double f_len, int samples, Render *render) :
            pos(pos), direct(dir), w(width),
            h(height), film(width, height), samples(samples), render(render), f_len(f_len) {}

    Mat printPhoto() const;

    void takePhoto(Scene *scene);
};

uchar Camera::regularizeColor(double x) const {
    double color = x;
    if (x > 255)
        color = 255;
    if (x < 0)
        color = 0;
    return uchar(pow(color / 255, (1 / 2.2)) * 255 + 0.5);
}

Mat Camera::printPhoto() const {
    Mat mat(h, w, CV_8UC3);
    for (int i = 0; i < w; i++)
        for (int j = 0; j < h; j++) {
            mat.at<Vec3b>(j, i)[0] = regularizeColor(film.c[j * w + i].b);
            mat.at<Vec3b>(j, i)[1] = regularizeColor(film.c[j * w + i].g);
            mat.at<Vec3b>(j, i)[2] = regularizeColor(film.c[j * w + i].r);
        }
    return mat;
}

void Camera::takePhoto(Scene *scene) {
    float3 cx = float3(w * f_len / h, 0, 0);
    float3 cy = cx.cross(direct).normalize() * f_len;
    unsigned int seed = int(&cx) * int(&cy);
    srand(seed);
    render->rendering(h, w, cx, cy, pos, direct, scene->objs, film, samples);
}

#endif //RENDER_CAMERA_H