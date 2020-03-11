//
// Created by mehdi on 11/03/2020.
//

#ifndef RAYMARCHER_SMOOTHUNION_HH
#define RAYMARCHER_SMOOTHUNION_HH

#include <utils/vector3.hh>
#include <scene/object/object.hh>
#include <vector>
#include <numeric>

class SmoothUnion : public Object{
public:
    SmoothUnion(std::vector<Object*> objects);
    double distance(Vector3 point) override;
private:
    std::vector<Object*> objects_;
    double k_;

    static double smoothmin(double a, double b);
};


#endif //RAYMARCHER_SMOOTHUNION_HH
