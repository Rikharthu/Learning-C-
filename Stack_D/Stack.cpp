#include <iostream>
using namespace std;
#include "stack.h"

Stack::Stack()
{
	cout << "Stack()" << endl;
	max_len = 256;
	s = new int[max_len];
	top = EMPTY;
}

Stack::Stack(int size)
{
	cout << "Stack(int size)" << endl;
	max_len = size;
	s = new int[size];
	top = EMPTY;
}

Stack::Stack(const Stack& s)
{
	cout << "Stack(const Stack& s), copy constructor" << endl;
	top = s.top;
	max_len = s.max_len;
	this->s = new int[max_len];
	for (int i = 0; i <= top; ++i) {
		this->s[i] = s.s[i];
	}
}

Stack::~Stack()
{
	cout << "~Stack()" << endl;
	delete s;
}

bool Stack::push(int item)
{
	if (!isFull()) {
		top++;
		s[top] = item;
		cout << "pushing " << item << endl;
		return true;
	}
	else return false;
}

bool Stack::push(int *cp, int n)
{
	// insert array through pointer
	if ((top + n) > max_len) return false;	
	cout << "pushing array" << endl;
	for (int i = 0; i < n; i++) {
		push(*(cp + i));
	}
	return true;
}

void Stack::clean()
{
	for (int i = 0; i<max_len; i++)
		s[i] = 0;
	top = EMPTY;
}

void Stack::print(int n)
{
	cout << endl;
	for (int i = 0; i < n && i < max_len; i++)
		cout << s[i] << ';';
	cout << "  top index=" << top<<endl;
}

Stack& Stack:: operator = (const Stack& other) {
	cout << " operator = " << endl;
	top = other.top;
	max_len = other.max_len;
	if (s) delete[] s;
	s = new int[max_len];
	for (int i = 0; i <= top; ++i) {
		s[i] = other.s[i];
	}
	return *this;
}

