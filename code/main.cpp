//Ananya Trivedi LetterGrader project.
//Driver function.


#include "Grades.h"

using namespace std;



int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cout << "Error: Wrong number of arguments";
		exit(EXIT_FAILURE);
	}

	Grades grade(argv[1], argv[2]);//obj created

	grade.readFile();//stores everything into all variables

	grade.writeFile();//uses private datamembers to populate output file

	cout << grade;//uses private members to display output

	grade.print();

}
