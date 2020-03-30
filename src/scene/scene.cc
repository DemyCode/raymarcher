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

std::optional<Vector3> Scene::trace(Ray ray, double maxdistance)
{
    double epsilondisplacement = 0.1;
    double epsilonbreakcondition = 0.01;
    ray.setPoint(ray.getPoint() + ray.getDirection() * epsilondisplacement);
    Vector3 currentpoint = ray.getPoint();
    for (size_t i = 0; i < 200; i++)
    {
        double distancetonearest = this->object_->distance(currentpoint);
        currentpoint = currentpoint + (ray.getDirection() * distancetonearest);
        if (distancetonearest < epsilonbreakcondition)
            return currentpoint;
        if (maxdistance != -1 && (ray.getPoint().dist(currentpoint) > maxdistance))
            return std::nullopt;
    }
    return std::nullopt;
}

ColorRGB Scene::castRay(Ray ray, int bounces) {
    ColorRGB newColor = ColorRGB(0, 0, 0);
    if (bounces == 0)
        return newColor;

    std::optional<Vector3> tuple = this->trace(ray, -1);

    if (tuple)
    {
        Vector3 pointresult = tuple.value();
        for (auto & light : this->lights_)
        {
            Vector3 lightdir = (light->getPos() - pointresult).normalize();
            std::optional<Vector3> shadow = this->trace(Ray(pointresult, lightdir), pointresult.dist(light->getPos()));
            if (!shadow)
            {
                Vector3 normaldir = this->normal(pointresult, 0.01).normalize();
                double dotproduct = normaldir.dot(lightdir);
                newColor = newColor +
                           (ColorRGB("white") * // objres->getTextureColor(pointresult)
                            1.0 * // objres->getTextureKd(pointresult)
                            dotproduct *
                            light->getIntensity());

                Vector3 reflectdir = ray.getDirection() - normaldir * ray.getDirection().dot(normaldir) * 2;
                double dotproduct2 = std::pow(reflectdir.dot(lightdir), 1.0); // objres->getTextureNs(pointresult)
                newColor = newColor +
                           light->getColorRgb() * 1.0 * // objres->getTextureKs(pointresult)
                           light->getIntensity() *
                           dotproduct2;

                newColor = newColor +
                           castRay(Ray(pointresult, reflectdir), bounces - 1) * 1.0; // objres->getTextureKs(pointresult)
            }
        }
    }
    return newColor;
}