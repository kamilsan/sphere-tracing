#include "Renderer.hpp"
#include "SDF.hpp"

int main()
{
  auto sphere = std::make_unique<Sphere>(Vector{0, 1, 2}, 1);

  Renderer renderer{1920, 1080};
  const Image render = renderer.render(std::move(sphere));
  render.save("render.ppm");

  return 0;
}