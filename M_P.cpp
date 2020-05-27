#pragma once
#include "Scene_Light.h"
#include "Obj.h"
#include "Vector.h"
#include "Color.h"
#include <iostream>
#include <fstream>


using namespace std;

int main() {
	int Height = 500;
	int Width = 500;

	Color_cvet pix_col(0, 0, 0);

	Scene scene = Scene();

	Sphere sphere1(VC(300, 250, 200), 100, Color_cvet(147, 24, 204));
	Sphere sphere2(VC(200,250,200), 100, Color_cvet(237, 230, 26));
	Sphere sphere3(VC(300, 150, 100), 50, Color_cvet(88, 88, 88));
	Sphere sphere4(VC(200,250,200), 50, Color_cvet(12, 240, 50));
	Sphere sphere5(VC(50, 50, 50), 40, Color_cvet(246, 7, 250));
	Sphere sphere6(VC(75, 75, 75), 30, Color_cvet(250, 36, 7));
	Sphere sphere7(VC(100, 100, 100), 20, Color_cvet(12, 7, 250));
	Sphere sphere8(VC(115, 115, 115), 10, Color_cvet(246, 250, 7));
	
	Light light1 = Light(VC(200, 250, 200), Color_cvet(255, 255, 255));

	scene.add(&sphere1);
	scene.add(&sphere2);
	scene.add(&sphere3);
	scene.add(&sphere4);
	scene.add(&sphere5);
	scene.add(&sphere6);
	scene.add(&sphere7);
	scene.add(&sphere8);
	scene.add(light1);

	ofstream my_Image("image.ppm");

	if (my_Image.is_open()) {
		my_Image << "P3\n" << Width << " " << Height << " 255\n";
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < Width; j++) {
				pix_col = scene.trace(i, j);
				my_Image << (int)pix_col.r << ' ' << (int)pix_col.g << ' ' << (int)pix_col.b << "\n";
			}
		}
		my_Image.close();
	}
	else
		cout << "Could not open the file";
	return 0;
}
