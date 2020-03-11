//
// Created by mehdi on 11/02/2020.
//

#ifndef RAYTRACER_TEXTUREMATERIAL_HH
#define RAYTRACER_TEXTUREMATERIAL_HH

#include <tuple>

#include <utils/vector3.hh>
#include <utils/color.hh>

class TextureMaterial {
public:
    virtual double getTextureKs(Vector3 point) = 0;
    virtual double getTextureKd(Vector3 point) = 0;
    virtual ColorRGB getTextureColor(Vector3 point) = 0;
    virtual double getTextureNs(Vector3 point) = 0;
};


#endif //RAYTRACER_TEXTUREMATERIAL_HH
