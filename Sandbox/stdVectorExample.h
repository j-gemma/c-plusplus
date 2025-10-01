#pragma once
#include <iostream> 
#include <vector>
#include "input.h"

void runGet3Numbers();

int get3Numbers();

void runLengthAndIndex();

int lengthAndIndex();


int runPrintElement();

template <typename T>
void printElement(const std::vector<T>& v, int index);