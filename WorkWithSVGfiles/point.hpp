#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include<cmath>
#include<iostream>
#include<iomanip>


struct Point {
	double x;
	double y;

	Point() = default;
	Point(double x, double y) :x{ x }, y{ y }{}

	Point& translate(int horizontal, int vertical) {
		x += horizontal;
		y += vertical;
	}

	double distanceTo(const Point& p)const {
		return std::sqrt((this->x - p.x) * (this->x - p.x) + (this->y - p.y) * (this->y - p.y));
	}

	friend std::istream& operator >> (std::istream& in, Point& p) {
		double x = 0;
		double y = 0;
		in >> x >> y;
		if (in) {
			p.x = x;
			p.y = y;
		}
		return in;
	}

	friend std::ostream& operator <<(std::ostream& out, const Point& p) {
		out << std::setiosflags(std::ios::fixed) << std::setprecision(1) << p.x << ' ' << p.y;
		return out;
	}
	Point& operator=(Point& other) {
		this->x = other.x;
		this->y = other.y;
		return *this;
	}
};

#endif

