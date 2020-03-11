//
// Created by mehdi on 11/02/2020.
//

#include "pointlight.hh"


PointLight::PointLight(Vector3 position, double intensity, ColorRGB colorRgb) {
    this->position_ = position;
    this->intensity_ = intensity;
    this->colorRgb_ = colorRgb;
}

Vector3 PointLight::getPos() {
    return this->position_;
}