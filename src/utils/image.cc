//
// Created by mehdi on 11/02/2020.
//

#include "image.hh"
#include "color.hh"


Image::Image(size_t width, size_t height) {
    this->width_ = width;
    this->height_ = height;
    this->pixels_ = std::vector<std::vector<ColorRGB>>();
    for (size_t i = 0; i < height; i++)
    {
        pixels_.emplace_back(std::vector<ColorRGB>());
        for (size_t j = 0; j < width; j++)
        {
            pixels_[i].push_back(ColorRGB(0, 0, 0));
        }
    }
}

void Image::ppm_creator(std::string filename) {
    std::ofstream myFile(filename);
    myFile << "P3";
    myFile << " ";
    myFile << this->width_;
    myFile << " ";
    myFile << this->height_;
    myFile << " ";
    myFile << MAX_RGB_INTENSITY << "\n";
    for (size_t i = 0; i < this->height_; i++)
    {
        for (size_t j = 0; j < this->width_; j++)
        {
            myFile << this->pixels_[i][j].getR() << " " <<
            this->pixels_[i][j].getG() << " " <<
            this->pixels_[i][j].getB() << " " <<
            std::endl;
        }
    }
}

ColorRGB Image::getPixel(int x, int y)
{
    return this->pixels_[y][x];
}

void Image::setPixel(int x, int y, ColorRGB pixel) {
    this->pixels_[y][x] = pixel;
}
