#ifndef RENDERER_H
#define RENDERER_H

#include "Image.hpp"

class Renderer
{
public:
  Renderer(unsigned int width, unsigned int height): width_(width), height_(height) {}

  Image render() const;

private:
  unsigned int width_;
  unsigned int height_;
};

#endif