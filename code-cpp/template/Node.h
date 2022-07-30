#pragma once
/*
泛型编程:C++中使用template实现 
 
类模板也是模板，因此必须以关键字 template 开头，后接模板形参表。
类模板Node接受一个名为 T 的模板类型形参。
除了模板形参表外，类模板的定义看起来与任意其他类问相似。类模板可以定义数据成员、函数成员和类型成员，也可以使用访问标号控制对成员的访问，
还可以定义构造函数和析构函数等等。在类和类成员的定义中，可以使用模板形
参作为类型或值的占位符，在使用类时再提供那些类型或值。
例如，Node 模板有一个模板类型形参，可以在任何可以使用类型名字的地方使用该形参。
 
当编译器看到模板定义的时候，它不立即产生代码。只有在看到用到模板时，如调用了函数模板或调用了类模板的对象的时候， 编译器才产生特定类型的模板实例。
一般而言，当调用函数的时候，编译器只需要看到函数的声明。类似地，定义类类型的对象时，类定义必须可用，但成员函数的定义不是必须存在的。因此，应该将类定义和函数声明放在头文件中， 而普通函数和类成员函数的定义放在源文件中。
模板则不同：要进行实例化，编译器必须能够访问定义模板的源代码。当调用函数模板或类模板的成员函数的时候，编译器需要函数定义，需要那些通常放在源
文件中的代码。
标准 C++ 为编译模板代码定义了两种模型。在两种模型中，构造程序的方式很
大程度上是相同的：类定义和函数声明放在头文件中，而函数定义和成员定义放
在源文件中。两种模型的不同在于，编译器怎样使用来自源文件的定义。如本书
所述，所有编译器都支持第一种模型，称为"包含"模型，只有一些编译器支持
第二种模型，"分别编译"模型
*/
 
/*类模板
*/
#include "comm.h"
template <class T>
class Node
{
public:
T m_data;
Node* m_next;
 
void show(){
cout << m_data;
 
}
 
Node(void): m_next(NULL){
}
Node(T e): m_data(e), m_next(NULL){
}
~Node(void){}
};

