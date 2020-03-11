//
// Created by mehdi on 11/02/2020.
//

#ifndef RAYTRACER_VECTOR3_H
#define RAYTRACER_VECTOR3_H

#include <iostream>
#include <cmath>

class Vector3
{
public:
    Vector3(double x, double y, double z);
    Vector3() = default;
    Vector3 operator+(const Vector3& v) const;
    Vector3 operator-(const Vector3& v) const;
    Vector3 operator*(const Vector3& v) const;
    Vector3 operator/(const Vector3& v) const;
    double dist(const Vector3& v) const;
    Vector3 operator*(double val) const;
    Vector3 operator/(double val) const;
    double dot(const Vector3& v) const;
    Vector3 cross(const Vector3& v) const;
    double norm() const;
    Vector3 normalize() const;
    bool equal(const Vector3 &v, int precision) const;
    friend std::ostream& operator<<(std::ostream &out, const Vector3 &vect);

    double getX();
    double getY();
    double getZ();

protected:
    double x_;
    double y_;
    double z_;
};

#endif //RAYTRACER_VECTOR3_H
