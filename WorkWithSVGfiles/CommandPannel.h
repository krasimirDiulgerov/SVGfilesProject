#pragma once
#include<iostream>
#include"myVector.hpp"
#include"FigureArray.h"
#include<iostream>
#include<fstream>
///This is the core of the program.Here I define all commands.
class CommandPannel {


public:
	///this function opens a file and loads the information in it
	///@param array is where all the information is gathered
	///@param in is the stream we use to take the information
	void open(FigureArray& array,std::istream& in);
	///this function closes the opened file and erases all the information we have gathered
	///@param array is the information we have
	void close(FigureArray&array);
	///this function saves all the information we have in the file we took it from
	///@param out is the stream we will use to save the info 
	///@param info is the information we want to save
	void save(std::ostream& out, FigureArray& info);
	///prints all the functions we can use
	void help();
	///exits the program
	void exit();
	///prints all the information we have on the console
	///@param info the information we have
	void print(FigureArray& info);
	///this function creates a Rectangle using specific parameters
	///@param start this is the Point we want our Rectangle to start from
	///@param width this is the length of the horizontal walls of the Rectangle
	///@param height this is the length of the vertical walls of the Rectangle
	///@param colour this is the colour of the Rectangle
	///@param other this is the information we have by now and the place we want to save our new Rectangle
	void createRect(Point& start, double width, double height, const char* colour, FigureArray& other);
	///this function creates a Circle using specific parameters
	///@param centre is the Point we want to be a centre of our new Circle
	///@param radius is the length of the radius of our new Circle
	///@param colour is the colour we want our new Circle to be
	///@param array  is the information we have by now and the place we want to save our new Circle
	void createCircle(Point& centre, double radius, const char* colour, FigureArray& array);
	/// this function creates a Line using specific parameters
	///@param start is the Point wherewe want our line to start from
	///@param end is the Point where we want our line to end
	///@param colour is the colour of our new Line
	///@param array is the information we have by now and the place we want to save our new Line
	void createLine(Point& start, Point& end, const char* colour, FigureArray& array);
	///this function prints all Figures that are within a specific Circle
	///@param centre is the centre Point of the big Circle
	///@param radius is the length of the radius of the big Circle 
	///@param info is the information we have(all Figures that we want to check)
	void withinCircle(Point& centre,double radius,FigureArray& info);
	///this function prints all Figures that are within a specific Rectangle
	///@param start is the starting Point of the Rectangle
	///@param width is the length of the horizontal walls of our Rectangle
	///@param height is the length of the vertical walls of our Rectangle
	///@param info is the information we have(all Figures that we want to check)
	void withinRectangle(Point& start,double width,double height,FigureArray& info);
	/// deletes a Figure at a certain position
	///@param position is the position of the Figure we want to delete
	///@param info is the information we have 
	void erase(int position,FigureArray& info);
	///this function moves a specific Figure or all of the horizontally and vertically
	///@param position is if you want to move only one Figure
	///@param info is the information we have 
	///@param horizontal is how much we want to move the figures horizontally
	///@param vertical is how much we want to move the figures vertically
	void translate(int position,FigureArray& info,double horizontal,double vertical);
	///used in the main to start the program
	void startProgram();
	
};
