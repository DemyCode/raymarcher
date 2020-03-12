//
// Created by mehdi on 11/02/2020.
//

#include "scene.hh"

Scene::Scene(Object* object, std::vector<PointLight*> lights, Camera camera) {
    this->object_ = object;
    this->lights_ = lights;
    this->camera_ = camera;
}

Vector3 Scene::normal(Vector3 p, double epsilon)
{
    return Vector3(
            this->object_->distance(Vector3(p.x_ + epsilon, p.y_, p.z_)) - this->object_->distance(Vector3(p.x_ - epsilon, p.y_, p.z_)),
            this->object_->distance(Vector3(p.x_, p.y_ + epsilon, p.z_)) - this->object_->distance(Vector3(p.x_, p.y_ - epsilon, p.z_)),
            this->object_->distance(Vector3(p.x_, p.y_, p.z_ + epsilon)) - this->object_->distance(Vector3(p.x_, p.y_, p.z_ - epsilon)));
}

ColorRGB Scene::castRay(Ray ray, int bounces) {
    if (bounces == 0)
        return ColorRGB(0, 0, 0);
    Vector3 currentpoint = ray.getPoint();
    double distance = std::numeric_limits<double>::infinity();
    for (int i = 0; i < 64 && distance > 0.001; i++)
    {
        distance = this->object_->distance(currentpoint);
        currentpoint = currentpoint + ray.getDirection() * distance;
    }
    ColorRGB newColor = ColorRGB(0, 0, 0);
    if (distance <= 0.001) {
        for (auto &light : this->lights_) {
            Vector3 lightdir = (light->getPos() - currentpoint).normalize();
            Vector3 normaldir = this->normal(currentpoint, 0.001).normalize();
            double dotproduct = normaldir.dot(lightdir);
            newColor = newColor +
                       (ColorRGB(255, 255, 255) *
                        1 *
                        dotproduct *
                        light->getIntensity());
            Vector3 reflectdir = ray.getDirection() - normaldir * ray.getDirection().dot(normaldir) * 2;
            double dotproduct2 = std::pow(reflectdir.dot(lightdir), 1.0);
            newColor = newColor +
                       light->getColorRgb() * 0.5 *
                       light->getIntensity() *
                       dotproduct2;
        }
    }
    return newColor;
}