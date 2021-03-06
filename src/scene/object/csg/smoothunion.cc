//
// Created by mehdi on 11/03/2020.
//

#include "smoothunion.hh"
#include <functional>

SmoothUnion::SmoothUnion(std::vector<Object*> objects, double smoothfactor)
{
    this->objects_ = objects;
    this->k_ = smoothfactor;
}

double SmoothUnion::smoothmin(double a, double b, double k)
{
    double h = std::max(k - std::abs(a - b), 0.0) / k;
    return std::min(a, b) - h * h * h * k * (1.0 / 6.0);
}

double SmoothUnion::distance(Vector3 point) {
    std::vector<double> distances = std::vector<double>();
    for (auto & object : this->objects_)
        distances.push_back(object->distance(point));

    // Can be change or even passed as parameter
    double k = this->k_;

    std::function<double(double, double)> accumulator = [k](double a, double b) -> double
    {
        return SmoothUnion::smoothmin(a, b, k);
    };

    return std::accumulate(distances.begin() + 1,
                           distances.end(),
                           distances.front(),
                           accumulator);
}
