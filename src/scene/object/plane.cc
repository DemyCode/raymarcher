//
// Created by mehdi on 19/02/2020.
//

#include "plane.hh"

Plane::Plane(Vector3 point, Vector3 normal, TextureMaterial* textureMaterial)
{
    this->point_ = point;
    this->normal_ = normal.normalize();
    this->textureMaterial_ = textureMaterial;
}

double Plane::distance(Vector3 point) {
    //TODO
    (void) point;
    return 0;
}