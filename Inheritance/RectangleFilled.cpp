#include "RectangleFilled.h"
#include <iostream>
using namespace std;

RectangleFilled::RectangleFilled()
{
	this->color = 0;
	cout << "RectangleFilled constructor\n"; 	//for demo only!
}

RectangleFilled::~RectangleFilled()
{
	cout << "RectangleFilled destructor\n"; 	//for demo only!
}

RectangleFilled::RectangleFilled(double w, double h, int c) : Rectangle(w, h)
{
	this->color = c;
}

RectangleFilled::RectangleFilled(double x,double y,double w,double h, int c) :  Rectangle(x, y, w, h)
{
	this->color = c;
}

