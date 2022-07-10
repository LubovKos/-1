#include "isosceles_triangle.h"
#define PI 3.14159265   
#define underline "\033[4m"
#define no_underline "\033[0m"

using namespace std;

//конструктор по умолчанию
isosceles_triangle::isosceles_triangle() {
	side_a = 0;
	side_b = 0;
	base = 0;
	angle_a = 0;
	angle_b = 0;
	angle_c = 0;
}

//конструктор с параметрами (2 стороны и угол между ними)
isosceles_triangle::isosceles_triangle(double a, double b, double ang_c) {
	side_a = a;
	side_b = b;

	//если треугольник не равнобедренный
	if (side_a != side_b)
		throw "error: Triangle does not meet the construction condition!\n";

	angle_c = ang_c;
	base = sqrt(side_a * side_a + side_b * side_b - 2 * side_a * side_b * cos(angle_c * PI / 180)); //теорема косинусов
	//углы при основании
	angle_a = (180 - angle_c) / 2;
	angle_b = angle_a;

	//если сумма углов != 180
	if (angle_a + angle_b + angle_c != 180)
		throw "error: Triangle sum of angles theorem!\n";
}

//печать треугольника (всех его параметров)
void isosceles_triangle::print() {
	cout << underline << "Parameters of triangle" << no_underline << endl;
	cout << "The base of the triangle: " << fixed << setprecision(2) << base << endl;
	cout << "Lateral side a: " << fixed << setprecision(2) << side_a << endl;
	cout << "Lateral side b: " << fixed << setprecision(2) << side_b << endl;
	cout << "Angle a: " << fixed << setprecision(2) << angle_a << endl;
	cout << "Angle b: " << fixed << setprecision(2) << angle_b << endl;
	cout << "Angle c: " << fixed << setprecision(2) << angle_c << endl;
	cout << "The perimeter of the triangle: " << fixed << setprecision(2) << perimeter() << endl;
	cout << "The area of the triangle: " << fixed << setprecision(2) << square() << endl;
}

//периметр
double isosceles_triangle::perimeter() { return base + side_a + side_b; }

//площадь
double isosceles_triangle::square() {
	double p = perimeter() / 2;
	return sqrt(p * (p - side_a) * (p - side_b) * (p - base)); //площадь по Герону
}

//деструктор
isosceles_triangle::~isosceles_triangle() {
	side_a = 0;
	side_b = 0;
	base = 0;
	angle_a = 0;
	angle_b = 0;
	angle_c = 0;
}