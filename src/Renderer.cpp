#include "Renderer.hpp"

Image Renderer::render() const
{
  Image result{width_, height_};

  const Color top{0.34, 0.87, 0.98};
  const Color bottom{0.05, 0.44, 0.71};

  for(unsigned int y = 0; y < height_; ++y)
  {
    for(unsigned int x = 0; x < width_; ++x)
    {
      const float factor = 1.0f - y / (height_ - 1.0);
      const Color col = factor * top + (1.0f - factor) * bottom;

      result.setPixel(x, y, col);
    }
  }

  return result;
}