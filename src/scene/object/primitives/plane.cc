//
// Created by mehdi on 12/03/2020.
//

#include "plane.hh"

Plane::Plane(Vector3 point, Vector3 normal) {
    this->point_ = point;
    this->normal_ = normal;
}

double Plane::distance(Vector3 p) {
    Vector3 crossed = this->normal_;
    double A = crossed.getX();
    double B = crossed.getY();
    double C = crossed.getZ();
    return (A * (p.x_ - this->point_.x_) + B * (p.y_ - this->point_.y_) + C * (p.z_ - this->point_.z_)) /
    std::sqrt(A * A + B * B + C * C);
}
