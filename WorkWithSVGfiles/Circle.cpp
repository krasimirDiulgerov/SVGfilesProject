#define _CRT_SECURE_NO_WARNINGS
#include"circle.h"
#include<iostream>
#include"rectangle.h"



Circle::Circle( Point& p, double radius, const char* colour):centre(p) {
	this->setRadius(radius);
	this->setColour(colour);


}

const Point& Circle::getCentre()const {
	return this->centre;
}

void Circle::setRadius(double radius) {
	this->radius = radius;

}

void Circle::setColour(const char* colour) {
	strcpy(this->colour, colour);
}

void Circle::print(std::ostream& out)const {
	out<<"  "<< "<circle " << "cx=\"" << centre.x << "\" cy=\"" << centre.y << "\" r=\"" << radius << "\" fill=\"" << colour << "\" " << "/>" << std::endl;
}

void Circle::read(std::istream& in) {
	char currentSymbol;
	char type[20];
	std::string cxValue;
	std::string cyValue;
	std::string radiusValue;
	std::string fillValue;
	std::string EndOfLine;
	std::string cxDouble;
	std::string cyDouble;
	std::string radiusDouble;
	std::string fill;
	double cx;
	double cy;
	double radius;
	char newColor[10];

	in.get(currentSymbol);
	if (currentSymbol == '<') {
		in >> type;
		if (strcmp(type, "circle") == 0) {
			in >> cxValue >> cyValue >> radiusValue >> fillValue >> EndOfLine;

			bool isFirstQ = false;
			for (int i = 0; i < cxValue.size(); i++) {
				if (cxValue[i] == '"' && isFirstQ == true) {
					break;
				}
				if (isFirstQ == true) {
					cxDouble.push_back(cxValue[i]);
				}
				if (cxValue[i] == '"' && isFirstQ == false) {
					isFirstQ = true;
				}
			}
			cx = strtod(cxDouble.c_str(), nullptr);

			 isFirstQ = false;
			for (int i = 0; i < cyValue.size(); i++) {
				if (cyValue[i] == '"' && isFirstQ == true) {
					break;
				}
				if (isFirstQ == true) {
					cyDouble.push_back(cyValue[i]);
				}
				if (cyValue[i] == '"' && isFirstQ == false) {
					isFirstQ = true;
				}
			}
			cy = strtod(cyDouble.c_str(), nullptr);

			 isFirstQ = false;
			for (int i = 0; i < radiusValue.size(); i++) {
				if (radiusValue[i] == '"' && isFirstQ == true) {
					break;
				}
				if (isFirstQ == true) {
					radiusDouble.push_back(radiusValue[i]);
				}
				if (radiusValue[i] == '"' && isFirstQ == false) {
					isFirstQ = true;
				}
			}
			radius = strtod(radiusDouble.c_str(), nullptr);

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
				newColor[i] = fill[i];
			}
			newColor[fill.size()] = '\0';

			Point p(cx, cy);
			this->centre = p;
			this->radius = radius;
			this->setColour(newColor);

		}
	}
}

Figure& Circle::translate(double horizontal, double vertical){
	centre.x += horizontal;
	centre.y += vertical;
	return *this;
}

bool Circle::containsPoint(const Point& p)const {
	if (centre.distanceTo(p) <= radius) {
		return true;
	}else {
		return false;
	}
	std::cout << "working";
}

const char* Circle::getType()const{
	return type;
}

void Circle::printOnConsole() {
	std::cout << "circle" <<" "<< centre.x << " " << centre.y << " " << radius << " " << this->colour << std::endl;
}

bool Circle::containedInCircle(Point& centreOne, double radiusOne)const {
	if ((this->centre.distanceTo(centreOne) + this->radius) <= radiusOne) {
		return true;
	}
	else{
		return false;
	}

}

bool Circle::containedInRectangle(Point& start, double width, double height)const {
	Rectangle Big(start, width, height, " ");
	Point one(this->centre.x + radius, this->centre.y);
	Point two(this->centre.x - radius, this->centre.y);
	Point three(this->centre.x, this->centre.y + radius);
	Point four(this->centre.x, this->centre.y - radius);
	if (Big.containsPoint(one) && Big.containsPoint(two) && Big.containsPoint(three) && Big.containsPoint(four)) {
		return true;
	}
	else {
		return false;
	}
}

Figure* Circle::clone()const {
	return new Circle(*this);
}
