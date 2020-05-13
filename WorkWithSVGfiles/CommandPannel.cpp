#define _CRT_SECURE_NO_WARNINGS
#include"CommandPannel.h"

double extractNumber(std::string sentence) {
	double number = 0;
	sentence.push_back('.');
	for (int i = 0; i < (int)sentence.size(); i++) {
		bool isDigit = false;
		if (sentence[i] >= '0' && sentence[i] <= '9') {
			isDigit = true;
		}
		if (isDigit) {
			number = number * 10 + sentence[i] - '0';
		}
		if (!isDigit) {
			if (number > 0.0 || number<0.0) {
				return number;
			}
		}

	}
}

void CommandPannel::open(FigureArray& array,std::istream& in){
	array.read(in);
	
}

void CommandPannel::close(FigureArray& array){
	array.clear();

}

void CommandPannel::save(std::ostream& out, FigureArray& array){
	out << "<?xml version=\"1.0\" standalone=\"no\"?>" << std::endl;
	out << "<!DOCTYPE svg PUBLIC \" -//W3C//DTD SVG 1.1//EN\"" << std::endl;
	out << " \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" << std::endl;
	out << "<svg>" << std::endl;
	array.print(out);
	out << "<svg>" << std::endl;
}

void CommandPannel::help(){
	std::cout << "The following commands are supported:" << std::endl;
	std::cout << "open<file>       opens<file" << std::endl;
	std::cout << "close            closes currently opened file" << std::endl;
	std::cout << "save             saves currently open file" << std::endl;
	std::cout << "saveas<file>     saves the currently open file in<file> " << std::endl;
	std::cout << "help             prints this info" << std::endl;
	std::cout << "exit             exits the program" << std::endl;
	std::cout << "print            prints all the figures" << std::endl;
	std::cout << "create           creates new figure" << std::endl;
	std::cout << "erase <n>        deletes figure with position <n>" << std::endl;
	std::cout << "translate[<n>]   Moves the figure with position <n> or all figures if n is not specified" << std::endl;
	std::cout << "within<option>  Shows all figures within a region(which can be circle or rectangle" << std::endl;
}

void CommandPannel::exit() {
	std::cout << "EXIT" << std::endl;
}

void CommandPannel::print(FigureArray& array){
	array.printOnConsole();


}

void CommandPannel::createRect(Point& start,double width,double height,const char* colour,FigureArray& other){
	Rectangle* figure=new Rectangle(start, width, height, colour);
	std::cout << "Successfully created rectangle" << "(" << other.getCountFigures() + 1 << ")" << std::endl;
	other.pushNewFigure(figure);
}

void CommandPannel::createCircle(Point& centre, double radius, const char* colour, FigureArray& array) {
	Circle* figure = new Circle(centre, radius, colour);
	std::cout << "Successfully created circle " << "(" << array.getCountFigures() + 1 << ")" << std::endl;
	array.pushNewFigure(figure);

}

void CommandPannel::createLine(Point& start, Point& end, const char* colour, FigureArray& array) {
	Line* figure = new Line(start, end, colour);
	std::cout << "Successfully created a line " << "(" << array.getCountFigures() + 1 << ")" << std::endl;
	array.pushNewFigure(figure);

}

void CommandPannel::withinCircle(Point& centre,double radius,FigureArray& array){
	array.containedInCircle(centre, radius);
}

void CommandPannel::withinRectangle(Point& start,double width,double height,FigureArray& array){
	array.containedInRectangle(start, width, height);
}

void CommandPannel::erase(int n,FigureArray& array){
	if (n > array.getCountFigures()) {
		std::cout << "There is no figure number " << n << std::endl;
		return;
	}
	char type[20];
	strcpy(type, array[n-1]->getType());
	std::cout << "Erased a " << type << " " <<"("<< n <<")"<< std::endl;
		array.remove(n-1);
	
	

}

void CommandPannel::translate(int n,FigureArray& array,double width,double height){
	if (n-1 < 0) {
		array.translate(width, height);
		std::cout << "Translated all figure!" << std::endl;
	}
	if (n-1 > array.getCountFigures()) {
		std::cout << "There are no figures with index" << n << std::endl;
		return;
	}if (n-1 >= 0 && n-1 <= array.getCountFigures()) {

		array.translateFigureIndex(n-1,width,height);
		std::cout << "Figure translated!" << std::endl;

	}
}

void CommandPannel::startProgram(){
	FigureArray array;
	bool openedFile = false;
	std::string NameOfFile;
	while (true) {
		
		char command[20];
		
		std::cin >> command;
		if (openedFile == false) {
			if (strcmp(command, "open") == 0) {
				openedFile = true;
			}
		}

		if (openedFile == true) {

			if (strcmp(command, "open") == 0) {
				
				std::cin >> NameOfFile;
				NameOfFile.push_back('.');
				NameOfFile.push_back('t');
				NameOfFile.push_back('x');
				NameOfFile.push_back('t');
				std::ifstream inFile(NameOfFile, std::ios::in);
				
				if (!inFile) {
					std::cerr << "File couldnt be opened! \n";
				}
				if (inFile) {
					std::cout << "Successfully opened ";
					for (int i = 0; i <(int) NameOfFile.size()-4; i++) {
						std::cout << NameOfFile[i];
					}
					std::cout << std::endl;
					this->open(array, inFile);
					inFile.close();
				}
			}

			if (strcmp(command, "close") == 0) {
				openedFile = false;
				std::cout << "Successfully closed " << NameOfFile << std::endl;
				this->close(array);

			}

			if (strcmp(command, "save") == 0) {
				std::cout << "Successfully saved the changes to ";
				for (int i = 0; i < (int)NameOfFile.size() - 4; i++) {
					std::cout << NameOfFile[i];
				}
				std::cout << std::endl;
				std::ofstream oFile;
				oFile.open(NameOfFile, std::ios::out, std::ios::trunc);
				if (!oFile) {
					std::cerr << "File couldnt be opened! \n";
				}
				this->save(oFile, array);
				oFile.close();
			}

			if (strcmp(command, "saveas") == 0) {
				std::string nameFile;
				std::cin >> nameFile;
				nameFile.push_back('.');
				nameFile.push_back('t');
				nameFile.push_back('x');
				nameFile.push_back('t');
				std::ofstream oFile;
				oFile.open(nameFile, std::ios::out, std::ios::trunc);
				if (!oFile) {
					std::cerr << "File couldnt be opened! \n";
				}
				this->save(oFile, array);
				std::cout << "Successfully saved the changes to ";
				for (int i = 0; i < (int)nameFile.size() - 4; i++) {
					std::cout << nameFile[i];
				}
				std::cout << std::endl;
				oFile.close();

			}

			if (strcmp(command, "help") == 0) {
				this->help();

			}

			if (strcmp(command, "exit") == 0) {
				this->exit();
				break;

			}

			if (strcmp(command, "print") == 0) {
				array.printOnConsole();

			}

			if (strcmp(command, "create") == 0) {
				char type[20];
				std::cin >> type;
				if (strcmp(type, "rectangle") == 0) {
					double x;
					double y;
					double width;
					double height;
					char colour[20];
					std::cin >> x >> y >> width >> height >> colour;
					Point p(x, y);
					this->createRect(p, width, height, colour, array);
				}
				if (strcmp(type, "circle") == 0) {
					double x;
					double y;
					double radius;
					char colour[20];
					std::cin >> x >> y >> radius >> colour;
					Point p(x, y);
					this->createCircle(p, radius, colour, array);
				}
				if (strcmp(type, "line") == 0) {
					double x1;
					double y1;
					double x2;
					double y2;
					char colour[20];
					std::cin >> x1 >> y1 >> x2 >> y2 >> colour;
					Point one(x1, y1);
					Point two(x2, y2);
					this->createLine(one, two, colour, array);
				}
			}

			if (strcmp(command, "erase") == 0) {
					int n;
					std::cin >> n;
					this->erase(n, array);
				

			}

			if (strcmp(command, "translate") == 0) {
				bool isTypedNumber = false;
				std::string one;
				std::string two;
				std::string three;
				double verticalD;
				double horizontalD;
				double n;
				char letter;
				
				std::cin >> one >> two;
				std::cin.get(letter);
				if (letter != '\n') {
					isTypedNumber = true;
					std::cin >> three;
				}
				if (isTypedNumber) {
					n = extractNumber(one);
					verticalD = extractNumber(two);
					horizontalD = extractNumber(three);
					translate(n, array, verticalD, horizontalD);
				}
				if (!isTypedNumber) {
					verticalD = extractNumber(one);
					horizontalD = extractNumber(two);
					translate(-1, array, verticalD, horizontalD);
				}

			}

			if (strcmp(command, "within") == 0) {
				char type[20];
				std::cin >> type;
				if (strcmp(type, "rectangle") == 0) {
					double x;
					double y;
					double width;
					double height;
					std::cin >> x >> y >> width >> height;
					Point p(x, y);
					this->withinRectangle(p, width, height, array);
				}

				if (strcmp(type, "circle") == 0) {
					double x;
					double y;
					double radius;
					std::cin >> x >> y >> radius;
					Point p(x, y);
					this->withinCircle(p, radius, array);
				}

			}
			std::cout << "Type a command" << std::endl;
		}	
	}

}