//
// Created by mehdi on 11/02/2020.
//

#include "color.hh"

ColorRGB::ColorRGB(int r, int g, int b)
{
    this->r_ = r;
    this->g_ = g;
    this->b_ = b;
}

int ColorRGB::getR() {
    return r_;
}

int ColorRGB::getG() {
    return g_;
}

int ColorRGB::getB() {
    return b_;
}

void ColorRGB::setR(int r) {
    this->r_ = r;
}

void ColorRGB::setG(int g) {
    this->g_ = g;
}

void ColorRGB::setB(int b) {
    this->b_ = b;
}

ColorRGB ColorRGB::operator*(double val) {
    int newr = (int)(this->r_ * val);
    int newg = (int)(this->g_ * val);
    int newb = (int)(this->b_ * val);
    int r =  newr >= 255 ? 255 : (newr <= 0 ? 0 : newr);
    int g =  newg >= 255 ? 255 : (newg <= 0 ? 0 : newg);
    int b =  newb >= 255 ? 255 : (newb <= 0 ? 0 : newb);
    return ColorRGB(r, g, b);
}

ColorRGB ColorRGB::operator+(const ColorRGB& colorRgb) const {
    return ColorRGB(
            this->r_ + colorRgb.r_ <= 255 ? this->r_ + colorRgb.r_ : 255,
            this->g_ + colorRgb.g_ <= 255 ? this->g_ + colorRgb.g_ : 255,
            this->b_ + colorRgb.b_ <= 255 ? this->b_ + colorRgb.b_ : 255);
}

ColorRGB ColorRGB::operator-(const ColorRGB& colorRgb) const {
    return ColorRGB(
            this->r_ + colorRgb.r_ >= 0 ? this->r_ + colorRgb.r_ : 0,
            this->g_ + colorRgb.g_ >= 0 ? this->g_ + colorRgb.g_ : 0,
            this->b_ + colorRgb.b_ >= 0 ? this->b_ + colorRgb.b_ : 0);
}

ColorRGB::ColorRGB(const std::string& string) {
    if (string == "white")
    {
        this->r_ = 255;
        this->g_ = 255;
        this->b_ = 255;
    }
    else if (string == "red")
    {
        this->r_ = 255;
        this->g_ = 0;
        this->b_ = 0;
    }
    else if (string == "yellow")
    {
        this->r_ = 255;
        this->g_ = 255;
        this->b_ = 0;
    }
    else if (string == "blue")
    {
        this->r_ = 0;
        this->g_ = 0;
        this->b_ = 255;
    }
    else if (string == "green")
    {
        this->r_ = 0;
        this->g_ = 255;
        this->b_ = 0;
    }
    else if (string == "black")
    {
        this->r_ = 0;
        this->g_ = 0;
        this->b_ = 0;
    }
}
