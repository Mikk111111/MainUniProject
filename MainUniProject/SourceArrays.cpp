#include "MyHeader.h"

struct student//DONE
{
	std::string studName;
	std::string studSurname;
	int marksAmount;
	int* marks{};
	int finalMark{};
	student() {};
};
int currentArraySize = 0;
student* students = new student[currentArraySize];
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
		std::cout << "4. Create random student" << std::endl;
		std::cout << "5. End Work" << std::endl;
		std::cin >> command;
		switch (command)
		{
		case 1://print med
			for (int i = 0; i < currentArraySize; i++)
				printWithMedArr(students, i);
			break;
		case 2://print avg
			for (int i = 0; i < currentArraySize; i++)
				printWithAvgArr(students, i);
			break;
		case 3://add stud
		{
			std::cout << "Current Array Size: " << currentArraySize << std::endl;
			student* resizedStudents = new student[currentArraySize + 1];
			for (int i = 0; i < currentArraySize;i++)
			{
				resizedStudents[i] = students[i];
			}
			currentArraySize++;
			std::cout << "New Array Size: " << currentArraySize << std::endl;
			addStudentArr(resizedStudents, currentArraySize-1);
			delete [] students;
			students = resizedStudents;
		}
			break;
		case 4:
		{
			std::cout << "Current Array Size: " << currentArraySize << std::endl;
			student* resizedStudents = new student[currentArraySize + 1];
			for (int i = 0; i < currentArraySize; i++)
			{
				resizedStudents[i] = students[i];
			}
			currentArraySize++;
			std::cout << "New Array Size: " << currentArraySize << std::endl;
			randFillStudentsArr(resizedStudents, currentArraySize - 1);
			delete[] students;
			students = resizedStudents;
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
	std::cout << std::endl << "Enter Student Mark Amount: ";
	std::cin >> students[place].marksAmount;
	students[place].marks = new int[students[place].marksAmount];
	for (int i = 0; i < students[place].marksAmount; i++)
	{
		std::cout << "Enter Mark:";
		std::cin >> students[place].marks[i];
	}
}

void printWithAvgArr(student* students, int place)//DONE
{
	std::cout << "Student " << std::setw(15) << students[place].studName << " " << std::setw(15) << students[place].studSurname << " Marks: ";
	double sum = 0;
	for (int i = 0;i<students[place].marksAmount;i++)
	{
		std::cout << "[" << students[place].marks[i] << "]";
		sum += students[place].marks[i];
	}
	std::cout << ", Average: " << std::setprecision(3) << sum / students[place].marksAmount;
	std::cout << ", Final Mark: " << students[place].finalMark << std::endl;
}

void printWithMedArr(student* students, int place)//DONE
{
	std::cout << "Student " << std::setw(15) << students[place].studName << " " << std::setw(15) << students[place].studSurname << " Marks: ";
	students[place].marks = new int[students[place].marksAmount];
	std::sort(students[place].marks,students[place].marks+students[place].marksAmount);
	for (int i = 0; i < students[place].marksAmount; i++)
		std::cout << "[" << students[place].marks[i] << "]";
	
	if (students[place].marksAmount % 2 == 0)//even
		std::cout << ", Median: " << std::setprecision(3) << (students[place].marks[students[place].marksAmount / 2] + students[place].marks[students[place].marksAmount / 2 - 1]) / 2;
	else//odd
		std::cout << ", Median: " << std::setprecision(3) << students[place].marks[students[place].marksAmount / 2];
	std::cout << ", Final Mark: " << students[place].finalMark << std::endl;5
}

void randFillStudentsArr(student*& students, int place)//DONE
{
	students[place].marksAmount = dist1_10(rng);
	students[place].marks = new int[students[place].marksAmount];
	for (int i = 0; i < students[place].marksAmount; i++)
		students[place].marks[i] = dist0_10(rng);
	students[place].studName = "Vardenis" + std::to_string(place);
	students[place].studSurname = "Pavardenis" + std::to_string(place);
	students[place].finalMark = dist0_10(rng);
}
