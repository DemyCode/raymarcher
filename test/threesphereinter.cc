//
// Created by mehdi on 11/02/2020.
//

#include <iostream>
#include <cmath>

#include <utils/vector3.hh>
#include <scene/scene.hh>
#include <scene/object/object.hh>
#include <scene/light/pointlight.hh>
#include <utils/image.hh>
#include <scene/texture/uniformtexture.hh>
#include <scene/object/primitives/sphere.hh>
#include <chrono>
#include <scene/object/csg/union.hh>
#include <scene/object/csg/intersection.hh>
#include <scene/object/csg/smoothunion.hh>


int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    auto *shinyred = new UniformTexture(0.2, 1, ColorRGB("red"), 1);
    Sphere sphere1 = Sphere(Vector3(50, 0, -5), 10, shinyred);
    Sphere sphere2 = Sphere(Vector3(50, 0, 5), 10, shinyred);
    Sphere sphere3 = Sphere(Vector3(50, 10, 0), 10, shinyred);
    std::vector<Object*> objects = std::vector<Object*>();
    objects.push_back(&sphere1);
    objects.push_back(&sphere2);
    objects.push_back(&sphere3);
    Union anUnion = Union(objects);
    Intersection intersection = Intersection(objects);
    SmoothUnion smoothUnion = SmoothUnion(objects);

    PointLight light2 = PointLight(Vector3(-500, 100, -500), 1, ColorRGB("white"));
    std::vector<PointLight*> lights = std::vector<PointLight*>();
    lights.push_back(&light2);

    double anglex = 90;
    double angley = 60;
    double zmin = 10;
    int bounces = 1;

    Vector3 location = Vector3(0, 10, 0);
    Vector3 targetv = Vector3(1, 0, 0);
    Vector3 upvector = Vector3(0, 1, 0);
    Camera camera = Camera(location, targetv, upvector, anglex, angley, zmin);

    targetv = targetv.normalize();
    upvector = upvector.normalize();
    Vector3 leftv = targetv.cross(upvector).normalize();
    double halfscreensizex = std::tan((camera.getAnglex() / 2.0) * (M_PI / 180)) * zmin;
    double halfscreensizey = std::tan((camera.getAngley() / 2.0) * (M_PI / 180)) * zmin;

    Scene scene = Scene(&intersection, lights, camera);

    int width = 1920;
    int height = 1080;

    Image image = Image(width, height);
    for (int i = 0; i < height; i++)
    {
        #pragma omp parallel for
        for (int j = 0; j < width; j++)
        {
            Vector3 origin = camera.getLocation();
            Vector3 screenpoint = origin + (targetv * zmin);
            double wid2 = width / 2;
            double hei2 = height / 2;
            Vector3 leftpoint = screenpoint + (leftv * halfscreensizex * ((j - wid2) / wid2));
            Vector3 uppoint = leftpoint + (upvector * halfscreensizey * ((i - hei2) / hei2));
            Vector3 direction = uppoint - origin;
            Ray ray = Ray(origin, direction);
            ColorRGB colorRgb = scene.castRay(ray, bounces);
            image.setPixel(j, height - i - 1, colorRgb);
        }
        std::cout << "Treating : " << i * width << "/" << width * height << std::endl;
    }

    image.ppm_creator("output.ppm");

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Duration of the program : " << duration.count() / 1000000 << " secondes" << std::endl;
    return 0;
}
