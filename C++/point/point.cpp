// This class represents the cartesian point.

#include "point.h"

point::point(const point& p) {
	x = p.getx();
	y = p.gety();
}

double point::getx(void) const {
	return x;
}

double point::gety(void) const {
	return y;
}

void point::setx(const double x) {
	this->x = x;
}

void point::sety(const double y) {
	this->y = y;
}

point point::operator+ (const point& p) {
	point p1;
	p1.setx(this->x + p.getx());
	p1.sety(this->y + p.gety());
	return p1;
}

point::~point() {}

ostream& operator<< (ostream& out, const point& p) {
	out << "(" << p.getx() << ", " << p.gety() << ")";
	return out;
}
