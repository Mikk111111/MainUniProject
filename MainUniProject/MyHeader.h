#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <cstdlib>

struct student//DONE
{
	std::string studName;
	std::string studSurname;
	int* marks;
	int finalMark;
};

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist0_10(0, 10); // distribution in range
std::uniform_int_distribution<std::mt19937::result_type> dist1_10(1, 10); // distribution in range

void menuArr(student* &students, int& studentAmount);//DONE
void printWithAvgArr(student* &students, int place);//DONE
void printWithMedArr(student* &students, int place);//DONE
void addStudentArr(student* &students, int place);//DONE
void randFillStudentsArr(student* &students, int place);//DONE
