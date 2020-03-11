//
// Created by mehdi on 11/02/2020.
//

#ifndef RAYTRACER_POINTLIGHT_HH
#define RAYTRACER_POINTLIGHT_HH

#include <scene/light/light.hh>

class PointLight : public Light {
public:
    explicit PointLight(Vector3 position, double intensity, ColorRGB colorRgb);
    Vector3 getPos();
private:
    Vector3 position_;
};


#endif //RAYTRACER_POINTLIGHT_HH
