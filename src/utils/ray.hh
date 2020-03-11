//
// Created by mehdi on 11/02/2020.
//

#ifndef RAYTRACER_RAY_HH
#define RAYTRACER_RAY_HH


#include <utils/vector3.hh>

class Ray {
public:
    Ray(Vector3 point, Vector3 direction);
    Vector3 getPoint();
    Vector3 getDirection();
    void setPoint(Vector3 point);
    void setDirection(Vector3 direction);
private:
    Vector3 point_;
    Vector3 direction_;
};


#endif //RAYTRACER_RAY_HH
