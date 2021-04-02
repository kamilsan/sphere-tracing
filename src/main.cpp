#include "Renderer.hpp"

int main()
{
  Renderer renderer{1920, 1080};
  const Image render = renderer.render();

  render.save("render.ppm");

  return 0;
}