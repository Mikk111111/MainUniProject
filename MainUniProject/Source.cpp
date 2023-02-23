//#include "MyHeader.h"
//
//student addStudent();
//void printWithMed(student stud);//DONE
//void printWithAvg(student stud);//DONE
//student randFillStudents(int studPosition);
//
//void menu(std::vector<student> studentBody)//TODO
//{
//	int command;
//	bool isWork = true;
//
//	while (isWork)
//	{
//		std::cout << "1. Print Student List with Median" << std::endl;
//		std::cout << "2. Print Student List with Average" << std::endl;
//		std::cout << "3. Add Student" << std::endl;
//		std::cout << "4. Create random students" << std::endl;
//		std::cout << "5. End Work" << std::endl;
//		command = 0;
//		try
//		{
//			std::cin >> command;
//		}
//		catch (std::exception e)
//		{
//			std::cout << "Unidentified command, try again" << std::endl;
//		}
//
//		switch (command)
//		{
//			case 1://print med
//				for (const student& std : studentBody)
//				{
//					printWithMed(std);
//
//				}
//				break;
//			case 2://print avg
//				for (const student& std : studentBody)
//				{
//					printWithAvg(std);
//
//				}
//				break;
//			case 3://add stud
//				studentBody.push_back(addStudent());
//				break;
//			case 4:
//				int amount;
//				std::cout << "Generate how many?:";
//				try
//				{
//					std::cin >> amount;
//				}
//				catch (std::exception e)
//				{
//					std::cout << "Unidentified amount, try again" << std::endl;
//				}
//				for(int i = 1;i<=amount;i++)
//				studentBody.push_back(randFillStudents(i));
//				break;
//			case 5:
//				isWork = false;
//				return;//end work
//			default:
//				std::cout << "-----------------------------------------------" << std::endl;
//			break;
//		}
//	}
//	
//}
//
//int main()
//{
//	std::vector<student> studs;
//	menu(studs);
//	return 0;
//}
//
//student addStudent()//TODO
//{
//	student temp;
//	
//	std::vector<int> tempArr;
//	int tempo = 0;
//	int amount;
//	bool isAdding = true;
//	int place = 0;
//	std::cout << "Enter Student Name: ";
//	std::cin >> temp.studName;
//	std::cout <<std::endl<< "Enter Student Surname: ";
//	std::cin >> temp.studSurname;
//	std::cout << std::endl << "Enter Student Final Mark: ";
//	try
//	{
//		std::cin >> temp.finalMark;
//	}catch (std::exception e)
//	{
//		std::cout << "Try again" << std::endl;
//	}
//	std::cout << std::endl << "Enter Student Mark Amount: ";
//	std::cin >> amount;
//
//	while(isAdding&&amount>0)
//	{
//		try
//		{
//			place++;
//			std::cout << "Enter "<<place<<" Mark:";
//			std::cin >> tempo;
//			tempArr.push_back(tempo);
//			amount--;
//
//		}catch(std::exception e)
//		{
//			std::cout << "Try again" << std::endl;
//		}
//	}
//	temp.marks = tempArr;
//	return temp;
//}
//
//void printWithAvg(student stud)//DONE
//{
//	std::cout << "Student "<<std::setw(15) << stud.studName << " " << stud.studSurname << " Marks: ";
//	double temp=0;
//	for(const int &mark:stud.marks)
//	{
//		std::cout << "[" << mark << "]";
//		temp += mark;
//	}
//	std::cout << ", Average: " <<std::setprecision(2)<< temp / stud.marks.size();
//	std::cout << ", Final Mark: " << stud.finalMark << std::endl;
//}
//
//void printWithMed(student stud)//DONE
//{
//	std::cout << "Student " << stud.studName << " " << stud.studSurname << " Marks: ";
//	for (const int& mark : stud.marks)
//	{
//		std::cout << "[" << mark << "]";
//	}
//	if(stud.marks.size()%2==0)//even
//	{
//		std::sort(stud.marks.begin(),stud.marks.end());
//		std::cout << ", Median: " << std::setprecision(2) << (stud.marks[stud.marks.size()/2]+stud.marks[stud.marks.size()/2-1])/2;
//	}
//	else//odd
//	{
//		std::sort(stud.marks.begin(), stud.marks.end());
//		std::cout << ", Median: " << std::setprecision(2) << stud.marks[stud.marks.size()/2];
//	}
//	std::cout << ", Final Mark: " << stud.finalMark << std::endl;
//}
//
//student randFillStudents(int studPosition)
//{
//	
//	student temp;
//	std::vector<int> tempArr;
//	for(int i = 0; i < dist1_10(rng);i++)
//	{
//		int tempmark = dist0_10(rng);
//		tempArr.push_back(tempmark);
//	}
//
//	temp.studName = "Vardenis" +std::to_string(studPosition);
//	temp.studSurname = "Pavardenis" + std::to_string(studPosition);
//	temp.finalMark = dist0_10(rng);
//	temp.marks = tempArr;
//
//	return temp;
//}