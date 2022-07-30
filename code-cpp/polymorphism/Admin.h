#pragma once
#include "WorkerABC.h"
 
/*
行政人员类Admin 继承 职工类WorkerABC
子类Admin 继承 抽象基类WorkerABC,
需要重写基类 纯虚函数(income()) 为普通的成员函数才能实例化
*/
class Admin :
public WorkerABC
{
public:
void study();
 
//继承虚函数,可以实现,也可以不实现
 void work();
 
 //继承纯虚函数,只有实现后才能实例化
 double income();
 
Admin(void);
~Admin(void);
};

