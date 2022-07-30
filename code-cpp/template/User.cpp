#include "User.h"
//操作符重载
bool operator != (const User &obj1,const User &obj2){
return !(obj1 == obj2);
}
 
bool operator == (const User &obj1,const User &obj2){
return (obj1.m_id == obj2.m_id && 
obj1.m_name == obj2.m_name);
}
 
 
ostream& operator << (ostream & os, const User & u_ref){
os << u_ref.m_name << " " << u_ref.m_id;
return os;
}
istream& operator >> (istream & is,  User & u_ref){
is >> u_ref.m_name >> u_ref.m_id;
return is;
}
 
 
void User:: set(string name, int id ){
m_name = name;
m_id = id;
}
 
User::User(void)
{
}
 
 
User::~User(void)
{
}

