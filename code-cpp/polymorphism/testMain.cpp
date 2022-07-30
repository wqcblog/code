#include "WorkerABC.h"
#include "Teacher.h"
#include "Admin.h"
/**=== 动态多态
基类对象的指针或基类对象的引用
实现多态
根据传入的子类对象而决定调用 子类特定的虚函数
如果虚函数在子类有实现,调用子类实现的虚函数
否则, 调用的是父类的虚函数
 
1. 调用的函数在基类中必须为虚函数
2. 通过 基类对象的指针或基类对象的引用来调用
 
*/
/*基类对象的指针实现多态
参数绑定:  basePt = &teacher, &admin
@param  basePt:类型为WorkerABC *,基类对象的指针
*/
void testPointer(WorkerABC * basePt)
{
basePt->work();
cout << basePt->income() <<endl;
basePt->study(); //没有多态,使用的是继承机制
 
}
 
 
/*基类对象的引用 实现 多态
参数绑定:  baseRef = teacher, admin
@param  baseRef:类型为WorkerABC &,基类对象的引用
*/
void testReference(WorkerABC &  baseRef)
{
baseRef.work();
cout << baseRef.income() <<endl;
baseRef.study(); //没有多态,使用的是继承机制
 
}
/*
Teacher Working!
1.2
WorkerABC studying!
Admin Working!
3.4
WorkerABC studying!
Teacher Working!
1.2
WorkerABC studying!
Admin Working!
3.4
WorkerABC studying!
请按任意键继续. . .
*/
 
int main()
{
//WorkerABC worker; //error,抽象类不能实例化
Teacher teacher;
Admin admin;
 
//形参为 基类对象的指针, 实参为 子类对象的地址
testPointer( &teacher);
testPointer( &admin);
 
 
//形参为 基类对象的引用, 实参为 子类对象
testReference(teacher);
testReference(admin);
 
return 0;
}

