//
// Created by mehdi on 11/02/2020.
//

#ifndef RAYTRACER_LIGHT_HH
#define RAYTRACER_LIGHT_HH

#include <utils/vector3.hh>
#include <utils/color.hh>

class Light {
public:
    double getIntensity();
    ColorRGB getColorRgb();
protected:
    double intensity_;
    ColorRGB colorRgb_;
};


#endif //RAYTRACER_LIGHT_HH
