//
// Created by mehdi on 11/03/2020.
//

#include "intersection.hh"

Intersection::Intersection(std::vector<Object*> objects)
{
    this->objects_ = objects;
}

double Intersection::distance(Vector3 point) {
    double maxdist = -std::numeric_limits<double>::infinity();
    for (auto & object : this->objects_)
    {
        double objdist = object->distance(point);
        if (objdist > maxdist)
            maxdist = objdist;
    }
    return maxdist;
}
