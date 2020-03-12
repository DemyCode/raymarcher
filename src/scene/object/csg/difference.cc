//
// Created by mehdi on 12/03/2020.
//

#include "difference.hh"

Difference::Difference(Object *a, Object *b) {
    this->a_ = a;
    this->b_ = b;
}

double Difference::distance(Vector3 point) {
    return std::max(a_->distance(point), -b_->distance(point));
}
