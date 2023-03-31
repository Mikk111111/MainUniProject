#include "VectorHeader.h"
#include "ListHeader.h"
#include "DequeHeader.h"

int main()
{
	std::vector<studentVector> studsVector;
	std::list<studentList> studsList;
	std::deque<studentDeque> studsDeque;
	std::string commandS;
	int command;
	while (true)
	{
		std::cout << "1. Work with Vectors" << std::endl;
		std::cout << "2. Work with List" << std::endl;
		std::cout << "3. Work with Deque" << std::endl;
		std::cout << "10. End Work" << std::endl;
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
			case 1:
				menuVector(studsVector);
				break;
			case 2:
				menuList(studsList);
				break;
			case 3:
				menuDeque(studsDeque);
				break;
			case 10:
				return 0;
			default:
				std::cout << "-----------------------------------------------------------------" << std::endl;
				break;

		}
	}
	return 0;
}
