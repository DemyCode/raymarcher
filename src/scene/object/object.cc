//
// Created by mehdi on 11/02/2020.
//

#include "object.hh"

double Object::getTextureKs(Vector3 point) {
    return this->textureMaterial_->getTextureKs(point);
}

double Object::getTextureKd(Vector3 point) {
    return this->textureMaterial_->getTextureKd(point);
}

ColorRGB Object::getTextureColor(Vector3 point) {
    return this->textureMaterial_->getTextureColor(point);
}

double Object::getTextureNs(Vector3 point) {
    return this->textureMaterial_->getTextureNs(point);
}