#ifndef ISOSCELES_TRIANGLE 
#define ISOSCELES_TRIANGLE 

#include "figure.h"

//������������� �����������
class isosceles_triangle : public figure {
public:
	//����������� �� ���������
	isosceles_triangle();

	//����������� � ����������� (2 ������� � ���� ����� ����)
	isosceles_triangle(double a, double b, double ang_c);

	//�������
	double get_side_a() { return side_a; }
	double get_side_b() { return side_b; }
	double get_base() { return base; }
	double get_angle_a() { return angle_a; }
	double get_angle_b() { return angle_b; }
	double get_angle_c() { return angle_c; }

	//������ ������������ (���� ��� ����������)
	void print() override;

	//��������
	double perimeter();

	//�������
	double square();

	//����������
	~isosceles_triangle();
protected:

	double side_a; //������� �������
	double side_b; //������� �������
	double base; //���������
	double angle_a; //���� �������� ������� side_a 
	double angle_b; //���� �������� ������� side_b
	double angle_c; //���� �������� ��������� base
};

#endif // ISOSCELES_TRIANGLE
