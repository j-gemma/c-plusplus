#pragma once
#include <string>

double getDoubleFromUser(void);

double getDoubleFromUser(std::string message);

int getIntFromUser(std::string message);

int getIntFromUserWithBounds(std::string message, int lbound = 1, int ubound = 100);

char getCharFromUser(std::string message);

char getOperation();

int getAge(void);

int getNameLength(void);

void ignoreLine();

bool hasUnextractedInput();