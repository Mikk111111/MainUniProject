#pragma once
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream> 
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>

struct student//DONE
{
	std::string studName;
	std::string studSurname;
	std::vector<int> marks;
	int finalMark;
};

student addStudent();
void printWithMed(student stud);
void printWithAvg(student stud);
void printBoth(student stud);
student randFillStudents(int studPosition);
void menu(std::vector<student> studentBody);

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist0_10(0, 10); // distribution in range
std::uniform_int_distribution<std::mt19937::result_type> dist1_10(1, 10); // distribution in range

void bufferRead(std::string readName, std::vector<student> &studentBody);
void fillText(std::string writeName, std::vector<student> studentBody);

bool studentSorter(student const& studB, student const& studE) {
    if (studB.studName != studE.studName)
        return studB.studName < studE.studName;
}