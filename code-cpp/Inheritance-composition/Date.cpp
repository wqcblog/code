#include "Date.h"
 
/*copy constructor:一个对象初始化另一个对象
@param ref_obj,const Date& 常Date对象的引用
*/
Date::Date(const Date& ref_obj)
{
this->year =ref_obj.year;
this->month = ref_obj.month;
cout << "Date copy constructor " << endl;
}
Date::Date(int y, int m)
: year(y), month(m)
{
/*this->year = y;
this->month = m;*/
cout << "Date args constructor " << endl;
}
Date::Date(void)
{
cout << "Date default constructor " << endl;
}
 
 
//对象转换为string
string Date::toString()
{
string str = dToString(year) + conc + dToString(month);
return str;
}
void Date::set(int y, int m)
{
this->year = y ; this->month= m;
}
 
 
Date::~Date(void)
{
cout << "Date destructor " << endl;
}

