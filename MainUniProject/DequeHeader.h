#include "MyHeader.h"

struct studentDeque//DONE
{
	std::string studName;
	std::string studSurname;
	std::deque<int> marks;
	int finalMark;
};

studentDeque addStudentDeque();
void printWithMedDeque(studentDeque stud);
void printWithAvgDeque(studentDeque stud);
void printBothDeque(studentDeque stud);
studentDeque randFillStudentsDeque(int studPosition);
void menuDeque(std::deque<studentDeque> studentBody);

void bufferReadDeque(std::string readName, std::deque<studentDeque>& studentBody);
void fillTextDeque(std::string writeName, std::deque<studentDeque> studentBody);

bool studentSorterDeque(studentDeque const& studB, studentDeque const& studE);
