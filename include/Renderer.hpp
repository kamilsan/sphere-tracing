#ifndef RENDERER_H
#define RENDERER_H
#include <memory>

#include "Image.hpp"
#include "Vector.hpp"

class Ray;
class SDF;

class Renderer
{
public:
  Renderer(unsigned int width, unsigned int height): width_(width), height_(height) {}

  Image render(std::unique_ptr<SDF> object) const;

private:
  Color trace(const Ray& ray, const SDF& object) const;

  unsigned int width_;
  unsigned int height_;
};

#endif