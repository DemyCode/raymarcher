//
// Created by mehdi on 11/02/2020.
//

#ifndef RAYTRACER_UNIFORMTEXTURE_HH
#define RAYTRACER_UNIFORMTEXTURE_HH

#include <scene/texture/texturematerial.hh>
#include <utils/vector3.hh>

class UniformTexture : public TextureMaterial {
public:
    UniformTexture(double ks, double kd, ColorRGB rgb, double ns);
    double getTextureKs(Vector3 point) override;
    double getTextureKd(Vector3 point) override;
    ColorRGB getTextureColor(Vector3 point) override;
    double getTextureNs(Vector3 point) override;

private:
    double ks_;
    double kd_;
    ColorRGB rgb_;
    double ns_;
};


#endif //RAYTRACER_UNIFORMTEXTURE_HH

