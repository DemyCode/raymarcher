//
// Created by mehdi on 11/02/2020.
//

#include "ray.hh"

Ray::Ray(Vector3 point, Vector3 direction) {
    this->point_ = point;
    this->direction_ = direction.normalize();
}

Vector3 Ray::getPoint() {
    return this->point_;
}

Vector3 Ray::getDirection() {
    return this->direction_;
}

void Ray::setPoint(Vector3 point) {
    this->point_ = point;
}

void Ray::setDirection(Vector3 direction) {
    this->direction_ = direction;
}
