#include "MyHeader.h"

struct studentVector//DONE
{
	std::string studName;
	std::string studSurname;
	std::vector<int> marks;
	int finalMark;
};

studentVector addStudentVector();
void printWithMedVector(studentVector stud);
void printWithAvgVector(studentVector stud);
void printBothVector(studentVector stud);
studentVector randFillStudentsVector(int studPosition);
void menuVector(std::vector<studentVector> studentBody);

void bufferReadVector(std::string readName, std::vector<studentVector>& studentBody);
void fillTextVector(std::string writeName, std::vector<studentVector> studentBody);

bool studentSorterVector(studentVector const& studB, studentVector const& studE);
