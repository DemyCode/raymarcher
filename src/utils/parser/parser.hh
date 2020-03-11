//
// Created by mehdi on 28/02/2020.
//

#ifndef RAYTRACER_PARSER_HH
#define RAYTRACER_PARSER_HH

#include <fstream>
#include <iostream>
#include <regex>
#include <scene/object/triangle.hh>

class Parser {
public:
    Parser(std::string file);
    std::vector<Triangle *> getTriangles();
private:
    std::vector<Vector3> vertices_;
    std::vector<Vector3> vetricestexture_;
    std::vector<Vector3> normals_;
    std::vector<Triangle*> faces_;
};


#endif //RAYTRACER_PARSER_HH
