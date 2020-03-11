//
// Created by mehdi on 11/02/2020.
//

#include "sphere.hh"

Sphere::Sphere(Vector3 center, double r, TextureMaterial *textureMaterial) {
    this->center_ = center;
    this->r_ = r;
    this->textureMaterial_ = textureMaterial;
}

double Sphere::distance(Vector3 point) {
    return point.dist(this->center_) - this->r_;
}