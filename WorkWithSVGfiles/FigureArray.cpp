#include"FigureArray.h"

FigureArray::FigureArray(const FigureArray& other){
	this->copy(other);
}

FigureArray& FigureArray:: operator=(const FigureArray& other){
	if (this != &other) {
		this->clear();
		this->copy(other);
		
	}
	return *this;
}

FigureArray:: ~FigureArray(){
	this->clear();
}

Figure* FigureArray:: operator[](int index){
	return this->FigureVector[index];
}

int FigureArray::getCountFigures()const{
	return this->FigureVector.getSize();
}

void FigureArray::print(std::ostream& out)const{
	for (int i = 0; i < this->getCountFigures(); i++) {
		this->FigureVector[i]->print(out);

	}
}

void FigureArray::read(std::istream& in){
	while (in) {
		char currentSymbol;
		char type[20];
		bool isCircle = false;
		bool isRectangle = false;
		bool isLine = false;
		std::streampos figureBeginning = in.tellg();
		in.get(currentSymbol);
		Figure* newFigure = nullptr;
		if (currentSymbol == '<') {
			in >> type;
			if (strcmp(type, "rect") == 0)isRectangle = true;
			if (strcmp(type, "circle") == 0)isCircle = true;
			if (strcmp(type, "line") == 0)isLine = true;
			
			if (isRectangle) {
				newFigure = new Rectangle();
				in.seekg(figureBeginning);
				newFigure->read(in);
				FigureVector.push_back(newFigure);
				
			}
			if (isCircle) {
				newFigure = new Circle();
				in.seekg(figureBeginning);
				newFigure->read(in);
				FigureVector.push_back(newFigure);
			}
			if (isLine) {
				newFigure = new Line();
				in.seekg(figureBeginning);
				newFigure->read(in);
				FigureVector.push_back(newFigure);
			}

		}
	}
}

Figure& FigureArray::translate(double horizontal, double vertical){
	for (int i = 0; i<FigureVector.getSize(); i++) {
		FigureVector[i]->translate(horizontal, vertical);
	}
	return *this;

}

bool FigureArray::containedInCircle(Point& centre,double radius)const{
	bool Found = false;
	for (int i = 0; i < FigureVector.getSize(); i++) {
		if (FigureVector[i]->containedInCircle(centre, radius) == true) {
			Found = true;
		}

	}
	if (!Found) { 
		std::cout << "No figures are located within circle " << centre.x << " " << centre.y << " " << radius << std::endl;
		return false; 
	}
	if (Found) {
		std::cout<<"Within circle " << centre.x << " " << centre.y << " " << radius << std::endl;
		int count = 1;
		for (int i = 0; i < FigureVector.getSize(); i++) {
			if (FigureVector[i]->containedInCircle(centre, radius) == true) {
				std::cout << count << ". ";
				FigureVector[i]->printOnConsole();
				count++;
			}

		}
		return true;
	}
}

bool FigureArray::containedInRectangle(Point& start,double width,double height)const {
	bool Found = false;
	for (int i = 0; i < FigureVector.getSize(); i++) {
		if (FigureVector[i]->containedInRectangle(start, width, height) == true) {
			Found = true;
		}

	}
	if (!Found) {
		std::cout << "No figures within rectangle " << start.x << " " << start.y << " " << width << " " << height << std::endl;
		return false;
	}
	if (Found) {
		std::cout<<"Figures within rectangle " << start.x << " " << start.y << " " << width << " " << height << std::endl;
		int count=1;
		for (int i = 0; i < FigureVector.getSize(); i++) {
			if (FigureVector[i]->containedInRectangle(start, width, height) == true) {
				std::cout << count << ". ";
				FigureVector[i]->printOnConsole();
				count++;
			}
			return true;
		}
	}
}

Figure* FigureArray::clone()const{
	return new FigureArray(*this);
}

const char* FigureArray::getType()const{
	return "FigureArray";
}

void FigureArray::translateFigureIndex(int n,double horizontal,double vertical) {
	this->FigureVector[n]->translate(horizontal, vertical);
}

bool FigureArray::containsPoint(const Point&)const {
	return true;
}

void FigureArray::printOnConsole() {
	for (int i = 0; i < FigureVector.getSize(); i++) {
		std::cout << i+1 << "." << " ";
		FigureVector[i]->printOnConsole();
	}
}

void FigureArray::copy(const FigureArray& other) {
	
	for (int i = 0; i < other.FigureVector.getSize(); i++) {
		FigureVector.push_back(other.FigureVector[i]);

	}
}

void FigureArray::remove(int n) {
	this->FigureVector.remove(n);

}

void FigureArray::pushNewFigure(Figure* newFig) {
	Figure* newFigure = newFig->clone();
	FigureVector.push_back(newFigure);
}

void FigureArray::clear() {
	FigureVector.clear();
}