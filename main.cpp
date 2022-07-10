#include <iostream>
#include <fstream>
#include "Figure.h"
#include "list.h"
#include "isosceles_triangle.h"
#include "isosceles_triangle_prism.h"

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() { 
	int class_code; // 1) triangle; 2) prism
	list<figure*> figures;

	double a, b, angl_c, h;
	while (!fin.eof()) {
		fin >> class_code;
		fin >> a >> b >> angl_c;

		if (class_code == 1) {
			try {
				isosceles_triangle* triangle_ptr = new isosceles_triangle(a, b, angl_c);
				figures.push_back(triangle_ptr);
			}
			catch (string exception) {
				cout << exception;
			}
		}
		else if (class_code == 2) {
			fin >> h;
			try {
				isosceles_triangle_prism* prism_ptr = new isosceles_triangle_prism(a, b, angl_c, h);
				figures.push_back(prism_ptr);
			}
			catch (string exception) {
				cout << exception;
			}
		}
		else cout << "The class code was entered incorrectly\n";
	}

	/*isosceles_triangle triangle(2, 2, 60);
	triangle.print();

	isosceles_triangle_prism prism(triangle.get_side_a(), triangle.get_side_b(), triangle.get_angle_c(), 4);
	prism.print();*/

	return 0;
}