#include "MyHeader.h"


std::string studName[100];
std::string studSurname[100];
int marks[100][100];
int finalMark[100];
int amountAdded = 0;

void printWithMedArr(int place);
void printWithAvgArr(int place);
void addStudentArr(int place);
void randFillStudentsArr(int place);

void menuArr()//DONE
{
	int command;
	bool isWork = true;

	while (isWork)
	{
		std::cout << "Array part only" << std::endl;
		std::cout << "1. Print Student List with Median" << std::endl;
		std::cout << "2. Print Student List with Average" << std::endl;
		std::cout << "3. Add Student" << std::endl;
		std::cout << "4. Create random students" << std::endl;
		std::cout << "5. End Work" << std::endl;
		try
		{
			std::cin >> command;
		}
		catch (std::exception e)
		{
			std::cout << "Unidentified command, try again" << std::endl;
		}

		switch (command)
		{
		case 1://print med
			for (int i = 0; i < amountAdded; i++)
				printWithMedArr(i);
			break;
		case 2://print avg
			for (int i = 0; i < amountAdded; i++)
				printWithAvgArr(i);
			break;
		case 3://add stud
			addStudentArr(amountAdded);
			break;
		case 4:
			int amount;
			std::cout << "Generate how many?:";
			try
			{
				std::cin >> amount;
				for (int i = 0; i < amount; i++)
					randFillStudentsArr(amountAdded);
			}
			catch (std::exception e)
			{
				std::cout << "Unidentified amount, try again" << std::endl;
			}
			break;
		case 5:
			isWork = false;
			return;//end work
		default:
			std::cout << "-----------------------------------------------" << std::endl;
		}
	}

}

int main()//DONE
{
	menuArr();
	system("pause");
	return 0;
}

void addStudentArr(int place)//DONE
{
	std::cout << "Enter Student Name: ";
	std::cin >> studName[place];
	std::cout << std::endl << "Enter Student Surname: ";
	std::cin >> studSurname[place];
	std::cout << std::endl << "Enter Student Final Mark: ";
	try
	{
		std::cin >> finalMark[place];
	}
	catch (std::exception e)
	{
		std::cout << "Try again" << std::endl;
	}
	int amount;
	int tempo = 0;
	try
	{
		std::cout << std::endl << "Enter Student Mark Amount: ";
		std::cin >> amount;
		for(int i=0;i<amount;i++)
		{
			try
			{
				std::cout << "Enter Mark:";
				std::cin >> marks[place][i];
			}
			catch (std::exception e)
			{
				std::cout << "Error, try again" << std::endl;
			}
		}
	}
	catch (std::exception e)
	{
		std::cout << "Try again" << std::endl;
	}
	amountAdded++;
}

void printWithAvgArr(int place)//DONE
{
	std::cout << "Student " << std::setw(15) << studName[place] << " " << studSurname[place] << " Marks: ";
	double temp = 0;
	double ammo = 0;
	for (const int& mark : marks[place])
	{
		if (mark > 0 && mark < 11)
		{
			std::cout << "[" << mark << "]";
			ammo++;
			temp += mark;
		}
	}
	std::cout << ", Average: " << std::setprecision(2) << temp / ammo;
	std::cout << ", Final Mark: " << finalMark[place] << std::endl;
}

void printWithMedArr(int place)//DONE
{
	std::cout << "Student " << studName[place] << " " << studSurname[place] << " Marks: ";
	int ammo = 0;
	for (const int& mark : marks[place])
	{
		if(mark>0&&mark<11)
		{
			std::cout << "[" << mark << "]";
			ammo++;
		}
			
	}
	if (ammo % 2 == 0)//even
	{
		std::sort(std::begin(marks[place]), std::end(marks[place]));
		std::cout << ", Median: " << std::setprecision(2) << (marks[place][ammo / 2] + marks[place][ammo / 2 - 1]) / 2;
	}
	else//odd
	{
		std::sort(std::begin(marks[place]), std::end(marks[place]));
		std::cout << ", Median: " << marks[place][ammo / 2];
	}
	std::cout << ", Final Mark: " << finalMark[place] << std::endl;
}

void randFillStudentsArr(int place)//DONE
{
	for (int i = 0; i < dist1_10(rng); i++)
		marks[place][i] = dist0_10(rng);
	studName[place] = "Vardenis" + std::to_string(place);
	studSurname[place] = "Pavardenis" + std::to_string(place);
	finalMark[place] = dist0_10(rng);
	amountAdded++;
}