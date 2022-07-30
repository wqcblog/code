/*
继承: Has-a聚合(组合):一个类中包含有另一个类的对象
Student 包含 Date 对象 birthday
继承 :Is-a
派生类(子类)  :  基类(父类)
Student.h: 类的声明设计
子类对象创建:        如果不显式指明构造函数,调用 默认的构造函数
step1: 调用父类构造函数 创建 继承的部分
step2: 调用成员对象的构造函数 创建 成员对象
step3: 调用自身构造函数 创建 自身部分
step1父类构造方法和step2成员对象的构造方法 调用 必须在
子类构造方法后用 初始化列表: 的方式实现,
即 放在 : 之后
 
子类继承父类所有的成员
成员变量
成员函数:
除父类 构造函数,析构函数 外
*/
#include "Person.h"
#include "Date.h"
class Student : public Person
{
public :
//constructor, overload
Student(void);
Student(string, double,string , double, int, int);        
//copy constructor:一个对象初始化另一个对象
Student(const Student&);
 
//overwrite
void set(string, double,string,double, int, int);
 
string toString();
 
 
~Student(void);
 
private://属性,数据成员
Date birthday;//成员对象, 出生年月
 
string sno;//学号
double score;//学分
 
};

