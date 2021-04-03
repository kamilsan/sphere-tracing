#include "Renderer.hpp"

#include "Ray.hpp"
#include "SDF.hpp"

Image Renderer::render(std::unique_ptr<SDF> object) const
{
  Image result{width_, height_};

  const float halfWidth = width_ * 0.5f;
  const float halfHeight = height_ * 0.5f;
  const float aspectRatio = static_cast<float>(width_) / height_;

  for(unsigned int y = 0; y < height_; ++y)
  {
    for(unsigned int x = 0; x < width_; ++x)
    {
      const float rx = aspectRatio * (x - halfWidth) / halfWidth;
      const float ry = (halfHeight - y) / halfHeight;

      const Vector direction{rx, ry, 1};

      const Ray ray{{0, 0, -1}, direction.normalized()};

      const Color col = trace(ray, *object);

      result.setPixel(x, y, col);
    }
  }

  return result;
}

Color Renderer::trace(const Ray& ray, const SDF& object) const
{
  const float maxDistance = 10.0f;
  const float threshold = 0.0001f;
  
  float t = 0;
  Vector position = ray.getOrigin();

  while(t < maxDistance)
  {
    const float sdf = object.evaluate(position);

    if(std::fabs(sdf) < threshold)
    {
      return Color{1, 1, 1};
    }

    t += sdf;
    position = ray(t);
  }

  return Color{};
}