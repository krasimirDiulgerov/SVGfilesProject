#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED
#include"figure.h"

///self-explanatory
class Rectangle :public Figure {
private:
	char type[10] = "rectangle";
	double width;
	double height;
	Point startingPoint;
	char colour[10];

public:
	/// this function sets the colour of our Rectangle
	///@param colour is the colour we want the Rectangle to be
	void setColour(const char* colour);
	///constructor
	Rectangle() = default;
	///constructor
	Rectangle(Point, double, double, const char*);
	///this function saves our Rectangle in a specific file
	///@param out is the stream we use to reach the file
	virtual void print(std::ostream& out)const ;
	///this function reads information about a Rectangle from a file and sets it for ours
	///@param in is the stream we use to reach the file
	virtual void read(std::istream& in) ;
	///this function translates our Rectangle horizontally and vertically
	///@param horizontal is how much we want to move our Rectangle horizontally
	///@param vertical is how much we want to move our Rectangle vertically
	virtual Figure& translate(double horizontal, double vertical) ;
	///this function checks whether a specific Point is within our Rectangle
	///@param p is the Point we are checking for
	virtual bool containsPoint(const Point& p)const;
	///this is a get function for the type of the Figure
	virtual const char* getType()const;
	///this function prints the information of our Rectangle on the console
	virtual void printOnConsole();
	///this function checks whether our Rectangle is within a Circle with specific parameters
	///@param centre is the central Point of the Circle
	///@param radius is the length of the radius of the Circle
	virtual bool containedInCircle(Point& centre, double radius)const;
	///this function checks whether our Rectangle is within a Rectangle with specific parameters
	///@param start is the starting Point of the Rectangle
	///@param width is the length of the horizontal walls of the Rectangle
	///@param height is the length of the vertical walls of the Rectangle
	virtual bool containedInRectangle(Point& start, double width,double height)const;
	///creates clone of our Rectangle
	virtual Figure* clone()const;
};
#endif

