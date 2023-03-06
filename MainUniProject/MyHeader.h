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

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist0_10(0, 10); // distribution in range
std::uniform_int_distribution<std::mt19937::result_type> dist1_10(1, 10); // distribution in range

