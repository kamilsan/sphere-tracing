#include "SDF.hpp"

float Sphere::evaluate(const Vector& point) const
{
  return (point - center_).length() - radius_;
}