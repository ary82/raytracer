#include "camera.hh"
#include "hittable_list.hh"
#include "sphere.hh"

int main() {

  hittable_list world;

  auto mat_ground = make_shared<lambertian>(color(0.8, 0.8, 0.0));
  auto mat_center = make_shared<lambertian>(color(0.1, 0.2, 0.5));
  auto mat_left = make_shared<metal>(color(0.8, 0.8, 0.8));
  auto mat_right = make_shared<metal>(color(0.8, 0.6, 0.2));

  world.add(make_shared<sphere>(point3(0.0, -100.5, -1.0), 100.0, mat_ground));
  world.add(make_shared<sphere>(point3(0.0, 0.0, -1.2), 0.5, mat_center));
  world.add(make_shared<sphere>(point3(-1.0, 0.0, -1.0), 0.5, mat_left));
  world.add(make_shared<sphere>(point3(1.0, 0.0, -1.0), 0.5, mat_right));

  camera cam;

  cam.aspect_ratio = 16.0 / 9.0;
  cam.image_width = 640;
  cam.samples_per_pixel = 100;
  cam.max_depth = 50;

  cam.render(world);
}
