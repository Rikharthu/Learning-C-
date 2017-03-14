#pragma once

#include "Figure.h"

class Rectangle : public Figure {
private:
	double w;
	double h;
public:
	Rectangle();
	Rectangle(double w, double h);
	Rectangle(double x, double y, double w, double h);
	~Rectangle();
	void setDim(double x, double y, double w, double h);
	void getSize( double *w, double *h);
	void resize(double w, double h);
	double area();
};
