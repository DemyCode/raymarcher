//
// Created by mehdi on 11/02/2020.
//

#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H

#include <string>

#define MAX_RGB_INTENSITY 255

class ColorRGB
{
public:
    ColorRGB(int r, int g, int b);
    explicit ColorRGB(const std::string& string);
    ColorRGB() = default;
    int getR();
    int getG();
    int getB();
    void setR(int r);
    void setG(int g);
    void setB(int b);
    ColorRGB operator+(const ColorRGB& colorRgb) const;
    ColorRGB operator-(const ColorRGB& colorRgb) const;
    ColorRGB operator*(double val);
private:
    int r_;
    int g_;
    int b_;
};

#endif //RAYTRACER_COLOR_H
