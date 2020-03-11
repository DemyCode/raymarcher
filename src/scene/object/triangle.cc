//
// Created by mehdi on 28/02/2020.
//

#include "triangle.hh"

Triangle::Triangle(Vertex a, Vertex b, Vertex c, TextureMaterial *textureMaterial) {
    this->a_ = a;
    this->b_ = b;
    this->c_ = c;
    this->textureMaterial_ = textureMaterial;
}

double Triangle::distance(Vector3 point) {
    //TODO
    (void) point;
    return 0;
}