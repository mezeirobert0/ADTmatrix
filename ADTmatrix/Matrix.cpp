#include "Matrix.h"
#include <exception>
#include <iostream>
using namespace std;

// Complexity: O(1)
Matrix::Matrix(int nrLines, int nrCols) {
	   
	lines = nrLines;
	cols = nrCols;
	head = new Node;
	tail = head;
}

// Complexity: O(1)
int Matrix::nrLines() const {
	return lines;
}

// Complexity: O(1)
int Matrix::nrColumns() const {
	return cols;
}

// Complexity: O(n), where n = number of non-zero elements in the matrix
TElem Matrix::element(int i, int j) const {
	if (i < 0 || j < 0 || i >= lines || j >= cols)
		throw exception("Position is out of range!");

	/*
	// element [i][j] is first in the list
	if (head->line == i && head->col == j)
		return head->value;

	// element [i][j] would be first in the list
	else if (i < head->line)
		return NULL_TELEM;

	else if (i == head->line && j <= head->col)
		return NULL_TELEM;

	// element [i][j] is last in the list
	else if (tail->line == i && tail->col == j)
		return tail->value;

	// element [i][j] would be last in the list
	else if (tail->line < i)
		return NULL_TELEM;

	else if (tail->line == i && tail->col < j)
		return NULL_TELEM;
	*/
	
	Node* it = head;
		
	// variable to check if the iterator went past the position [i][j]
	bool passed = false;

	while (passed == false && it != nullptr)
	{
		if (it->line == i && it->col == j)
			return it->value;

		if (it->line > i)
			passed = true;

		else if (it->line == i && it->col > j)
			passed = true;

		else it = it->next;
	}

	return NULL_TELEM;
}

// Complexity: O(n), where n = number of non-zero elements in the matrix
TElem Matrix::modify(int i, int j, TElem e) {
	if (i < 0 || j < 0 || i >= lines || j >= cols)
		throw exception("Position is out of range!");

	// if matrix is empty
	if (head->value == 0)
	{
		head->line = i;
		head->col = j;
		head->value = e;

		return NULL_TELEM;
	}

	TElem previousElement = element(i, j);

	/*
	// element [i][j] is first in the list
	if (head->line == i && head->col == j)
		head->value = e;

	// element [i][j] would be first in the list
	else if (i < head->line)
	{
		Node* newNode = new Node(nullptr, head, i, j, e);
		head = newNode;
	}

	else if (i == head->line && j <= head->col)
	{
		Node* newNode = new Node(nullptr, head, i, j, e);
		head = newNode;
	}

	// element [i][j] is last in the list
	else if (tail->line == i && tail->col == j)
		tail -> value = e;

	// element [i][j] would be last in the list
	else if (tail->line < i)
	{
		Node* newNode = new Node(tail, nullptr, i, j, e);
		tail = newNode;
	}

	else if (tail->line == i && tail->col < j)
	{
		Node* newNode = new Node(tail, nullptr, i, j, e);
		tail = newNode;
	}
	*/

	Node* it = head;
		
	// variable to check if the iterator went past the position [i][j]
	bool passed = false;

	while (passed == false && it != nullptr)
	{
		if (it->line == i && it->col == j)
		{
			it->value = e;
			return previousElement;
		}

		if (it->line > i)
			passed = true;

		else if (it->line == i && it->col > j)
			passed = true;

		else it = it->next;
	}

	if (it == nullptr)
	{
		//Node* newNode = new Node(tail, nullptr, i, j, e);
		Node* newNode = new Node;

		newNode->prev = tail;
		newNode->next = nullptr;

		newNode->line = i;
		newNode->col = j;
		newNode->value = e;

		tail->next = newNode;
		tail = tail->next;
	}

	// here passed == true

	else if (it == head)
	{
		//Node* newNode = new Node(nullptr, head, i, j, e);
		Node* newNode = new Node;

		newNode->prev = nullptr;
		newNode->next = head;

		newNode->line = i;
		newNode->col = j;
		newNode->value = e;

		head->prev = newNode;
		head = head->prev;
	}

	else
	{
		//Node* newNode = new Node(it->prev, it, i, j, e);
		Node* newNode = new Node;

		newNode->prev = it->prev;
		newNode->next = it;

		newNode->line = i;
		newNode->col = j;
		newNode->value = e;

		(it->prev)->next = newNode;
		it->prev = newNode;
	}

	return previousElement;
}

// Complexity: O(n), where n = number of non-zero elements in the matrix
Matrix::~Matrix() {
	Node* it = head;
	while (it != nullptr) {
		Node* nextNode = it->next;
		delete it;
		it = nextNode;
	}
	head = nullptr;
	tail = nullptr;
}
