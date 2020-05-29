#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include<cmath>
#include<iostream>
#include<iomanip>

///This is a structure I use to describe Figure
struct Point {
	double x;
	double y;
	///constructor
	Point() = default;
	///constructor
	Point(double x, double y) :x{ x }, y{ y }{}
	///translates the Point horizontally and vertically
	///@param horizontal how much do we want to translate it horizontally
	///@param vertical how much we want to translate it vertically
	Point& translate(int horizontal, int vertical) { 
		x += horizontal;
		y += vertical;
	}
	///this function gives us the distance between this Point and another Point
	///@param p is the other Point
	double distanceTo(const Point& p)const {
		return std::sqrt((this->x - p.x) * (this->x - p.x) + (this->y - p.y) * (this->y - p.y));
	}
	/// this function helps us to read information about a Point and to set it
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
	///this function helps us to save information about our Point in a file
	friend std::ostream& operator <<(std::ostream& out, const Point& p) {
		out << std::setiosflags(std::ios::fixed) << std::setprecision(1) << p.x << ' ' << p.y;
		return out;
	}
	///this is operator =
	Point& operator=(Point& other) {
		this->x = other.x;
		this->y = other.y;
		return *this;
	}
};

#endif

