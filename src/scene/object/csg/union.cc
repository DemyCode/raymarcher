//
// Created by mehdi on 11/03/2020.
//

#include "union.hh"

Union::Union(std::vector<Object*> objects)
{
    this->objects_ = objects;
}

double Union::distance(Vector3 point) {
    double mindist = std::numeric_limits<double>::infinity();
    for (auto & object : this->objects_)
    {
        double objdist = object->distance(point);
        if (objdist < mindist)
            mindist = objdist;
    }
    return mindist;
}
