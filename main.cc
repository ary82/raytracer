#include "camera.hh"
#include "hittable_list.hh"
#include "sphere.hh"

int main() {

  hittable_list world;

  auto mat_ground = make_shared<lambertian>(color(0.6, 0.7, 0.3));
  auto mat_center = make_shared<lambertian>(color(0.1, 0.2, 0.5));
  auto mat_left = make_shared<dielectric>(1.33);
  auto mat_right = make_shared<metal>(color(0.83, 0.68, 0.22), 1);

  world.add(make_shared<sphere>(point3(0.0, -100.5, -1.0), 100.0, mat_ground));
  world.add(make_shared<sphere>(point3(0.0, 0.0, -1.2), 0.5, mat_center));
  world.add(make_shared<sphere>(point3(-1.0, 0.0, -1.0), 0.5, mat_left));
  world.add(make_shared<sphere>(point3(1.0, 0.0, -1.0), 0.5, mat_right));

  camera cam;

  cam.aspect_ratio = 16.0 / 9.0;
  cam.image_width = 1920;
  cam.samples_per_pixel = 100;
  cam.max_depth = 50;

  cam.vfov = 45;
  cam.lookfrom = point3(-3, 0, 1);
  cam.lookat = point3(2, 0, -2.5);
  cam.vup = point3(-0.1, 1, 0.1);

  cam.defocus_angle = 0.3;
  cam.focus_dist = 3;

  cam.render(world);
}
