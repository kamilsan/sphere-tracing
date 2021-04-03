#ifndef SDF_HPP
#define SDF_HPP

#include "Vector.hpp"

class SDF
{
public:
  virtual float evaluate(const Vector&) const = 0;
private:
};

class Sphere : public SDF
{
public:
  Sphere(const Vector& center, float radius): center_(center), radius_(radius) {}
  Sphere(float radius): Sphere(Vector{}, radius) {}

  float evaluate(const Vector& point) const override;
private:
  Vector center_;
  float radius_;
};

#endif