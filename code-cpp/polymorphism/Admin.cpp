#include "Admin.h"
 
void Admin::study(){
cout << "Admin Studying!" <<endl;
}
 
void Admin::work(){
cout << "Admin Working!" <<endl;
}
 
//基类纯虚函数的定义实现
double Admin::income()
{
return 3.4;
}
 
Admin::Admin(void)
{
}
 
 
Admin::~Admin(void)
{
}

