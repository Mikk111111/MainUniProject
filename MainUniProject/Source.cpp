#include "MyHeader.h"

int main()
{
	std::vector<student> studs;
	menu(studs);
	return 0;
}

void menu(std::vector<student> studentBody) //TODO
{
	std::string commandS;
	int command = 0;

	while (true)
	{
		if(!studentBody.empty())
		{
			std::cout << "1. Print Student List and Marks with Median" << std::endl;
			std::cout << "2. Print Student List and Marks with Average" << std::endl;
			std::cout << "3. Print Student List only with Average and Median" << std::endl;
		}
		std::cout << "4. Add Student" << std::endl;
		std::cout << "5. Create random students" << std::endl;
		std::cout << "6. Read from file" << std::endl;
		std::cout << "7. Write to file" << std::endl;
		std::cout << "8. End Work" << std::endl;
		std::cout << "Enter Command:";
		std::cin >> commandS;
		try
		{
			command = std::stoi(commandS);
		}
		catch (...)
		{
			command = 0;
			std::cout << "Unidentified command, try again" << std::endl;
		}
		switch (command)
		{
		case 1: //print med
			for (const student& std : studentBody)
				printWithMed(std);
			break;
		case 2: //print avg
			for (const student& std : studentBody)
				printWithAvg(std);
			break;
		case 3:
			for (const student& std : studentBody)
				printBoth(std);
			break;
		case 4: //add stud
			studentBody.push_back(addStudent());
			break;
		case 5: //generate stud
			{
				std::string amountS;
				int amount;
				std::cout << "Generate how many?:";
				std::cin >> amountS;
				try
				{
					amount = std::stoi(amountS);
				}
				catch (std::exception e)
				{
					amount = 0;
					std::cout << "Unidentified amount, going back" << std::endl;
				}
				for (int i = 0; i <= amount; i++)
					studentBody.push_back(randFillStudents(i + 1));
			}
			break;
		case 6:
			{
				std::string readFileName;
				std::cout << "Enter File Name:";
				std::cin >> readFileName;
				bufferRead(readFileName, studentBody);
			}
			break;
		case 7:
			fillText("test.txt", studentBody);
			std::cout << "Done" << std::endl;
			break;
		case 8:
			return; //end work
		default:
			std::cout << "-----------------------------------------------" << std::endl;
			break;
		}
	}
}

student addStudent() //TODO
{
	student temp;

	std::vector<int> tempArr;
	int tempo1 = 0;
	std::string tempo2;
	int amount;
	std::cout << "Enter Student Name: ";
	std::cin >> temp.studName;
	std::cout << std::endl << "Enter Student Surname: ";
	std::cin >> temp.studSurname;
	while (true)
	{
		std::cout << std::endl << "Enter Student Final Mark: ";
		std::cin >> tempo2;
		try
		{
			tempo1 = std::stoi(tempo2);
			if (tempo1 < 0 || tempo1 > 10)
			{
				std::cout << "Mark out of bounds" << std::endl;
			}
			else
			{
				temp.finalMark = tempo1;
				break;
			}
		}
		catch (std::exception e)
		{
			std::cout << "Try again" << std::endl;
		}
	}
	while (true)
	{
		std::cout << std::endl << "Enter Student Mark Amount: ";
		std::cin >> tempo2;
		try
		{
			amount = std::stoi(tempo2);
			break;
		}
		catch (std::exception e)
		{
			std::cout << "Try again" << std::endl;
		}
	}

	while (amount > 0)
	{
		std::cout << "Enter " << tempArr.size() + 1 << " Mark:";
		std::cin >> tempo2;
		try
		{
			tempo1 = std::stoi(tempo2);
			if (tempo1 < 0 || tempo1 > 10)
			{
				std::cout << "Mark out of bounds" << std::endl;
			}
			else
			{
				tempArr.push_back(tempo1);
				amount--;
			}
		}
		catch (std::exception e)
		{
			std::cout << "Try again" << std::endl;
		}
	}
	temp.marks = tempArr;
	return temp;
}

void printBoth(student stud)
{
	std::cout << "Student| " << std::setw(22) << stud.studName << "|" << std::setw(22) << stud.studSurname <<
		"|";
	double temp = 0;
	for (const int& mark : stud.marks) temp += mark;
	std::cout << ", Average: " << std::setprecision(3) << std::setw(5) << temp / stud.marks.size() << "| ";
	if (stud.marks.size() % 2 == 0) //even
	{
		std::sort(stud.marks.begin(), stud.marks.end());
		std::cout << ", Median: " << std::setprecision(3) << std::setw(5)
		<< (stud.marks[stud.marks.size() / 2] + stud.marks[stud.marks.size() / 2 - 1]) / 2 << "| ";
	}
	else //odd
	{
		std::sort(stud.marks.begin(), stud.marks.end());
		std::cout << ", Median: " << std::setw(5) << stud.marks[stud.marks.size() / 2] << "| ";
	}
	std::cout << std::endl;
}

void printWithAvg(student stud) //DONE
{
	std::cout << "Student " << std::setw(22) << stud.studName << "|" << std::setw(22) << stud.studSurname <<
		"| Marks: ";
	double temp = 0;
	for (const int& mark : stud.marks)
	{
		std::cout << "[" << std::setw(2) << mark << "]";
		temp += mark;
	}
	std::cout << ", Average: " << std::setprecision(3) << std::setw(5) << temp / stud.marks.size();
	std::cout << ", Final Mark: " << stud.finalMark << std::endl;
}

void printWithMed(student stud) //DONE
{
	std::cout << "Student " << std::setw(22) << stud.studName << "|" << std::setw(22) << stud.studSurname <<
		"| Marks: ";
	for (const int& mark : stud.marks)
	{
		std::cout << "[" << std::setw(2) << mark << "]";
	}
	if (stud.marks.size() % 2 == 0) //even
	{
		std::sort(stud.marks.begin(), stud.marks.end());
		std::cout << ", Median: " << std::setprecision(3) << std::setw(5) << (stud.marks[stud.marks.size() / 2] + stud.marks[stud.marks.
			size() / 2 - 1]) / 2;
	}
	else //odd
	{
		std::sort(stud.marks.begin(), stud.marks.end());
		std::cout << ", Median: " << stud.marks[stud.marks.size() / 2];
	}
	std::cout << ", Final Mark: " << stud.finalMark << std::endl;
}

student randFillStudents(int studPosition)
{
	student temp;
	for (int i = 0; i < static_cast<unsigned>(dist1_10(rng)); i++)
		temp.marks.push_back(dist0_10(rng));
	temp.studName = "Vardenis" + std::to_string(studPosition);
	temp.studSurname = "Pavardenis" + std::to_string(studPosition);
	temp.finalMark = dist0_10(rng);
	return temp;
}

void bufferRead(std::string readName, std::vector<student>& studentBody)
{
	std::vector<std::string> splited;
	std::string line;
	std::stringstream my_buffer;
	
	std::ifstream open_f(readName); //Open file
	if (open_f)
	{
		my_buffer << open_f.rdbuf(); //Load to buffer
	}
	else
	{
		std::cout << "Couldn't find the file" << std::endl;
		return;
	}
	open_f.close(); //Close file

	while (my_buffer)
	{
		if (!my_buffer.eof())
		{
			std::getline(my_buffer, line);
			splited.push_back(line);
		}
		else
		{
			break;
		}
	}
	splited.erase(splited.begin());
	for (std::string& fullLine : splited)
	{
		student temp;
		temp.marks.clear();
		int readPlace = 0;
		int numb;
		std::istringstream ss(fullLine);
		std::string word; // for storing each word
		if (!fullLine.empty())
		{
			while (ss >> word)
			{
				readPlace++;
				if (readPlace == 1)temp.studName = word;
				else if (readPlace == 2)temp.studSurname = word;
				else
				{
					try
					{
						temp.marks.push_back(std::stoi(word));
					}
					catch (...)
					{
						std::cout << "Failed to convert marks" << std::endl;
					}
				}
			}
			temp.finalMark = temp.marks.back();
			temp.marks.pop_back();
			studentBody.push_back(temp);
		}
	}
	splited.clear();
}

void fillText(std::string writeName, std::vector<student> studentBody)
{
	std::ofstream out(writeName);
	std::string outText;
	std::sort(studentBody.begin(), studentBody.end(),&studentSorter );
	for (auto temp : studentBody)
	{
		out << std::setw(20) << temp.studName << std::setw(20) << temp.studSurname;
		
		double tempor = 0;
		for (const int& mark : temp.marks) tempor += mark;
		out << ", Average: " << std::setprecision(3) << std::setw(5) << tempor / temp.marks.size() << "| ";
		if (temp.marks.size() % 2 == 0) //even
		{
			std::sort(temp.marks.begin(), temp.marks.end());
			out << ", Median: " << std::setprecision(3) << std::setw(5) << 
				(temp.marks[temp.marks.size() / 2] + temp.marks[temp.marks.size() / 2 - 1]) / 2 << "| ";
		}
		else //odd
		{
			std::sort(temp.marks.begin(), temp.marks.end());
			out << ", Median: " << std::setw(5) << temp.marks[temp.marks.size() / 2] << "| ";
		}
		out << std::endl;
			
	}

	out.close();
}
