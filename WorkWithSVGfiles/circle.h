#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED
#include"figure.h"
#include<iostream>


class Circle :public Figure {
private:
	char type[10] = "circle";
	double radius;
	Point centre;
	char colour[10];
public:
	Circle() = default;
	Circle( Point& p, double radius, const char* colour);
	const Point& getCentre()const;
	void setRadius(double radius);
	void setColour(const char* colour);
	virtual void print(std::ostream& out)const ;
	virtual void read(std::istream& in) ;
	virtual Figure& translate(double horizontal, double vertical) ;
	virtual bool containsPoint(const Point&)const;
	virtual const char* getType()const ;
	virtual void printOnConsole();
	virtual bool containedInCircle(Point& centre, double radius)const;
	virtual bool containedInRectangle(Point& start, double width, double height)const;
	virtual Figure* clone()const;
};
#endif // CIRCLE_H_INCLUDED