#pragma once
#include "comm.h"
class User
{
string m_name;
int  m_id;
public:
//操作符重载
friend ostream& operator << (ostream & os, const User & );
friend istream& operator >> (istream & os,  User & );
friend bool operator != (const User &,const User &);
friend bool operator == (const User &,const User &);
 
void set(string ,int );
User(void);
~User(void);
};

