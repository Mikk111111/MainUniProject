#include "MyHeader.h"

struct studentList//DONE
{
	std::string studName;
	std::string studSurname;
	std::list<int> marks;
	int finalMark;
};

studentList addStudentList();
void printWithMedList(studentList stud);
void printWithAvgList(studentList stud);
void printBothList(studentList stud);
studentList randFillStudentsList(int studPosition);
void menuList(std::list<studentList> studentBody);

void bufferReadList(std::string readName, std::list<studentList>& studentBody);
void fillTextList(std::string writeName, std::list<studentList> studentBody);

bool studentSorterList(studentList const& studB, studentList const& studE);
