#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED
#include"figure.h"
#include<iostream>

///self-explanatory
///
/// blqq
class Circle :public Figure {
private:
	char type[10] = "circle";
	double radius;
	Point centre;
	char colour[10];
public:
	///default constructor 
	Circle() = default;
	///constructor
	///this constructur takes 3 parameters
	///@param p we take a Point for the centre
	///@param radius we take the lenght of the radius
	///@param we take the colour we want our circle to be
	Circle( Point& p, double radius, const char* colour);
	///get function for the centre of the circle
	const Point& getCentre()const;
	///set function for the radius of the circle
	void setRadius(double radius);
	///set function for the colour of the circle
	void setColour(const char* colour);
	///this print function is used to print the circle in specific file
	///@param out we give the name of the stream we want to use to save the Circle
	virtual void print(std::ostream& out)const ;
	///this function is used to read information about a circle and set those values to our current object
	///@param in  we give the name of the stream we want to use to read the information
	virtual void read(std::istream& in) ;
	///this function moves our circle horizontal or vertical 
	///@param horizontal is how much we want to move our circle horizontally
	///@param vertical is how much we want to move our circle vertically
	virtual Figure& translate(double horizontal, double vertical) ;
	///we use this bool function to decide whether or not our circle contains a specific point
	///@param p we give the point we want to test 
	virtual bool containsPoint(const Point&)const;
	///this is a get function for the Type of our Figure all classes have one
	virtual const char* getType()const ;
	///this function prints our circle on the console
	virtual void printOnConsole();
	/// this function is used to decide whether our circle is contained within another circle with specific parameters
	///@param centre we give the centre point of the circle we are checking 
	///@param we give the radius value of the circle we are checking
	virtual bool containedInCircle(Point& centre, double radius)const;
	///this function is used to decide whether our circle is contained within a Rectangle with specific parameters
	///@param start we take the bottom left corner of the rectangle
	///@param width we take the length of the horizontal walls of the rectangle
	///@param height we take the length of the vertical walls of the rectangle
	virtual bool containedInRectangle(Point& start, double width, double height)const;
	///this function is used to create clone objects to our circle
	virtual Figure* clone()const;
};
#endif // CIRCLE_H_INCLUDED