#include <iostream>
#include "Matrix.h"
#include "ExtendedTest.h"
#include "ShortTest.h"

using namespace std;


int main() {
	testAll();
	testAllExtended();
	cout << "Test End" << endl;
	system("pause");

	/*
	Matrix m(4, 4);
	m.modify(0, 1, 2);
	m.modify(0, 3, 3);
	m.modify(1, 0, 8);
	m.modify(1, 2, 10);
	m.modify(2, 0, 12);
	m.modify(2, 3, 16);
	m.modify(3, 2, 19);
	m.modify(0, 0, 1);
	m.modify(2, 3, 100);
	*/
}
