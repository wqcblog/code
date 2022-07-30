#include "Student.h"
/*copy constructor:一个对象初始化另一个对象
@param ref_obj,const Student& 常Student对象的引用
*/
Student::Student(const Student& ref_obj)
//初始化列表
:Person( (Person)ref_obj ), //实现的是继承部分copy
birthday(ref_obj.birthday)//实现的是成员对象的copy
{
//自身部分copy
this->sno = ref_obj.sno;
this->score =ref_obj.score;
cout << "Student copy constructor " << endl;
}
 
//调用默认构造函数
Student::Student(void)
{
this->sno="20211234"; 
this->score = 21;
cout << "Student default constructor " << endl;
}
 
Student::Student(string name, double h,string sno,double score, int y, int m)
//初始化列表
:Person(name,h),//指明调用父类构造函数
birthday(y,m) //指明成员对象的构造函数
{
//Person(name,h);
//Date birthday(y,m);
this->sno = sno;
this->score = score;
cout << "Student args constructor " << endl;
}
 
//update
//对象转成string
string Student::toString()
{
string str = Person::toString() + conc;
str += this->sno;
str += conc;
string str1 = dToString(this->score);
str += str1;
str += conc;
str += birthday.toString();
 
return str;
}
 
void Student::set(string name, double h,string sno,double score, int y, int m)
 
{
Person::set(name, h);//继承部分的写入
this->birthday.set(y,m); //成员对象的写入
this->sno = sno;
this->score = score;
}
 
Student::~Student(void){
cout << "Student destructor " << endl;
}

