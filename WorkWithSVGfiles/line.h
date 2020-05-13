#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED
#include"figure.h"


class Line :public Figure {
private:
	char type[10] = "line";
	Point startingPoint;
	Point endingPoint;
	char colour[10];
public:
	void setColour(const char* colour);
	Line()=default;
	Line(Point, Point,const char*);
	virtual void print(std::ostream& out)const ;
	virtual void read(std::istream& in) ;
	virtual Figure& translate(double horizontal, double vertical);
	virtual const char* getType()const;
	virtual bool containsPoint(const Point&)const;
	virtual void printOnConsole();
	virtual bool containedInCircle(Point& centre, double radius)const;
	virtual bool containedInRectangle(Point& start, double width, double height)const;
	virtual Figure* clone()const;
};
#endif
