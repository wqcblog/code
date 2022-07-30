#pragma once
#include "Node.h"
class CyLinkList
{
public:
//判断空
bool isEmpty();
 
//删除1个结点
bool delNode(int &);
 
//循环左移: 循环链表向左平移
void moveLeft(int );
 
//构造函数:带缺省值的参数
CyLinkList(int =3); //size
 
//output
void show();
 
~CyLinkList(void);
 
private://成员对象指针
void clear();
Node* head;//首结点
Node* cur;//代表当前结点
Node* pre;//代表cur的前驱
};

