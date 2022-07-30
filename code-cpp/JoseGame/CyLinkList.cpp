#include "CyLinkList.h"
 
//判断为空
bool CyLinkList:: isEmpty()
{
return NULL == cur;
}
 
/*删除cur所指向的结点
@param val_ref,int &,int引用,保存删除结点的id
@return true:删除成功,false:删除失败
*/
bool CyLinkList:: delNode(int &val_ref)
{
//空表
if (isEmpty())
{
cout << "List is empty,delete error!" <<endl;
val_ref = -1;
return false;
}
//只有1个结点
if(pre == cur)
{
val_ref = cur->id;
pre = cur = NULL;
return true;
}
 
 //暂存
val_ref = cur->id;        
pre->next = cur->next;        
//回到初始状态        
cur = pre->next;
 
return true;
}
 
 
 
/*循环左移: 循环链表向左平移
@param step: 位移步数
*/
void CyLinkList::moveLeft(int step)
{
for (int i=0; i<step; i++)
{
//pre为cur前驱:更新(平移)前状态
pre = cur; 
cur = cur->next;
}
 
}
 
/*功能:创建包含n个结点的循环链表
@param n: int,链表长度,默认值为3
*/
CyLinkList::CyLinkList(int n)
{
//cout << n << endl;
head = new Node[n];
//head = (Node*)malloc(sizeof(Node)*n);
 
for (int i=0; i<n; i++)
{
head[i].next = &head[(i+1)%n];
head[i].id = i+1;
}
 
cur = head; //cur = &head[0];
//pre初始时为最后一个节点
pre  = &head[n-1];
 
}
 
//output
void CyLinkList::show()
{
//cur初始时指向最后一个
Node * t=cur; 
if(NULL == cur) //if (cur == NULL)
{
cout <<"()" << endl;
return;
}
cout <<"(";
do
{
cout << t->id;
if(t->next != cur)//非最后结点
{
cout << ",";
}                
t=t->next;
 
}while(t!=cur);
cout << ")";
cout << endl;
}
//清空链表
void CyLinkList::clear()
{
if(NULL != head)
{
delete []head;
}
}
CyLinkList::~CyLinkList(void)
{
cout << "destructor called!" <<endl;
clear();
}

