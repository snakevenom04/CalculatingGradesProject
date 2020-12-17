
#include "Grades.h"

using namespace std;

Grades::Grades(string i, string o)
{
	inputfile = i;
	outputfile = o;
}

void Grades::readFile()
{
	string inputline;

	//inputfilename needs to be userbased	
	ifstream ifile(inputfile); // input file

	if (!ifile)//file stream error handling
	{
		cerr << "Error: Input filestream not found.\n";
		exit(EXIT_FAILURE);
	}

	while (getline(ifile, inputline))
	{
		int counter = 0;
		int check = 0;
		int tempmarks = 0;

		for (int i = 0; i < inputline.size(); i++)//go throught each character in the line
		{

			if (inputline[i] == ',' && check == 1)//checks if its the first comma or not
			{
				marks[counter] = tempmarks;
				tempmarks = 0;
				counter++;
			}
			
			if (inputline[i] == ',' && check == 0)//stores the name in the vector
			{
				gradelist.push_back(make_pair(inputline.substr(0, i)+":", 'P'));
				check = 1;
			}

			if (isdigit(inputline[i]))//stores the marks in the array
			{
				tempmarks = tempmarks * 10 + (inputline[i] - '0');
			}

		}
		
		marks[counter] = tempmarks;

		calculate(marks);

		gradelist[total_students].second = getGrade(marks);
		total_students++;

	}

	ifile.close();

}//end of readFile

void Grades::calculate(int* mark)
{
	for (int i = 0; i < 7; i++)
	{
		average[i] = average[i] + mark[i];

		if (mark[i] < min[i])
			min[i] = mark[i];

		if (mark[i] > max[i])
			max[i] = mark[i];

	}

}//end of calculate

char Grades::getGrade(int* mark)
{
	double fscore = mark[0] * 0.1 + mark[1] * 0.1 + mark[2] * 0.1 + mark[3] * 0.1 + mark[4] * 0.2 + mark[5] * 0.15 + mark[6] * 0.25;

	if (fscore >= 90)
		return 'A';
	else if (fscore >= 80)
		return 'B';
	else if (fscore >= 70)
		return 'C';
	else if (fscore >= 60)
		return 'D';
	else
		return 'F';
}//end of getGrade

void Grades::writeFile()
{
	ofstream outfile(outputfile);

	sort(gradelist.begin(), gradelist.end());

	for (int i = 0; i < total_students; i++)//tabular printing
	{
		outfile << setw(30) << left << gradelist[i].first << gradelist[i].second << "\n";
	}


	outfile.close();
}//end of writefile


std::ostream& operator<< (std::ostream& out, const Grades& grade)
{
	out << "Letter grade has been calculated for " << grade.total_students << " students listed in input file " << grade.inputfile
		<< " and written to output file " << grade.outputfile << "\n";

	return out;

}


void Grades::print()
{

	

	cout << "Here is the class averages:\n\n";

	//Tabular formatting
	cout << setw(9) << left << " " << setw(20) << left << "Q1" << setw(20) << left << "Q2" << setw(20) << left << "Q3" << setw(20) << left << "Q4";
	cout << setw(20) << left << "MidI" << setw(20) << left << "MidII" << setw(20) << left << "Final";

	cout << "\nAverage: ";

	for (int i = 0; i < 7; i++)//average
	{
		cout << setw(20) << left << fixed << setprecision(2) <<average[i]/total_students;
	}
	
	cout << "\nMinimum: ";

	for (int i = 0; i < 7; i++)//minimum
	{
		cout << setw(20) << left << min[i];
	}

	cout << "\nMaximum: ";

	for (int i = 0; i < 7; i++)//maximum
	{
		cout << setw(20) << left << max[i];
	}

}//end of print