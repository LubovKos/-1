#ifndef ISOSCELES_TRIANGLE 
#define ISOSCELES_TRIANGLE 

#include "figure.h"

//прямоугольный треугольник
class isosceles_triangle : public figure {
public:
	//конструктор по умолчанию
	isosceles_triangle();

	//конструктор с параметрами (2 стороны и угол между ними)
	isosceles_triangle(double a, double b, double ang_c);

	//геттеры
	double get_side_a() { return side_a; }
	double get_side_b() { return side_b; }
	double get_base() { return base; }
	double get_angle_a() { return angle_a; }
	double get_angle_b() { return angle_b; }
	double get_angle_c() { return angle_c; }

	//печать треугольника (всех его параметров)
	void print() override;

	//периметр
	double perimeter();

	//площадь
	double square();

	//деструктор
	~isosceles_triangle();
protected:

	double side_a; //боковая сторона
	double side_b; //боковая сторона
	double base; //основание
	double angle_a; //угол напротив стороны side_a 
	double angle_b; //угол напротив стороны side_b
	double angle_c; //угол напротив основания base
};

#endif // ISOSCELES_TRIANGLE
