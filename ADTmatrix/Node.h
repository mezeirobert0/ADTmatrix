#pragma once
typedef int TElem;

class Node
{
private:
	Node* prev;
	Node* next;
	int line;
	int col;
	TElem value;

	Node();

	friend class Matrix;
};
