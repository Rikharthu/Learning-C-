#pragma once

class Figure{
protected:
	double x;
	double y;
public:
	Figure();
	Figure(double, double);
	~Figure();
	void setCoord(double x , double y) { this->x = x; this->y = y; }
	void getCoord(double *x , double *y) { *x = this->x; *y = this->y; }
};
