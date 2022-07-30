/*加上条件编译 ,使得该文件只包含一次,防止多次包含
#pragma once 
*/
#ifndef COMMON_H_H_2020_2099
#define  COMMON_H_H_2020_2099
 
#include <iostream>
#include <sstream>
#include <string.h>
#include <string> //不同于<string.h> 
#include <string.h>
using namespace std;
 
string conc = "-"; // concatenation
 
string dToString(double d){
    
string sa ;
stringstream ss;
ss<< d;
    ss>>sa;
return sa;
}
 
#endif

