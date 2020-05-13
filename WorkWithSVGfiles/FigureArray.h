#pragma once
#include"myVector.hpp";
#include"figure.h"
#include"line.h"
#include"rectangle.h"
#include"circle.h"
class FigureArray :public Figure {
private:
	myVector<Figure*> FigureVector;
	void copy(const FigureArray&);
	
public:
	FigureArray() = default;
	FigureArray(const FigureArray& other);
	FigureArray& operator=(const FigureArray& other);
	virtual ~FigureArray();
	Figure* operator[](int index);
	int getCountFigures()const;
	virtual void print(std::ostream& out)const;
	virtual void read(std::istream& in);
	virtual Figure& translate(double, double);
	bool containedInCircle(Point& centre, double radius)const;
	bool containedInRectangle(Point& start,double width,double height)const;
	virtual Figure* clone()const;
	virtual const char* getType()const;
	void translateFigureIndex(int n,double horizontal,double vertical);
	virtual bool containsPoint(const Point&)const;
	virtual void printOnConsole();
	void remove(int);
	void pushNewFigure(Figure*);
	void clear();
};
