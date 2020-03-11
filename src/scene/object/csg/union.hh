//
// Created by mehdi on 11/03/2020.
//

#ifndef RAYMARCHER_UNION_HH
#define RAYMARCHER_UNION_HH


#include <scene/object/object.hh>
#include <vector>

class Union : public Object{
public:
    Union(std::vector<Object*> objects);
    double distance(Vector3 point) override;
private:
    std::vector<Object*> objects_;
};


#endif //RAYMARCHER_UNION_HH
