//
// Created by mehdi on 11/02/2020.
//

#ifndef RAYTRACER_SCENE_HH
#define RAYTRACER_SCENE_HH

#include <optional>
#include <vector>

#include <scene/object/object.hh>
#include <scene/light/light.hh>
#include <scene/camera.hh>
#include <utils/color.hh>
#include <scene/light/pointlight.hh>
#include <scene/object/triangle.hh>

class Scene {
public:
    Scene(Object* object, std::vector<PointLight*> lights, Camera camera);
    Object* getObject(){ return this->object_; }
    std::vector<PointLight*> getLights(){ return this->lights_; }
    Camera getCamera(){ return this->camera_; }
    ColorRGB castRay(Ray ray, int bounces);
private:
    Object* object_;
    std::vector<PointLight*> lights_;
    Camera camera_;
};


#endif //RAYTRACER_SCENE_HH
