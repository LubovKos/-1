#include "isosceles_triangle_prism.h"
#define underline "\033[4m"
#define no_underline "\033[0m"

using namespace std;

//конструктор по умолчанию
isosceles_triangle_prism::isosceles_triangle_prism() {
	height = 0;
	side_a = 0;
	side_b = 0;
	base = 0;
	angle_a = 0;
	angle_b = 0;
	angle_c = 0;
};

//конструктор с параметром для призмы, передаётся треуг-ник в основании и высота призмы
isosceles_triangle_prism::isosceles_triangle_prism(double s_a, double s_b, double ang_c, double h) {
	isosceles_triangle triangle(s_a, s_b, ang_c);
	height = h;
	side_a = s_a;
	side_b = s_b;
	base = triangle.get_base();
	angle_a = triangle.get_angle_a();
	angle_b = triangle.get_angle_b();
	angle_c = triangle.get_angle_c();
}

//площадь поверхности призмы
double isosceles_triangle_prism::square() {
	double side_surface_area = isosceles_triangle::perimeter() * height;
	return side_surface_area + (2 * isosceles_triangle::square());
}

//объём призмы
double isosceles_triangle_prism::volume() { return isosceles_triangle::square() * height; }

//печать призмы (всех ее параметров)
void isosceles_triangle_prism::print() {
	cout << endl;
	isosceles_triangle::print();
	cout << underline << "Parameters of the prism:" << no_underline << endl;
	cout << "Height of the prism: " << fixed << setprecision(2) << height << endl;
	cout << "Surface area of the prism: " << square() << endl;
	cout << "Volune of the prism: " << volume() << endl;
}

//деструктор
isosceles_triangle_prism::~isosceles_triangle_prism() {
	height = 0;
	side_a = 0;
	side_b = 0;
	base = 0;
	angle_a = 0;
	angle_b = 0;
	angle_c = 0;
}