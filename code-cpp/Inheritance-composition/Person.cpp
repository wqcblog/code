#include "Person.h"
 
/* copy construtor
 
@param ref_obj:const Person&, Person对象的常引用
*/
Person::Person(const Person & ref_obj){
this->pname = ref_obj.pname;
this->height = ref_obj.height;// +1;
//ref_obj.height += 1;//error,const 不允许写操作
cout << "Person copy constructor " << endl;
}
 
 
Person::Person(string name, double h){
this->pname = name;
this->height = h;
cout << "Person args constructor " << endl;
}
 
Person::Person(void)
{
this->height = 1.8;
this->pname= "Tom";
cout << "Person default constructor " << endl;
}
 
//output
/*将对象的属性用string返回*/
string Person::toString(){
string str(this->pname);
 
//将double int转成string
string s1 = dToString(this->height);
/*stringstream ss;   
    string s1;
ss<<this->height;
    ss>>s1;*/
str += conc;
str += s1;
return str;
}
 
void Person::set(string name,double h)
{
this->pname = name;
 
this->height = h;
}
 
void Person::show(){
cout <<this->pname<<this->height<< endl;
}
 
//destructor:析构函数,销毁对象
Person::~Person(void)
{
 
cout << this->toString();
cout << " Person destructor" << endl;
//delete this->pname;
}

