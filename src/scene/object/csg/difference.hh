//
// Created by mehdi on 12/03/2020.
//

#ifndef RAYMARCHER_DIFFERENCE_HH
#define RAYMARCHER_DIFFERENCE_HH


#include <scene/object/object.hh>

class Difference : public Object {
public:
    Difference(Object *a, Object *b);
    double distance(Vector3 point) override;
private:
    Object* a_;
    Object* b_;
};


#endif //RAYMARCHER_DIFFERENCE_HH
