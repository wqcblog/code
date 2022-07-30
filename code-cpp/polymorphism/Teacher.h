#pragma once
#include "WorkerABC.h"
 
/*教师类Teacher 继承 职工类WorkerABC(抽象类)
子类Teacher 继承 抽象基类WorkerABC,
需要重写基类 纯虚函数(income()) 为普通的成员函数才能 实例化
*/
class Teacher :
public WorkerABC
{
public:
void study();
 
//继承虚函数,可以实现,也可以不实现
 void work();
 
 //继承纯虚函数,只有实现后才能实例化
 double income();
 
Teacher(void);
~Teacher(void);
};

