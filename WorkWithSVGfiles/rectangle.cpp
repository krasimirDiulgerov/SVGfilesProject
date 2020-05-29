#define _CRT_SECURE_NO_WARNINGS
#include"rectangle.h"
#include<iostream>
#include<string>


void Rectangle::setColour(const char* colour) {
	strcpy(this->colour, colour);

}

Rectangle::Rectangle(Point p, double width, double height, const char* colour):startingPoint(p){
	this->width = width;
	this->height = height;
	this->setColour(colour);
}

void Rectangle::print(std::ostream& out)const{
	out<<"  "<< "<rect x=\"" << startingPoint.x << "\" y=\"" << startingPoint.y << "\" width=\"" << width << "\" height=\"" << height << "\" fill=\"" << colour << "\" />" << std::endl;
}

Figure& Rectangle::translate(double horizontal, double vertical){
	startingPoint.x += horizontal;
	startingPoint.y += vertical;
	return *this;
}

bool Rectangle::containsPoint(const Point& p)const{
	if (this->width > 0) {
		if (this->height > 0) {
			if (p.x >= startingPoint.x && p.x <= startingPoint.x + width && p.y >= startingPoint.y && p.y <= startingPoint.y + height) {
				return true;
			}
			else {
				return false;
			}

		}
		else {
			if (p.x >= startingPoint.x && p.x <= startingPoint.x + width && p.y >= startingPoint.y + height && p.y <= startingPoint.y) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	else {
		if (this->height > 0) {
			if (p.x <= startingPoint.x && p.x >= startingPoint.x + width && p.y >= startingPoint.y && p.y <= startingPoint.y + height) {
				return true;
			}
			else {
				return false;
			}

		}
		else {
			if (p.x <= startingPoint.x && p.x >= startingPoint.x && p.y <= startingPoint.y && p.y >= startingPoint.y) {
				return true;
			}
			else {
				return false;
			}

		}


	}

}

const char* Rectangle::getType()const{
	return type;
}

void Rectangle::read(std::istream& in) {
	
		char currentSymbol;
		char type[20];
		std::string xValue;
		std::string yValue;
		std::string widthValue;
		std::string heightValue;
		std::string fillValue;
		std::string endoFLine;
		std::string xDouble;
		std::string yDouble;
		std::string widthDouble;
		std::string heightDouble;
		double x;
		double y;
		double width;
		double height;
		std::string colour;


		in.get(currentSymbol);
		if (currentSymbol == '<') {
			in >> type;
			if (strcmp(type, "rect") == 0) {
				in >> xValue >> yValue >> widthValue >> heightValue >> fillValue >> endoFLine;

				bool isFirstQ = false;
				//here I extract the x value of the starting Point
				for (int i = 0; i < xValue.size(); i++) {
					if (xValue[i] == '"' && isFirstQ == true) {
						break;
					}
					if (isFirstQ == true) {
						xDouble.push_back(xValue[i]);
					}
					if (xValue[i] == '"' && isFirstQ == false) {
						isFirstQ = true;
					}
				}
				//here I convert it to double
				x = strtod(xDouble.c_str(), nullptr);
				
				isFirstQ = false;
				//here I extract the y value of the starting Point of the Rectangle
				for (int i = 0; i < yValue.size(); i++) {
					if (yValue[i] == '"' && isFirstQ == true) {
						break;
					}
					if (isFirstQ == true) {
						yDouble.push_back(yValue[i]);
					}
					if (yValue[i] == '"' && isFirstQ == false) {
						isFirstQ = true;
					}
				}
				//here I convert it to double
				y = strtod(yDouble.c_str(), nullptr);
				
				isFirstQ = false;
				//here I extract the width value of the Rectangle
				for (int i = 0; i < widthValue.size(); i++) {
					if (widthValue[i] == '"' && isFirstQ == true) {
						break;
					}
					if (isFirstQ == true) {
						widthDouble.push_back(widthValue[i]);
					}
					if (widthValue[i] == '"' && isFirstQ == false) {
						isFirstQ = true;
					}
				}
				//here I convert it to double
				width = strtod(widthDouble.c_str(), nullptr);
				
				isFirstQ = false;
				//here I extract the height value of the Rectangle
				for (int i = 0; i < heightValue.size(); i++) {
					if (heightValue[i] == '"' && isFirstQ == true) {
						break;
					}
					if (isFirstQ == true) {
						heightDouble.push_back(heightValue[i]);
					}
					if (heightValue[i] == '"' && isFirstQ == false) {
						isFirstQ = true;
					}
				}
				//here I convert it to double
				height = strtod(heightDouble.c_str(), nullptr);

				int count = 0;
				isFirstQ = false;
				for (int i = 0; i < fillValue.size(); i++) {
					if (fillValue[i] == '"' && isFirstQ == true) {
						break;
					}
					if (isFirstQ == true) {
						colour.push_back(fillValue[i]);
					}
					if (fillValue[i] == '"' && isFirstQ == false) {
						isFirstQ = true;
					}
				}
				char newColor[10];
				for (int i = 0; i < colour.size(); i++) {
					newColor[i] = colour[i];
				}
				newColor[colour.size()] = '\0';
				Point p(x, y);
				this->startingPoint = p;
				this->width = width;
				this->height = height;
				this->setColour(newColor);


				
			}
		}
	
}

void Rectangle::printOnConsole() {
	std::cout << "rectangle" << " " << startingPoint.x << " " << startingPoint.y << " " << width << " " << height << " " << colour << std::endl;

}

bool Rectangle::containedInCircle(Point& centre, double radius)const {
	Point one(startingPoint.x, startingPoint.y + height);
	Point two(startingPoint.x + width, startingPoint.y);
	Point three(startingPoint.x + width, startingPoint.y + height);
	if (startingPoint.distanceTo(centre) <= radius && one.distanceTo(centre) <= radius && two.distanceTo(centre) <= radius && three.distanceTo(centre) <= radius) {
		return true;
	}
	else {
		return false;
	}

}

bool Rectangle::containedInRectangle(Point& start, double width, double height)const {
	Point one(this->startingPoint.x, this->startingPoint.y + this->height);
	Point two(this->startingPoint.x + this->width, this->startingPoint.y);
	Point three(this->startingPoint.x + this->width, this->startingPoint.y + this->height);
	Rectangle Big(start, width, height," ");
	if (Big.containsPoint(one) && Big.containsPoint(two) && Big.containsPoint(three) && Big.containsPoint(startingPoint)) {
		return true;
	}
	else {
		return false;
	}

}

Figure* Rectangle::clone()const {
	return new Rectangle(*this);
}