#include <iostream>

#include "Vector.hpp"

Vector Vector::normalized() const
{
  const float len = length();
  if(len > 0.00001f)
  {
    const float f = 1.0f/len;
    return Vector{x * f, y * f, z * f};
  }
  return *this;
}