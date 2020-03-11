//
// Created by mehdi on 11/02/2020.
//

#ifndef RAYTRACER_CAMERA_HH
#define RAYTRACER_CAMERA_HH

#include <utils/vector3.hh>

class Camera {
public:
    Camera() = default;
    Camera(Vector3 location, Vector3 target, Vector3 upvector, double anglex, double angley, double zmin);
    Vector3 getLocation(){ return this->location_; };
    Vector3 getTarget(){ return this->target_; };
    Vector3 getUpvector(){ return this->upvector_; }
    size_t getAnglex(){return this->anglex_;}
    size_t getAngley(){return this->angley_;}
    double getZmin(){return this->zmin_;}
private:
    Vector3 location_;
    Vector3 target_;
    Vector3 upvector_;
    double anglex_;
    double angley_;
    double zmin_;
};


#endif //RAYTRACER_CAMERA_HH
