#include "VectorHeader.h"

std::random_device devVector;
std::mt19937 rngVector(devVector());
std::uniform_int_distribution<std::mt19937::result_type> dist0_10Vector(0, 10); // distribution in range
std::uniform_int_distribution<std::mt19937::result_type> dist1_10Vector(1, 10); // distribution in range

bool studentSorterVector(studentVector const& studB, studentVector const& studE) {
	if (studB.studName != studE.studName)
		return studB.studName < studE.studName;
	else return false;
}

void menuVector(std::vector<studentVector> studentBody) //TODO
{
	std::string commandS;
	int command = 0;

	while (true)
	{
		std::cout << "Running Work with Vectors" << std::endl;
		if (!studentBody.empty())
		{
			std::cout << "1. Print studentVector List and Marks with Median" << std::endl;
			std::cout << "2. Print studentVector List and Marks with Average" << std::endl;
			std::cout << "3. Print studentVector List only with Average and Median" << std::endl;
			std::cout << "4. Sort Students by Grades to Files" << std::endl;
		}
		std::cout << "5. Add studentVector" << std::endl;
		std::cout << "6. Create random students" << std::endl;
		std::cout << "7. Read from file" << std::endl;
		std::cout << "8. Write to file" << std::endl;
		std::cout << "9. Generate requested files" << std::endl;
		std::cout << "10. End Work" << std::endl;
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
			for (const studentVector& std : studentBody)
				printWithMedVector(std);
			break;
		case 2: //print avg
			for (const studentVector& std : studentBody)
				printWithAvgVector(std);
			break;
		case 3://print both med and avg
			for (const studentVector& std : studentBody)
				printBothVector(std);
			break;
		case 4://create dumb and smart files
		{
			auto start = std::chrono::high_resolution_clock::now();

			std::vector<studentVector> tempBodySmart;
			std::vector<studentVector> tempBodyDumb;
			for (const studentVector& std : studentBody)
			{
				if (std.finalMark >= 5)
					tempBodySmart.push_back(std);
				else
					tempBodyDumb.push_back(std);
			}
			std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
			std::cout << "Segregation sort Time: " << std::fixed << diff.count() << " s" << std::endl;

			start = std::chrono::high_resolution_clock::now();
			fillTextVector("SmartStudents.txt", tempBodySmart);
			fillTextVector("DumbStudents.txt", tempBodyDumb);
			tempBodyDumb.clear();
			tempBodySmart.clear();
			diff = std::chrono::high_resolution_clock::now() - start;
			std::cout << "Text File fill Time: " << diff.count() << " s" << std::endl;
		}
		break;
		case 5: //add stud
			studentBody.push_back(addStudentVector());
			break;
		case 6: //generate stud
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
				studentBody.push_back(randFillStudentsVector(i + 1));
		}
		break;
		case 7://File reading to buffer
		{
			auto start = std::chrono::high_resolution_clock::now();

			std::string readFileName;
			std::cout << "Enter File Name:";
			std::cin >> readFileName;
			bufferReadVector(readFileName, studentBody);

			std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
			std::cout << "Time to load file to buffer: " << diff.count() << " s" << std::endl;
		}
		break;
		case 8://Write to file
		{
			auto start = std::chrono::high_resolution_clock::now();
			fillTextVector("test.txt", studentBody);
			std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
			std::cout << "Time to fill file: " << diff.count() << " s" << std::endl;
		}
		break;
		case 9://create files
		{
			auto start = std::chrono::high_resolution_clock::now();
			auto st = start;
			std::vector<studentVector> tempBody;

			tempBody.reserve(1000);
			for (int i = 0; i < 1000; i++)
				tempBody.push_back(randFillStudentsVector(i));
			fillTextVector("Students1000.txt", tempBody);
			std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
			std::cout << "File1000 Done in: " << diff.count() << " s" << std::endl;
			tempBody.clear();

			start = std::chrono::high_resolution_clock::now();
			tempBody.reserve(10000);
			for (int i = 0; i < 10000; i++)
				tempBody.push_back(randFillStudentsVector(i));
			fillTextVector("Students10000.txt", tempBody);
			diff = std::chrono::high_resolution_clock::now() - start;
			std::cout << "File10000 Done in: " << diff.count() << " s" << std::endl;
			tempBody.clear();

			start = std::chrono::high_resolution_clock::now();
			tempBody.reserve(100000);
			for (int i = 0; i < 100000; i++)
				tempBody.push_back(randFillStudentsVector(i));
			fillTextVector("Students100000.txt", tempBody);
			diff = std::chrono::high_resolution_clock::now() - start;
			std::cout << "File100000 Done in: " << diff.count() << " s" << std::endl;
			tempBody.clear();

			start = std::chrono::high_resolution_clock::now();
			tempBody.reserve(1000000);
			for (int i = 0; i < 1000000; i++)
				tempBody.push_back(randFillStudentsVector(i));
			fillTextVector("Students1000000.txt", tempBody);
			diff = std::chrono::high_resolution_clock::now() - start;
			std::cout << "File1000000 Done in: " << diff.count() << " s" << std::endl;
			tempBody.clear();

			start = std::chrono::high_resolution_clock::now();
			tempBody.reserve(10000000);
			for (int i = 0; i < 10000000; i++)
				tempBody.push_back(randFillStudentsVector(i));
			fillTextVector("Students10000000.txt", tempBody);
			diff = std::chrono::high_resolution_clock::now() - start;
			std::cout << "File10000000 Done in: " << diff.count() << " s" << std::endl;
			tempBody.clear();


			diff = std::chrono::high_resolution_clock::now() - st;
			std::cout << "File creation Done in: " << diff.count() << " s Total" << std::endl;
		}
		break;
		case 10:
			return; //end work
		default:
			std::cout << "-----------------------------------------------" << std::endl;
			break;
		}
	}
}

studentVector addStudentVector() //TODO
{
	studentVector temp;

	std::vector<int> tempArr;
	int tempo1 = 0;
	std::string tempo2;
	int amount;
	std::cout << "Enter studentVector Name: ";
	std::cin >> temp.studName;
	std::cout << std::endl << "Enter studentVector Surname: ";
	std::cin >> temp.studSurname;
	while (true)
	{
		std::cout << std::endl << "Enter studentVector Final Mark: ";
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
		std::cout << std::endl << "Enter studentVector Mark Amount: ";
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

void printBothVector(studentVector stud)
{
	std::cout << "studentVector| " << std::setw(22) << stud.studName << "|" << std::setw(22) << stud.studSurname <<
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

void printWithAvgVector(studentVector stud) //DONE
{
	std::cout << "studentVector " << std::setw(22) << stud.studName << "|" << std::setw(22) << stud.studSurname <<
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

void printWithMedVector(studentVector stud) //DONE
{
	std::cout << "studentVector " << std::setw(22) << stud.studName << "|" << std::setw(22) << stud.studSurname <<
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

studentVector randFillStudentsVector(int studPosition)
{
	studentVector temp;
	for (unsigned int i = 0; i < static_cast<unsigned>(dist1_10Vector(rngVector)); i++)
		temp.marks.push_back(dist0_10Vector(rngVector));
	temp.studName = "Vardenis" + std::to_string(studPosition);
	temp.studSurname = "Pavardenis" + std::to_string(studPosition);
	temp.finalMark = dist0_10Vector(rngVector);
	return temp;
}

void bufferReadVector(std::string readName, std::vector<studentVector>& studentBody)
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
		studentVector temp;
		temp.marks.clear();
		int readPlace = 0;
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

void fillTextVector(std::string writeName, std::vector<studentVector> studentBody)
{
	std::ofstream out(writeName);
	std::stringstream z;
	std::string outText;
	auto start = std::chrono::high_resolution_clock::now();
	std::sort(studentBody.begin(), studentBody.end(), &studentSorterVector);//Important sort
	std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
	std::cout << "Sort Time: " << std::fixed << diff.count() << " s" << std::endl;

	for (auto temp : studentBody)
	{
		z << std::setw(20) << temp.studName << std::setw(20) << temp.studSurname;

		double tempor = 0;
		for (const int& mark : temp.marks) tempor += mark;
		z << ", Average: " << std::setprecision(3) << std::setw(5) << tempor / temp.marks.size() << "| ";
		if (temp.marks.size() % 2 == 0) //even
		{
			std::sort(temp.marks.begin(), temp.marks.end());
			z << ", Median: " << std::setprecision(3) << std::setw(5) <<
				(temp.marks[temp.marks.size() / 2] + temp.marks[temp.marks.size() / 2 - 1]) / 2 << "| ";
		}
		else //odd
		{
			std::sort(temp.marks.begin(), temp.marks.end());
			z << ", Median: " << std::setw(5) << temp.marks[temp.marks.size() / 2] << "| ";
		}
		z << std::endl;
	}
	out << z.str();
	z.clear();
	out.close();
}
