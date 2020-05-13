#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED



#include<iostream>
#include"point.hpp"

class Figure {
 public:
	 Figure() {};
	virtual ~Figure(){}
	virtual void print(std::ostream& out)const = 0;
	virtual void read(std::istream& in) = 0;
	virtual Figure& translate(double horizontal, double vertical) = 0;
	virtual bool containsPoint(const Point&)const = 0;
	virtual const char* getType()const = 0;
	virtual void printOnConsole()=0;
	virtual bool containedInCircle(Point& centre, double radius)const = 0;
	virtual bool containedInRectangle(Point& start, double width, double height)const=0;
	virtual Figure* clone()const = 0;

};

#endif 