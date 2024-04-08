#include <assert.h>
#include "Matrix.h"
#include <exception>
#include <iostream>

using namespace std;

void testAll() { 
	Matrix m(4, 4);
	assert(m.nrLines() == 4);
	assert(m.nrColumns() == 4);	
	m.modify(1, 1, 5);
	assert(m.element(1, 1) == 5);
	TElem old = m.modify(1, 1, 6);
	assert(m.element(1, 2) == NULL_TELEM);
	assert(old == 5);

	//tests for new method
	Matrix m1(4, 4);
	m1.modify(0, 1, 2);
	m1.modify(0, 3, 3);
	m1.modify(1, 0, 8);
	m1.modify(1, 2, 10);
	m1.modify(2, 0, 12);
	m1.modify(2, 3, 16);
	m1.modify(3, 2, 19);
	m1.modify(0, 0, 1);
	m1.modify(2, 3, 100);

	try {
		m1.resize(-10, 10);
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}

	try {
		m1.resize(2, -6);
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}

	m1.resize(2, 6);

	try {
		m1.element(3, 2);
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}

	/*
	cout << m1.element(0, 0) << ' ';
	cout << m1.element(0, 1) << ' ';
	cout << m1.element(0, 2) << ' ';
	cout << m1.element(0, 3) << ' ';
	cout << m1.element(0, 4) << ' ';
	cout << m1.element(0, 5) << '\n';
	cout << m1.element(1, 0) << ' ';
	cout << m1.element(1, 1) << ' ';
	cout << m1.element(1, 2) << ' ';
	cout << m1.element(1, 3) << ' ';
	cout << m1.element(1, 4) << ' ';
	cout << m1.element(1, 5) << 'n';
	*/

	assert(m1.element(0, 0) == 1);
	assert(m1.element(0, 1) == 2);
	assert(m1.element(0, 2) == NULL_TELEM);
	assert(m1.element(0, 3) == 3);
	assert(m1.element(0, 4) == NULL_TELEM);
	assert(m1.element(0, 5) == NULL_TELEM);
	assert(m1.element(1, 0) == 8);
	assert(m1.element(1, 1) == NULL_TELEM);
	assert(m1.element(1, 2) == 10);
	assert(m1.element(1, 3) == NULL_TELEM);
	assert(m1.element(1, 4) == NULL_TELEM);
	assert(m1.element(1, 5) == NULL_TELEM);
}
