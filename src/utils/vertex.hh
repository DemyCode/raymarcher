//
// Created by mehdi on 28/02/2020.
//

#ifndef RAYTRACER_VERTEX_HH
#define RAYTRACER_VERTEX_HH


#include <optional>
#include <utils/vector3.hh>

class Vertex : public Vector3
{
public:
    Vertex() = default;
    Vertex(Vector3 v, std::optional<Vector3> normal);
    Vertex(double x, double y, double z, std::optional<Vector3> normal);
    std::optional<Vector3> getNormal();
private:
    std::optional<Vector3> normal_;
};


#endif //RAYTRACER_VERTEX_HH
