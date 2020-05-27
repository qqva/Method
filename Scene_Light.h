#pragma once
#ifndef Scene_h
#define Scene_h
#include "Obj.h"
#include "Color.h"
#include <iostream>
#include <list>
#include "float.h"
using namespace std;

class Light {
public:
	VC position;
	Color_cvet color;
	double intensity = 100;
	Light(VC position_, Color_cvet color_ = Color_cvet(255, 255, 255), double intensity_ = 100.0) : position(position_), color(color_), intensity(intensity_) {}
};

class Scene {

	list<Sphere*> objects;
	list<Light> lightS;

public:
	Scene() {}

	void add(Sphere* object) {
		objects.push_back(object);
	}

	void add(Light light) {
		lightS.push_back(light);
	}

	Color_cvet Shading(const Ray& ray, const Sphere& sphere,double t, int depth) {
		VC intersect_point = ray.origin + ray.direction * t;
		VC normal = sphere.get_normal(intersect_point);
		return (sphere.color).scale_by(normal.dot(ray.direction) * 0.5);
		
	}

	Color_cvet trace(int x, int y) {
		VC ray_origin = VC(0, 0, -1000);
		VC ray_direction = VC(x, y, 1250).normalize();
	
		return trace_ray(Ray(ray_origin, ray_direction), 0, 50);
	}
	Color_cvet trace_ray(const Ray& ray, const Sphere* exclude_obj,int depth) {
		double min_t = FLT_MAX;
		//int min_i = -1;
		const Sphere* nearest_obj = nullptr;

		double t = FLT_MAX;
		for (const Sphere* object : objects) {
			if ((*object).intersect(ray, t)) {
				if (min_t > t) {
					nearest_obj = object;

					min_t = t;
				}
			}
		}
		if (nearest_obj != nullptr) {
			return Shading(ray, *nearest_obj, min_t, depth);
		}
		return Color_cvet(0, 0, 0);
	}

	bool check_occlusion(VC target, VC source) {
		VC toSource = source - target;
		double t_light = toSource.norm();
		Ray ray = Ray(target, toSource * (1.0 / t_light));
		double min_t = t_light;
		const Sphere* nearest_obj = nullptr;
		double t = FLT_MAX;
		for (const Sphere* object : objects) {
			if ((*object).intersect(ray, t)) {
				if (min_t > t) {
					nearest_obj = object;
					min_t = t;
				}
			}
		}
		return nearest_obj == nullptr; // false if lightsource is occluded
	}
	
};


#endif
