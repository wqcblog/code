#pragma once
/*
问题描述:用OO方法
# 假设有n个人围坐一圈(循环链表)
现在要求从第1个人开始报数，报到第m个数的人退出。然后从下一个人开始继续报数
并按照同样的规则退出
直至所有人都退出。按照顺序输出各出列人的编号
*/
class Node
{
public:
Node(void);
~Node(void);
//友元
friend class CyLinkList;
private:
int id;
Node* next;//指向下一个结点
};

