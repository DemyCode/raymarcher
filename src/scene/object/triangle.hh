//
// Created by mehdi on 28/02/2020.
//

#ifndef RAYTRACER_TRIANGLE_HH
#define RAYTRACER_TRIANGLE_HH


#include <scene/object/object.hh>
#include <utils/vertex.hh>

class Triangle : public Object {
public:
    Triangle(Vertex a, Vertex b, Vertex c, TextureMaterial *textureMaterial);
    double distance(Vector3 point) override;
private:
    bool isintriangle(Vector3 point);
    bool sameside(Vector3 a, Vector3 b, Vector3 c, Vector3 point);
    Vertex a_;
    Vertex b_;
    Vertex c_;
};


#endif //RAYTRACER_TRIANGLE_HH
