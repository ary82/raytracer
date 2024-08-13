#include "camera.hh"
#include "hittable_list.hh"
#include "sphere.hh"

int main() {

  hittable_list world;

  world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
  world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

  camera cam;

  cam.aspect_ratio = 16.0 / 9.0;
  cam.image_width = 640;
  cam.samples_per_pixel = 100;

  cam.render(world);
}
