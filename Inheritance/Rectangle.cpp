#include "Rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle()
{
	w = h = 0.0;
	cout << "Rectangle constructor\n";      //for demo only! 
}

Rectangle::~Rectangle()
{
	cout << "Rectangle destructor\n";       //for demo only! 
}

Rectangle::Rectangle(double w, double h) : Figure(0.0, 0.0)
{
	cout << "Rectangle constructor(w,h)\n";
	this->w = w;
	this->h = h;
}
Rectangle::Rectangle(double x, double y, double w, double h) : Figure(x, y)
{
	cout << "Rectangle constructor(x,y,w,h)\n";
	this->w = w;
	this->h = h;
}
void Rectangle::setDim(double x, double y, double w, double h)
{
	this->x = x;
	this->y = y;
	resize(w, h);
}

void Rectangle::getSize(double *w, double *h)
{
	*w = this->w;
	*h = this->h;
}

void Rectangle::resize(double w, double h)
{
	this->w = w;
	this->h = h;
}


double Rectangle::area()
{
	return ( w * h );
}
