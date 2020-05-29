#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED
#include"figure.h"

///self-explanatory
class Line :public Figure {
private:
	char type[10] = "line";
	Point startingPoint;
	Point endingPoint;
	char colour[10];
public:
	///this function sets the colour of our Line
	///@param colour is the colour we want our Line to be
	void setColour(const char* colour);
	///constructor
	Line()=default;
	///constructor
	Line(Point, Point,const char*);
	///this function saves the information of our Line in a file
	///@param out is the stream we use to reach the file
	virtual void print(std::ostream& out)const ;
	///this function reads information about a Line from a file and sets it for our Line
	///@param in is the stream we use to reach the file
	virtual void read(std::istream& in) ;
	///this function moves our Line horizontally and vertically
	///@param horizontal is how much we want to move the Line horizontally
	//@param vertical is how much we want to move the Line vertically
	virtual Figure& translate(double horizontal, double vertical);
	///this function returns the type of the Figure(Line)
	virtual const char* getType()const;
	///this function checks if a certain Point is within our Line
	///@param p is the Point we are checking for
	virtual bool containsPoint(const Point& p)const;
	///this function prints the information about our Line on the console
	virtual void printOnConsole();
	///this function checks if our Line is within a Circle with specific parameters
	///@param centre is the central Point of the Circle
	///@param radius is the length of the radius of the Circle
	virtual bool containedInCircle(Point& centre, double radius)const;
	///this function checks if our Line is within a Circle with specific parameters
	///@param start is the starting Point of the Rectangle
	///@param width is the length of the horizontal walls of the Rectangle
	///@param height is the length of the vertical walls of the Rectangle
	virtual bool containedInRectangle(Point& start, double width, double height)const;
	///this function clones our Line
	virtual Figure* clone()const;
};
#endif
