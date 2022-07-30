#pragma once
#include "Node.h"
/*单链表--类模板
*/
template <typename T>
class LinkList
{
Node<T>* head; //头结点
Node<T>* tail; //尾结点
int m_length;
public:
/*==查找:在表中查找元素e的前驱
@param pre: Node<T>* & ,结点指针的引用,元素e的前驱
@param cur: Node<T>* & ,结点指针的引用,当前结点指针,指向元素e 
@param e:所查找的元素 
*/
bool findPreCurElem(Node<T>* & pre, Node<T>* & cur, T e); 
 
 
//===删除: 删除元素e
bool delElem(T e);
 
/*===尾删法:删除表的最后1个结点,并将该结点的值保存至e
@param e: T&, 保存删除结点的值
@return bool: true,删除成功;false,删除失失败
*/
bool delBack(T&);
 
 
//删除:首结点
bool delFirst(T &);
 
//创建链表: 从数组中读入数据创建链表
bool createListArr(T [], int );
 
//插入:头插法,新元素总是为链表的第1个结点
bool insertFront(T e);
 
//插入:尾插法,新元素总是为链表的最后1个结点
bool insertBack(T e);
 
//判断为空
bool isEmpty();
 
void show();
LinkList(void);
~LinkList(void){}
};
 
/*==查找:在表中查找元素e的 当前指针cur 及 前驱pre
@param pre: Node<T>* & ,结点指针的引用,元素e的前驱
@param cur: Node<T>* & ,结点指针的引用,当前结点指针,指向元素e 
@param e:所查找的元素 
@return bool: true,查找成功;false,查找失败
*/
template <typename T>
bool  LinkList<T>::findPreCurElem(Node<T>* & pre, Node<T>* & cur, T e){
 
//遍历
for ( pre=head, cur=head->m_next; cur && cur->m_data != e;)
{
//PS:两个指针同步后移,维持相对关系
pre = cur; 
cur = cur->m_next;
}//loop ending, cur ==NULL 或 cur->m_data == e
 
//表中不存在元素e
if (cur == NULL)
{
cout <<"Not Exist!" ;
return false;
}
 
return true; // cur->m_data == e
 
}
 
 
 
/*===删除: 删除元素e
@param e: T, 删除结点的数据
@return bool: true,删除成功;false,删除失败
*/
template <typename T>
bool  LinkList<T>::delElem(T e){
bool b;
 
Node<T> * pre = head, *cur = NULL;
//step1: 查找 指向元素e的指针cur 及 cur的前驱pre
b = findPreCurElem(pre, cur, e);
 
//step2: 删除
if (!b){
return false;
}
 
pre->m_next = cur->m_next;
if (tail == cur){ //元素e是最后1个结点
tail = pre; //更新tail
}
delete cur;
m_length --;
 
return true;
 
}
 
/*===尾删法:删除表的最后1个结点,并将该结点的值保存至e
@param e: T&, 保存删除结点的值
@return bool: true,删除成功;false,删除失败
*/
template <typename T>
bool  LinkList<T>:: delBack(T& e){ 
//step0:合法性验证
if( isEmpty() ){ //空表
return false;
}
 
//step1: 查找tail的前驱
Node<T> *pre;
for (pre = head; pre->m_next != tail; pre = pre->m_next)
{
}//loop ending, pre->m_next == tail
//pre 为 tail的前驱
 
//step2: 删除
//pre->m_next = tail->m_next;
pre->m_next = NULL;
e =  tail->m_data; //暂存
delete tail;
//更新
tail = pre;
m_length --;
 
return true;
 
 
}
 
 
/*删除:首结点
@param tmp:T&,T类型的引用, 暂存被删除结点的数据
*/
template <typename T>
bool  LinkList<T>:: delFirst(T &tmp){
//step0:合法性验证
if(isEmpty()){ //空表
return false; 
}
 
//step1: 暂存首结点
Node<T> * p = head->m_next;
 
//PS:处理特殊情形
if(p == tail){//最后只剩下1个结点
tail = head; //回到初始状态
}
//step2: 删除首结点
head->m_next = p->m_next;
tmp = p->m_data;//暂存数据
delete p;
 
//step3: 更新成员        
m_length--;
 
return true;
}
 
//判断为空:表初始状态
template <typename T>
bool  LinkList<T>:: isEmpty(){
return tail == head;
}
 
//插入(w):头插法,新元素总是为链表的第1个结点
template <typename T>
bool LinkList<T>:: insertFront(T e){
//step1: 封装结点
Node<T> * pNew = new Node<T>(e);
 
//step2: 插入
pNew->m_next = head->m_next;//原表的首结点作为新结点的后继
 
head->m_next = pNew;
 
//首次插入
if( isEmpty() ){
tail = pNew;        
}
 
m_length ++;
 
return true;
}
 
//插入:尾插法,新元素总是为链表的最后1个结点
template <typename T>
bool LinkList<T>:: insertBack(T e){
//step1: 封装结点
Node<T> * pNew = new Node<T>(e);
 
//step2: 插入
tail->m_next = pNew;//原表的尾结点后继即为新结点
tail =pNew; //新结点为新的尾结点
 
m_length ++;
 
return true;
}
 
 
 
//创建链表(w): 从数组中读入数据创建链表
template <typename T>
bool LinkList<T>::createListArr(T arr[], int length){
 
//遍历数组
for (int i=0; i<length; i++){
//数组元素加入链表中
//insertFront(arr[i]);
insertBack(arr[i]);
}
 
return true;
 
}
 
 
template <typename T>
LinkList<T>::LinkList(void){
head = new Node<T>;
tail = head;//初始状态
m_length = 0;
}
 
template <typename T>
void LinkList<T>::show(){
cout << m_length <<":";
if (isEmpty()){
cout << "[]" <<endl;
return;
}
Node<T> * p ;
cout <<"[";
for (p=head->m_next; p ; p = p->m_next){
p->show();
if(p != tail){//不是最后一个节点
cout <<",";
}                
 
}
cout << "]";
 
cout << endl;
}

