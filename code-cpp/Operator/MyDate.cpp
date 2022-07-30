#include "MyDate.h"
int MyDate::date[2][13]={
{365,31,28,31,30,31,30,31,31,30,31,30,31},
{366,31,29,31,30,31,30,31,31,30,31,30,31}
};
 
int getDays(const MyDate&obj1, const MyDate&obj2){
MyDate obj_1= obj1, obj_2 = obj2 ;
int sign = 1;
if (obj1 > obj2){
obj_1 = obj2;
obj_2 = obj1;
sign = -1;
}
 
int count=0;
for (; obj_1 != obj_2; ++obj_1 ){
count ++;
}
return count*sign;
 
}
 
/*自增 
前缀 prefix operators
为了与内置类型一致，前缀式操作符应返回被增量或减量对象的引用。 改变后的对象的引用
@param void
@return DateCPP&,该类对象的引用(左值) 
*/
MyDate& MyDate::operator ++(){
//cout << "prefix"<<endl;
this->m_day ++;
 
int r = isLeapYear(this->m_year);
int c = this->m_month;
 
if (this->m_day > date[r][c]){
this->m_day = 1;
this->m_month++;
 
if(this->m_month >12){
this->m_month = 1;
this->m_year ++;
}
 
}
 
 
 
return *this;
}
/* postfix operators
为了与内置操作符一致， 后缀式操作符应返回旧值（即，
尚未自增或自减的值），并且，应作为值返回，而不是返回引用。
@param int,无形参名,也不接受传入数据,其作用在形式上区分前缀 
@return Date对象(旧值)
*/
MyDate MyDate::operator ++(int){
//cout << "Postfix" <<endl;
MyDate tmp = *this;
 
this->m_day ++;
 
int r = isLeapYear(this->m_year);
int c = this->m_month;
 
if (this->m_day > date[r][c]){
this->m_day = 1;
this->m_month++;
 
if(this->m_month >12){
this->m_month = 1;
this->m_year ++;
}
 
}
 
 
 
return tmp;
}
 
 
 
//友元函数
bool isLeapYear( int y){
return (!(y%4) && (y%100) || !(y%400) );
}
 
 
bool operator >(const MyDate& obj1, const MyDate& obj2){
if (obj1 == obj2 ){
return false;
}
 
if (obj1.m_year > obj2.m_year){
return true;
}
 
if(obj1.m_year == obj2.m_year)
{
if (obj1.m_month > obj2.m_month){
return true;
}
 
if (obj1.m_month == obj2.m_month){
if (obj1.m_day > obj2.m_day){
return true;
}
 
return false;
}
 
}
 
return false;
 
}
 
 
/*操作符 ==
两对象相等
@param const MyDate&,该类对象的常引用
@param const MyDate&,该类对象的常引用
@return bool: true,两个对象相等; false,不相等
*/
bool operator ==(const MyDate& obj1_r, const MyDate& obj2_r)
{
return (obj1_r.m_year == obj2_r.m_year &&                obj1_r.m_month == obj2_r. m_month &&                obj1_r.m_day == obj2_r.m_day) ;
}
 
/*操作符 !=
两对象不相等
@param const MyDate&,该类对象的常引用
@param const MyDate&,该类对象的常引用
@return bool: true,两个对象不相等; false,相等
*/
bool operator !=(const MyDate& obj1_r, const MyDate& obj2_r)
{
return  ! ( obj1_r == obj2_r);
}
 
 
//bool MyDate ::operator == (const MyDate& obj2_r)
//{
//                return (this->m_year == obj2_r.m_year &&                this->m_month == obj2_r. m_month &&                this->m_day == obj2_r.m_day) ;
//}
 
 
bool MyDate ::equal(const MyDate& obj2_r){
return (this->m_year == obj2_r.m_year &&                this->m_month == obj2_r. m_month  &&                this->m_day == obj2_r.m_day) ;
}
/*操作符+: 对象 + int
@param const MyDate&,该类对象的引用
@param int
@return MyDate,该类对象(加之后的结果)
*/
MyDate operator +(const MyDate& obj_ref, int d){
cout << "friend"<<endl;
MyDate tmp = obj_ref;
tmp.m_day += d;
return tmp;
 
}
/*操作符>+ : int + 对象,不能用成员函数重载        
@param int
@param const MyDate&,该类对象的常引用
 
@return MyDate&,该类对象的引用
*/
 MyDate operator +( int d, const MyDate& obj_ref){
cout << "friend 2"<<endl;
MyDate tmp = obj_ref;
tmp.m_day += d;
return tmp;
 
}
 
 
/*输出操作符<<, 读read
@param ostream&,输出流对象的引用
@param const MyDate&,该类对象的常引用
@return ostream&
*/
ostream& operator <<(ostream& os, const MyDate& obj_ref){
//cout <<"friend"<<endl;
os << obj_ref.m_year <<"-";
os << obj_ref.m_month <<"-";
os <<obj_ref.m_day;
return os;
}
 
 
 
/*输入操作符>>  ,写write
@param istream&,输入流对象的引用
@param MyDate&,该类对象的常引用
@return istream&
*/
istream& operator >>(istream& is,  MyDate& obj_ref){
is >> obj_ref.m_year >> obj_ref.m_month;
is >> obj_ref.m_day;
return is;
}
 
//操作符+ : 成员函数实现重载
MyDate MyDate::operator+(int d)
{
cout << "member" << endl;
MyDate tmp = *this;
tmp.m_day += d;
return tmp;
}
 
bool MyDate::check()
{
return true;
}
 
MyDate::MyDate(void)
:m_year(2020), m_month(1), m_day(31)
{
 
}
 
void MyDate::set(int y, int m, int d){
m_year = y; m_month = m;
m_day = d;
}
 
MyDate::~MyDate(void)
{
}

