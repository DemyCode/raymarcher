//
// Created by mehdi on 11/03/2020.
//

#include "smoothunion.hh"

SmoothUnion::SmoothUnion(std::vector<Object*> objects)
{
    this->objects_ = objects;
}

double SmoothUnion::smoothmin(double a, double b)
{
    double k = 2.5;
    double h = std::max(k - std::abs(a - b), 0.0) / k;
    return std::min(a, b) - h * h * h * k * ( 1.0 / 6.0);
}

double SmoothUnion::distance(Vector3 point) {
    std::vector<double> distances = std::vector<double>();
    for (auto & object : this->objects_)
        distances.push_back(object->distance(point));
    return std::accumulate(distances.begin() + 1,
                           distances.end(),
                           distances.front(),
                           &SmoothUnion::smoothmin);
}
