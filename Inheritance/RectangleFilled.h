#pragma once

#include "Rectangle.h"

class RectangleFilled : public Rectangle {
private:
	int color;
public:
	RectangleFilled();
	RectangleFilled(double w, double h, int color);
	RectangleFilled(double x, double y, double w, double h, int color);
	~RectangleFilled();
	int setColor(int c) { int prev = color; color = c; return prev;}
};
