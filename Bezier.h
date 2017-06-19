//
// Created by Liyf on 2017/5/27.
//

#ifndef RENDER_BEZIER_H
#define RENDER_BEZIER_H

#include "int4.h"
#include "float3.h"

#include <opencv2/opencv.hpp>
#include <cmath>

using namespace cv;
using namespace std;

class Bezier{
    int n, m;  //curve control points: range[0, n]; surface: range[0, m]

    float3 ** p;
public:
    vector<float3> points;               // points

    vector<int4> meshes;                 // surfaces

    Bezier(int _n, int _m);

    virtual ~Bezier();

    double Bernstein(int i, int n, float t);

    float3 plotPoint(float u, float v);

    void BezierMesh(float du = 0.01f, float dv = 0.01f);
};

#endif //RENDER_BEZIER_H
