//
// Created by mehdi on 11/03/2020.
//

#ifndef RAYMARCHER_CUBE_HH
#define RAYMARCHER_CUBE_HH


#include <scene/object/object.hh>

class Box : public Object {
    Box();
    virtual double distance(Vector3 point) override;
};


#endif //RAYMARCHER_CUBE_HH
