//
// Created by mehdi on 11/02/2020.
//

#include "camera.hh"

Camera::Camera(Vector3 location, Vector3 target, Vector3 upvector, double anglex, double angley, double zmin) {
    this->location_ = location;
    this->target_ = target;
    this->upvector_ = upvector;
    this->anglex_ = anglex;
    this->angley_ = angley;
    this->zmin_ = zmin;
}
