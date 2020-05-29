#pragma once
#include"myVector.hpp";
#include"figure.h"
#include"line.h"
#include"rectangle.h"
#include"circle.h"
///this class is used to keep the information gathered from the files.It contains a vector of addresses of Figures
///this class inherits Figure because all functions of Figure are useful for it
class FigureArray :public Figure {
private:
	myVector<Figure*> FigureVector;
	void copy(const FigureArray&);
	
public:
	///constructor
	FigureArray() = default;
	///copy-constructor
	FigureArray(const FigureArray& other);
	///operator =
	FigureArray& operator=(const FigureArray& other);
	///destructor
	virtual ~FigureArray();
	///operator []
	Figure* operator[](int index);
	///return the amount of Figures we have in our array
	int getCountFigures()const;
	///this function saves all the Figures in our array in a specific file
	///@param our this is the stream we use to access the file
	virtual void print(std::ostream& out)const;
	///this function reads information about Figures and saves them in our array
	virtual void read(std::istream& in);
	///this function translates all the Figures within horizontally and vertically
	///@param horizontal is how much we want to move our Figures horizontally
	///@param vertical is how much we want to move our Figures vertically
	virtual Figure& translate(double horizontal, double vertical);
	///this function prints all the Figures that are within a specific  Circle if there are any
	///@param centre is the centre Point of our Circle
	///@param radius is the length of the radius of our Circle
	bool containedInCircle(Point& centre, double radius)const;
	///this function prints all the Figures that are within a specific Rectangle if there are any
	///@param start is the starting Point of our Rectangle
	///@param width is the length of the horizontal walls of our Rectangle
	///@param height is the length of the vertical walls of our Rectangle
	bool containedInRectangle(Point& start,double width,double height)const;
	///this function creates a clone of our object
	virtual Figure* clone()const;
	///this is a get function of the type
	virtual const char* getType()const;
	///this function translates a specific Figure or all of them horizontally and vertically
	///@param n is the position of the Figure you want to translate
	///@param horizontal is how much we want to translate the Figure/figures horizontally
	///@param vertical is how much we want to translate the Figure/figures vertically
	void translateFigureIndex(int n,double horizontal,double vertical);
	///this function returns whether we have a Figure that contains a specific Point
	///@param p is the Point we are searching for
	virtual bool containsPoint(const Point& p)const;
	///this function prints our array on the console
	virtual void printOnConsole();
	///this function removes a Figure at a specific position
	///@param pos is the position we want 
	void remove(int pos);
	///this function adds new Figure to our array
	///@param figure is the address of the Figure we want to add
	void pushNewFigure(Figure* figure);
	///this function clears the array
	void clear();
};
