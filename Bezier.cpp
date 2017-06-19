//
// Created by Liyf on 2017/5/27.
//

#include "Bezier.h"

Bezier::Bezier(int _n, int _m): n(_n), m(_m)
{
    p = new float3* [_n + 1];
    for(int i = 0; i <= _n; i++)
    {
        p[i] = new float3[_m + 1];
    }
    for(int i = 0; i <= n; i++)
    {
        printf("\nInput line %d:\n", i);
        for(int j = 0; j <= m; j++)
        {
            printf("Point %d: ", j);
            scanf("%f %f %f", &p[i][j].x, &p[i][j].y, &p[i][j].z);
        }
    }
}

Bezier::~Bezier()
{
    if(p) {
        for(int i = 0; i <= n; i++) {
            if(p[i])  {
                delete[] p[i];
            }
        }
        delete[] p;
    }
}
double Bezier::Bernstein(int i, int n, float t)
{
    if(n == 0)
    {
        return 0;
    }
    if(i == 0)
    {
        return pow(1-t, n);
    }
    if(i > n/2 + 1)
    {
        return Bernstein(n-i, n, 1-t);  //symmetry
    }
    return (1-t) * Bernstein(i, n-1, t) + t * Bernstein(i-1, n-1, t);
}

float3 Bezier::plotPoint(float u, float v)
{
    float3 * sum = new float3;
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            *sum = *sum + p[i][j] * Bernstein(i, m, u) * Bernstein(j, n, v);
        }
    }
    //printf("Point: %f %f %f\n", sum->x, sum->y, sum->z);
    return *sum;
}

void Bezier::BezierMesh(float du, float dv) // du, dv: density
{
    int nu = int(1 / du + 1);
    int nv = int(1 / dv + 1);               // nums
    int pid = 0;                            // point id
    for (float u = 0.0f, i = 0; u <= 1.0f; u += du, i++) {
        for (float v = 0.0f, j = 0; v <= 1.0f; v += dv, j++) {
            points.push_back(plotPoint(u, v));  // create point
            pid++;                              // id start from 1
            if (i != 0 && j != 0) {
                meshes.push_back(int4(pid-nv-1, pid-nv, pid, pid-1));
            }
        }
        printf("%.2f%%...", u*100);
    }

    FILE* fp = fopen("../mesh/mesh.obj", "w");
    if(!fp) {
        printf("Failed to open the file\n");
        return;
    }
    printf("Writing file...\n");
    int len = points.size();
    for(int i = 0; i < len; i++) {
        fprintf(fp, "v %f %f %f\n", points[i].x, points[i].y, points[i].z);
        fprintf(fp, "f %d %d %d %d\n", meshes[i].x0, meshes[i].x1, meshes[i].x2, meshes[i].x3);
    }
    fclose(fp);
    printf("Finished!\n");
    return;
}