#include "Bezier.h"
#include "Camera.h"
#include "PathTracing.h"
#include "Sphere.h"
#include "PureColor.h"

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    if(argc != 2)
    {
        printf("Please specify sample size:\n%s sample_size\n", argv[0]);
        return 1;
    }
    int smpl = atoi(argv[1]);

    Scene scene;
    Render* render = new PathTracing;
    Camera camera(1024, 768, float3(50, 52, 295.6), float3(0, -0.042612, -1).normalize(), 0.5312, smpl, render);

    Material* sp1_m = new Grain(DIFFUSE, "../grain/wood.jpg");
    Sphere sphere1(float3(27, 9, 90), 9, sp1_m);

    Material* sp2_m = new PureColor(REFRACTIVE, Color(200, 200, 200));
    Sphere sphere2(float3(73,17,78), 17, sp2_m);

    Material* sp3_m = new PureColor(SPECULAR, Color(200, 200, 200));
    Sphere sphere3(float3(27,15,37), 15, sp3_m);

    Material* lt_m = new PureColor(DIFFUSE, Color(), Color(5000, 5000, 5000));
    Sphere light(float3(50,681.6-.27,81.6), 600, lt_m);

    Material* lw_m = new PureColor(DIFFUSE, Color(200, 100, 100));
    Sphere left(float3(1e5+1,40.8,81.6), 1e5, lw_m);

    Material* rw_m = new PureColor(DIFFUSE, Color(200, 100, 200));
    Sphere right(float3(-1e5+99,40.8,81.6), 1e5, rw_m);

    Material* bw_m = new PureColor(DIFFUSE, Color(200, 200, 200));
    Sphere back(float3(50,40.8, 1e5), 1e5, bw_m);

    Material* fw_m = new PureColor(DIFFUSE, Color(0, 0, 0));
    Sphere front(float3(50,40.8,-1e5+170), 1e5, fw_m);

    Sphere bot(float3(50, 1e5, 81.6), 1e5, bw_m);

    Sphere top(float3(50,-1e5+81.6,81.6), 1e5, bw_m);

    scene.addObj(&sphere1);
    scene.addObj(&sphere2);
    scene.addObj(&sphere3);
    scene.addObj(&light);
    scene.addObj(&left);
    scene.addObj(&right);
    scene.addObj(&back);
    scene.addObj(&front);
    scene.addObj(&bot);
    scene.addObj(&top);

    camera.takePhoto(&scene);
    Mat photo = camera.printPhoto();
    stringstream ss; string ptr;
    ss << int(&photo); ss >> ptr;
    string out_path = string("../img/pic-") + ptr + string(".png");
    imwrite(out_path, photo);

    delete sp1_m;
    delete sp2_m;
    delete sp3_m;
    delete lw_m;
    delete rw_m;
    delete lt_m;
    delete bw_m;
    delete fw_m;
    delete render;

    return 0;
}