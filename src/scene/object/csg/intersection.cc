//
// Created by mehdi on 11/03/2020.
//


#include "intersection.hh"

Intersection::Intersection(std::vector<Object *> objects) {
    this->objects_ = objects;
}

double max(double a, double b)
{
    return std::max(a, b);
}

double Intersection::distance(Vector3 point) {
    std::vector<double> distances = std::vector<double>();
    for (auto & object : this->objects_)
        distances.push_back(object->distance(point));
    return std::accumulate(distances.begin() + 1,
                           distances.end(),
                           distances.front(),
                           max);
}