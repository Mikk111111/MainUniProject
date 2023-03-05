#include "MyHeader.h"

student* students = new student[0];

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
				printWithMedArr(students,i);
			break;
		case 2://print avg
			for (int i = 0; i < sizeof(students); i++)
				printWithAvgArr(students,i);
			break;
		case 3://add stud
			resizedStudents = new students[sizeOf(students)+1];
			for(int i=0;i<sizeOf(students);i++)
			{
				resizedStudets[i]=students[i];
			}
			students = new student[sizeof(students)];
			addStudentArr(students,sizeOf(students));
			break;
		case 4:
			int studentsToAdd;
			int temp;
			std::cout << "Generate how many?:";
			std::cin >> studentsToAdd;
			for (sizeof(students); sizeof(students) < temp; sizeof(students)++)
			{
				delete [] students;
				students = new student[sizeof(students)];
				randFillStudentsArr(students,sizeof(students));
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

void addStudentArr(student* &students, int place)//DONE
{
	std::cout << "Enter Student Name: ";
	std::cin >> students[place].studName;
	std::cout << std::endl << "Enter Student Surname: ";
	std::cin >> students[place].studSurname;
	std::cout << std::endl << "Enter Student Final Mark: ";
	std::cin >> students[place].finalMark;
	int amount;
	std::cout << std::endl << "Enter Student Mark Amount: ";
	std::cin >> amount;
	for (int i = 0; i < amount; i++)
	{
		std::cout << "Enter Mark:";
		std::cin >> students[place].marks[i];
	}
}

void printWithAvgArr(student* &students,int place)//DONE
{
	std::cout << "Student " << std::setw(15) << students[place].studName << " " << std::setw(15) << students[place].studSurname << " Marks: ";
	double sum = 0;
	for (const int& mark : students[place].marks)
	{
		std::cout << "[" << mark << "]";
		sum += mark;
	}
	std::cout << ", Average: " << std::setprecision(3) << sum / students[place].marks.size();
	std::cout << ", Final Mark: " << students[place].finalMark << std::endl;
}

void printWithMedArr(student* &students, int place)//DONE
{
	std::cout << "Student " << std::setw(15) << students[place].studName << " " << std::setw(15) << students[place].studSurname << " Marks: ";
	for (const int& mark : students[place].marks)
		std::cout << "[" << mark << "]";
	std::sort(std::begin(students[place].marks), std::end(students[place].marks));
	if (students[place].marks.size() % 2 == 0)//even
		std::cout << ", Median: " << std::setprecision(3) << (students[place].marks[students[place] .marks.size()/ 2] + students[place].marks[students[place].marks.size() / 2 - 1]) / 2;
	else//odd
		std::cout << ", Median: " << std::setprecision(3) << students[place].marks[students[place].marks.size() / 2];
	std::cout << ", Final Mark: " << students[place].finalMark << std::endl;
}

void randFillStudentsArr(student* &students,int place)//DONE
{
	for (int i = 0; i < dist1_10(rng); i++)
		students[place].marks[i] = dist0_10(rng);
	students[place].studName = "Vardenis" + std::to_string(place);
	students[place].studSurname = "Pavardenis" + std::to_string(place);
	students[place].finalMark = dist0_10(rng);
}
