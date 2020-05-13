#define _CRT_SECURE_NO_WARNINGS
#include"line.h"
#include<iostream>
#include"rectangle.h"


void Line::setColour(const char* colour){
	strcpy(this->colour, colour);

}

Line::Line(Point s, Point f, const char* colour):startingPoint(s),endingPoint(f){
	setColour(colour);

}

void Line::print(std::ostream& out)const {
	out<<"  "<< "<line sx=\"" << startingPoint.x << "\" sy=\"" << startingPoint.y << "\" enx=\"" << endingPoint.x << "\" eny=\"" << endingPoint.y << "\" fill=\"" << colour << "\" />" << std::endl;
}

void Line::read(std::istream& in){
	char currentSymbol;
	char type[20];
	std::string sxValue;
	std::string syValue;
	std::string enxValue;
	std::string enyValue;
	std::string fillValue;
	std::string EndLine;
	std::string sxDouble;
	std::string syDouble;
	std::string enxDouble;
	std::string enyDouble;
	std::string fill;
	double sx;
	double sy;
	double enx;
	double eny;
	char newColour[10];
	

	in.get(currentSymbol);
	if (currentSymbol == '<') {
		in >> type;
		if (strcmp(type, "line") == 0) {
			in >> sxValue >> syValue >> enxValue >> enyValue >> EndLine;

			bool isFirstQ = false;
			for (int i = 0; i < sxValue.size(); i++) {
				if (sxValue[i] == '"' && isFirstQ == true) {
					break;
				}
				if (isFirstQ == true) {
					sxDouble.push_back(sxValue[i]);
				}
				if (sxValue[i] == '"' && isFirstQ == false) {
					isFirstQ = true;
				}
			}
			sx = strtod(sxDouble.c_str(), nullptr);

			isFirstQ = false;
			for (int i = 0; i < syValue.size(); i++) {
				if (syValue[i] == '"' && isFirstQ == true) {
					break;
				}
				if (isFirstQ == true) {
					syDouble.push_back(syValue[i]);
				}
				if (syValue[i] == '"' && isFirstQ == false) {
					isFirstQ = true;
				}
			}
			sy = strtod(syDouble.c_str(), nullptr);

			 isFirstQ = false;
			for (int i = 0; i < enxValue.size(); i++) {
				if (enxValue[i] == '"' && isFirstQ == true) {
					break;
				}
				if (isFirstQ == true) {
					enxDouble.push_back(enxValue[i]);
				}
				if (enxValue[i] == '"' && isFirstQ == false) {
					isFirstQ = true;
				}
			}
			enx = strtod(enxDouble.c_str(), nullptr);

			 isFirstQ = false;
			for (int i = 0; i < enyValue.size(); i++) {
				if (enyValue[i] == '"' && isFirstQ == true) {
					break;
				}
				if (isFirstQ == true) {
					enyDouble.push_back(enyValue[i]);
				}
				if (enyValue[i] == '"' && isFirstQ == false) {
					isFirstQ = true;
				}
			}
			eny = strtod(enyDouble.c_str(), nullptr);

			isFirstQ = false;
			for (int i = 0; i < fillValue.size(); i++) {
				if (fillValue[i] == '"' && isFirstQ == true) {
					break;
				}
				if (isFirstQ == true) {
					fill.push_back(fillValue[i]);
				}
				if (fillValue[i] == '"' && isFirstQ == false) {
					isFirstQ = true;
				}
			}
			for (int i = 0; i < fill.size(); i++) {
				newColour[i] = colour[i];
			}
			newColour[fill.size()] = '\0';
			setColour(newColour);
		}
	}
	
}

Figure& Line::translate(double horizontal, double vertical){
	this->startingPoint.x += horizontal;
	this->endingPoint.x += horizontal;
	this->startingPoint.y += vertical;
	this->endingPoint.y += vertical;
	return *this;
}

const char* Line::getType()const{
	return type;
}

bool Line::containsPoint(const Point& p)const {
	return true;
}

void Line::printOnConsole() {
	std::cout << "line" << " " << startingPoint.x << " " << startingPoint.y << " " << endingPoint.x << " " << endingPoint.y<<" "<<colour << std::endl;
}

bool Line::containedInCircle(Point& centre, double radius)const {
	if (startingPoint.distanceTo(centre) <= radius && endingPoint.distanceTo(centre) <= radius) {
		return true;
	}
	else {
		return false;
	}

}

bool Line::containedInRectangle(Point& start, double width, double height)const {
	Rectangle Big(start, width, height, " ");
	if (Big.containsPoint(startingPoint)&& Big.containsPoint(endingPoint)) {
		return true;
	}
	else {
		return false;
	}
	
}

Figure* Line::clone()const {
	return new Line(*this);
}