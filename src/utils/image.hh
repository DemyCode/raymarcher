//
// Created by mehdi on 11/02/2020.
//

#ifndef RAYTRACER_IMAGE_HH
#define RAYTRACER_IMAGE_HH

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include <utils/color.hh>

class Image {
public:
    Image(size_t width, size_t height);
    ColorRGB getPixel(int x, int y);
    void setPixel(int x, int y, ColorRGB pixel);
    void ppm_creator(std::string filename);
private:
    size_t width_;
    size_t height_;
    std::vector<std::vector<ColorRGB>> pixels_;
};


#endif //RAYTRACER_IMAGE_HH
