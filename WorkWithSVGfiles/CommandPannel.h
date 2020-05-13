#pragma once
#include<iostream>
#include"myVector.hpp"
#include"FigureArray.h"
#include<iostream>
#include<fstream>
class CommandPannel {


public:
	void open(FigureArray& ,std::istream&);
	void close(FigureArray&);
	void save(std::ostream&, FigureArray&);
	void help();
	void exit();
	void print(FigureArray&);
	void createRect(Point& start, double width, double height, const char* colour, FigureArray& other);
	void createCircle(Point& centre, double radius, const char* colour, FigureArray& array);
	void createLine(Point&, Point&, const char* colour, FigureArray& array);
	void withinCircle(Point&,double,FigureArray&);
	void withinRectangle(Point&,double,double,FigureArray&);
	void erase(int,FigureArray&);
	void translate(int,FigureArray&,double,double);
	void startProgram();
	
};
