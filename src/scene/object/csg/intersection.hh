//
// Created by mehdi on 11/03/2020.
//

#ifndef RAYMARCHER_INTERSECTION_HH
#define RAYMARCHER_INTERSECTION_HH


#include <scene/object/object.hh>
#include <vector>

class Intersection : public Object {
public:
    Intersection(std::vector<Object*> objects);
    double distance(Vector3 point) override;
private:
    std::vector<Object*> objects_;
};


#endif //RAYMARCHER_INTERSECTION_HH
