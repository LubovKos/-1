#ifndef ISOSCELES_TRIANGLE_PRISM
#define ISOSCELES_TRIANGLE_PRISM
#include "isosceles_triangle.h"

//��������� ����� ������ �� ������������
class isosceles_triangle_prism : public isosceles_triangle {
public:
	//����������� �� ���������
	isosceles_triangle_prism();

	//����������� � ���������� ��� ������, ��������� �����-��� � ��������� � ������ ������
	isosceles_triangle_prism(double s_a, double s_b, double ang_c, double h);

	//������� ����������� ������
	double square();

	//����� ������
	double volume();

	//������ ������ (���� �� ����������)
	void print() override;

	//����������
	~isosceles_triangle_prism();
private:
	double height; //������ ������
};

#endif ISOSCELES_TRIANGLE_PRISM
