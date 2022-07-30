#pragma once
/*操作符重载:
友元函数
成员函数
 
这些函数的定义并不重要，重要的是这些函数所包含的设计原则：
如果类定义了 == 操作符，该操作符的含义是两个对象包含同样的数据。
如果类具有一个操作，能确定该类型的两个对象是否相等，通常将该函数
定义为 operator== 而不是创造命名函数。 用户将习惯于用 == 来比较对象，而且这样做比记住新名字更容易。
如果类定义了 operator==，它也应该定义 operator!=。用户会期待如果可以用某个操作符，则另一个也存在。
相等和不相等操作符一般应该相互联系起来定义， 让一个操作符完成比较对象的实际工作，而另一个操作符只是调用前者。
定义了 operator== 的类更容易与标准库一起使用。有些算法，
如 find，默认使用 == 操作符，如果类定义了 ==，则这些算
法可以无须任何特殊处理而用于该类类型。
 
 
*/
 
#include "comm.h"
//日期
class MyDate
{
public:
//friend 友元
friend         bool isLeapYear( int);
 
friend int getDays(const MyDate&obj1, const MyDate&obj2);
 
friend bool operator >(const MyDate&obj1, const MyDate&obj2);
 
/*操作符 ==
@param const MyDate&,该类对象的常引用
@param const MyDate&,该类对象的常引用
@return bool: true,两个对象相等; false,不相等
*/
friend bool operator == (const MyDate&, const MyDate&);
 
/*操作符 !=
@param const MyDate&,该类对象的常引用
@param const MyDate&,该类对象的常引用
@return bool: true,两个对象相等; false,不相等
*/
friend bool operator != (const MyDate&, const MyDate&);
 
 
/*输出操作符<< read
@param ostream&,输出流对象的引用
@param const MyDate&,该类对象的常引用
@return ostream&
*/
friend ostream& operator <<(ostream&, const MyDate&);
 
 
/*输入操作符>> write
@param istream&,输入流对象的引用
@param MyDate&,该类对象的引用
@return istream&
*/
friend istream& operator >>(istream&, MyDate&);
 
/*操作符>+        
@param const MyDate&,该类对象的常引用
@param int
@return MyDate&,该类对象的引用
*/
friend MyDate operator +(const MyDate&, int);
 
/*操作符>+ : int + 对象,不能用成员函数重载        
@param int
@param const MyDate&,该类对象的常引用
 
@return MyDate&,该类对象的引用
*/
friend MyDate operator +( int,const MyDate&);
 
//成员函数
/*自增 
前缀 prefix operators
为了与内置类型一致，前缀式操作符应返回被增量或减量对象的引用。 
@param void
@return DateCPP&,该类对象的引用(左值) 
*/
MyDate& operator ++();
/* postfix operators
为了与内置操作符一致， 后缀式操作符应返回旧值（即，
尚未自增或自减的值），并且，应作为值返回，而不是返回引用。
@param int,无形参名,也不接受传入数据,其作用在形式上区分前缀 
@return Date对象(旧值)
*/
MyDate operator ++(int);
 
 
 
 
//bool operator == (const MyDate&);
bool equal(const MyDate&);
 
 
 //ostream& operator <<(ostream&);//error,不能用成员函数
MyDate operator +( int);
 
bool check();
 
void set(int ,int ,int );
 
MyDate(void);
~MyDate(void);
 
private://member variable
//静态成员变量
static int date[2][13];//每月天数
 
int m_year; //年月日
int m_month;
int m_day;
};

