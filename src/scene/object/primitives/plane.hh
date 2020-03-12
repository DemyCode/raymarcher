//
// Created by mehdi on 12/03/2020.
//

#ifndef RAYMARCHER_PLANE_HH
#define RAYMARCHER_PLANE_HH


#include <utils/vector3.hh>
#include <scene/object/object.hh>

class Plane : public Object{
public:
    Plane(Vector3 point, Vector3 normal);
    double distance(Vector3 point) override;
private:
    Vector3 point_;
    Vector3 normal_;
};


#endif //RAYMARCHER_PLANE_HH
