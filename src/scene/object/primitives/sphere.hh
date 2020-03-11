//
// Created by mehdi on 11/02/2020.
//

#ifndef RAYTRACER_SPHERE_HH
#define RAYTRACER_SPHERE_HH

#include <scene/object/object.hh>

class Sphere : public Object
{
public:
    Sphere(Vector3 center, double r, TextureMaterial *textureMaterial);
    Sphere(Sphere const &) = default;
    Sphere() = default;
    double distance(Vector3 point) override;
private:
    Vector3 center_;
    double r_;
};


#endif //RAYTRACER_SPHERE_HH
