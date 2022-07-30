#pragma once
#include "Comm.h"
class Date
{
public:
Date(void);
Date(int, int);
Date(const Date&); //copy
 
string toString();
void set(int ,int );
 
~Date(void);
private:
int year, month, day; //年月日
};

