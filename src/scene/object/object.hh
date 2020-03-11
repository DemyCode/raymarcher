//
// Created by mehdi on 11/02/2020.
//

#ifndef RAYTRACER_OBJECT_HH
#define RAYTRACER_OBJECT_HH

#include <optional>
#include <tuple>

#include <scene/texture/texturematerial.hh>
#include <utils/ray.hh>

class Object {
public:
    virtual double distance(Vector3 point) = 0;
    double getTextureKs(Vector3 point);
    double getTextureKd(Vector3 point);
    ColorRGB getTextureColor(Vector3 point);
    double getTextureNs(Vector3 point);

protected:
    TextureMaterial *textureMaterial_;
};


#endif //RAYTRACER_OBJECT_HH
