#include <iostream>

using namespace std;

class Point {

	int x, y;

public:

	Point(int x, int y) :x(x), y(y) {}

	Point operator++(int) {

		Point temp(x, y);

		x++; y++;

		return temp;

	}

	void Print() {

		cout << "x=" << x << "y=" << y << '\n';
	}

};
int main() {

	Point p1(2, 3), p2(2, 3);

	p1 = p2++;

	p1.Print();

	p2.Print();

	system("pause");

	return 0;

}