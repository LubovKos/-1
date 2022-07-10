#ifndef ISOSCELES_TRIANGLE_PRISM
#define ISOSCELES_TRIANGLE_PRISM
#include "isosceles_triangle.h"

//наследуем класс призмы от треугольника
class isosceles_triangle_prism : public isosceles_triangle {
public:
	//конструктор по умолчанию
	isosceles_triangle_prism();

	//конструктор с параметром для призмы, передаётся треуг-ник в основании и высота призмы
	isosceles_triangle_prism(double s_a, double s_b, double ang_c, double h);

	//площадь поверхности призмы
	double square();

	//объём призмы
	double volume();

	//печать призмы (всех ее параметров)
	void print() override;

	//деструктор
	~isosceles_triangle_prism();
private:
	double height; //высота призмы
};

#endif ISOSCELES_TRIANGLE_PRISM
