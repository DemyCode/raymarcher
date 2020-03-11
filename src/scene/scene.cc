//
// Created by mehdi on 11/02/2020.
//

#include "scene.hh"

Scene::Scene(Object* object, std::vector<PointLight*> lights, Camera camera) {
    this->object_ = object;
    this->lights_ = lights;
    this->camera_ = camera;
}

ColorRGB Scene::castRay(Ray ray, int bounces) {
    if (bounces == 0)
        return ColorRGB(0, 0, 0);
    Vector3 currentpoint = ray.getPoint();
    double distance = std::numeric_limits<double>::infinity();
    for (int i = 0; i < 64 && distance > 0.1; i++)
    {
        distance = this->object_->distance(currentpoint);
        currentpoint = currentpoint + ray.getDirection() * distance;
    }
    return distance > 0.1 ? ColorRGB(0, 0, 0) : ColorRGB(255, 0, 0);
}