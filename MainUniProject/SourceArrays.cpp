#include "MyHeader.h"

struct student//DONE
{
	std::string studName;
	std::string studSurname;
	int* marks{};
	int finalMark{};
	student() {};
};

student* students = new student[0];
void menuArr(student*& students, int& studentAmount);//DONE
void printWithAvgArr(student* students, int place);//DONE
void printWithMedArr(student* students, int place);//DONE
void addStudentArr(student* students, int place);//DONE
void randFillStudentsArr(student*& students, int place);//DONE

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
		std::cin >> command;
		switch (command)
		{
		case 1://print med
			for (int i = 0; i < sizeof(students); i++)
				printWithMedArr(students, i);
			break;
		case 2://print avg
			for (int i = 0; i < sizeof(students); i++)
				printWithAvgArr(students, i);
			break;
		case 3://add stud
		{
			int arrayLenght = sizeof(students) / sizeof(students[0]);
			std::cout << "Current Array Size: " << arrayLenght << std::endl;
			student* resizedStudents = new student[arrayLenght + 2];
			for (int i : arrayLenght)
			{
				resizedStudents[i] = students[i];
			}
				arrayLenght = sizeof(resizedStudents) / sizeof(resizedStudents[0]);
			std::cout << "New Array Size: " << arrayLenght << std::endl;
			addStudentArr(resizedStudents, arrayLenght-1);
			delete [] students;
			students = resizedStudents;
		}
			break;
		case 4:

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
	return 0;
}

void addStudentArr(student* students, int place)//DONE
{
	std::cout << "Enter Student Name: ";
	std::cin >> students[place].studName;
	std::cout << std::endl << "Enter Student Surname: ";
	std::cin >> students[place].studSurname;
	std::cout << std::endl << "Enter Student Final Mark: ";
	std::cin >> students[place].finalMark;
	int marksAmount;
	std::cout << std::endl << "Enter Student Mark Amount: ";
	std::cin >> marksAmount;
	students[place].marks = new int[marksAmount];
	for (int i = 0; i < marksAmount; i++)
	{
		std::cout << "Enter Mark:";
		std::cin >> students[place].marks[i];
	}
}

void printWithAvgArr(student* students, int place)//DONE
{
	std::cout << "Student " << std::setw(15) << students[place].studName << " " << std::setw(15) << students[place].studSurname << " Marks: ";
	double sum = 0;
	for (int i = 0;i<sizeof(students[place].marks)/sizeof(students[place].marks[0]);i++)
	{
		std::cout << "[" << students[place].marks[i] << "]";
		sum += students[place].marks[i];
	}
	std::cout << ", Average: " << std::setprecision(3) << sum / (sizeof(students[place].marks)/sizeof(students[place].marks[0]));
	std::cout << ", Final Mark: " << students[place].finalMark << std::endl;
}

void printWithMedArr(student* students, int place)//DONE
{
	std::cout << "Student " << std::setw(15) << students[place].studName << " " << std::setw(15) << students[place].studSurname << " Marks: ";
	for (int i = 0; i < sizeof(students[place].marks); i++)
		std::cout << "[" << students[place].marks[i] << "]";
	std::sort(std::begin(students[place].studName), std::end(students[place].studName));
	if (sizeof(students[place].marks) % 2 == 0)//even
		std::cout << ", Median: " << std::setprecision(3) << (students[place].marks[sizeof(students[place].marks) / 2] + students[place].marks[sizeof(students[place].marks) / 2 - 1]) / 2;
	else//odd
		std::cout << ", Median: " << std::setprecision(3) << students[place].marks[sizeof(students[place].marks) / 2];
	std::cout << ", Final Mark: " << students[place].finalMark << std::endl;
}

void randFillStudentsArr(student*& students, int place)//DONE
{
	for (int i = 0; i < dist1_10(rng); i++)
		students[place].marks[i] = dist0_10(rng);
	students[place].studName = "Vardenis" + std::to_string(place);
	students[place].studSurname = "Pavardenis" + std::to_string(place);
	students[place].finalMark = dist0_10(rng);
}
