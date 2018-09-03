// This class represents the cartesian point.

#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

class point {
	private:
		double x;
		double y;

	public:
		point(const double x = 0.0, const double y = 0.0) : x(x), y(y) {}
		point(const point& p);
		double getx(void) const;
		double gety(void) const;
		void setx(const double x);
		void sety(const double y);
		point operator+ (const point& p);
		~point();
};

ostream& operator<< (ostream& out, const point& p);

#endif //POINT_H
