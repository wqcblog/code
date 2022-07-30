#ifndef PERSON_HH_2021_CTGU
#define PERSON_HH_2021_CTGU
/*.h 类的设计
*/
//#pragma once
#include "Comm.h"
 
class Person
{
public: //成员函数
//constructor
Person(void);
Person(string, double);
Person(const Person&);
 
//output
string toString();
 
//update
void set(string,double);
 
void think(){}
void show();
 
//destructor
~Person(void);
private://成员变量
string pname;//姓名
double height;//身高
};
 
 
#endif

