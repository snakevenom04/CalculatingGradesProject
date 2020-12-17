#include <vector>
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm> 

class Grades
{
private:

	std::string inputfile;
	std::string outputfile;
	std::vector <std::pair <std::string, char>> gradelist;
	int marks[7] = {0,0,0,0,0,0,0};
	double average[7] = {0,0,0,0,0,0,0};
	int min[7] = {100, 100, 100, 100, 100, 100, 100};
	int total_students = 0;
	int max[7] = {0, 0, 0, 0, 0, 0, 0};



public:

	Grades(std::string i, std::string o);

	void readFile();

	void calculate(int* mark);

	char getGrade(int* mark);

	void writeFile();

	void print();

	friend std::ostream& operator<< (std::ostream& out, const Grades& );

};
