#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED
#include"figure.h"


class Rectangle :public Figure {
private:
	char type[10] = "rectangle";
	double width;
	double height;
	Point startingPoint;
	char colour[10];

public:
	
	void setColour(const char* colour);
	Rectangle() = default;
	Rectangle(Point, double, double, const char*);
	virtual void print(std::ostream& out)const ;
	virtual void read(std::istream& in) ;
	virtual Figure& translate(double horizontal, double vertical) ;
	virtual bool containsPoint(const Point&)const;
	virtual const char* getType()const;
	virtual void printOnConsole();
	virtual bool containedInCircle(Point& centre, double radius)const;
	virtual bool containedInRectangle(Point& start, double width,double height)const;
	virtual Figure* clone()const;
};
#endif

