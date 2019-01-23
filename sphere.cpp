#include "sphere.h"
#include "ray.h"

// Determine if the ray intersects with the sphere
Hit Sphere::Intersection(const Ray& ray, int part) const
{
    //TODO;

    double x = dot(ray.direction, ray.direction);
    double y = 2 * dot(ray.direction, ray.endpoint - center);
    double z = dot(ray.endpoint - center, ray.endpoint - center) - radius * radius;
    double discrim = y * y - 4 * x * z;
    double t = 0, t0 = 0, t1 = 0;

    if(discrim == 0){
	t = (-1 * y) /(2 * x);
    }else{
	t0 = ((-1 * y) + sqrt(discrim)) /(2 * x);
	t1 = ((-1 * y) - sqrt(discrim)) / (2 * x);
	t = (t0 >= t1) ? t0 : t1;
    }
    
    if(t >= small_t){
	return {this, t, part};
    }
    return {0,0,0};
}

vec3 Sphere::Normal(const vec3& point, int part) const
{
    vec3 normal;
    TODO; // compute the normal direction
    
    return normal;
}

Box Sphere::Bounding_Box(int part) const
{
    Box box;
    TODO; // calculate bounding box
    return box;
}
