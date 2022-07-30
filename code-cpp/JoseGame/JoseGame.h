#pragma once
/*
据说著名犹太历史学家 Josephus有过以下的故事：在罗马人占领乔塔帕特后，39 个犹太人与Josephus及他的朋友躲到一个洞中，39个犹太人决定宁愿死也不要被人抓到，于是决定了一个自杀方式，41个人排成一个圆圈，由第1个人开始报数，每报数到第3人该人就必须自杀，然后再由下一个重新报数，直到所有人都自杀身亡为止。
然而Josephus 和他的朋友并不想遵从，Josephus要他的朋友先假装遵从，他将朋友与自己安排在第16个与第31个位置，于是逃过了这场死亡游戏。
问题描述:用OO方法
# 假设有n个人围坐一圈(循环链表)
现在要求从第1个人开始报数，报到第m个数的人退出。然后从下一个人开始继续报数
并按照同样的规则退出
直至所有人都退出。按照顺序输出各出列人的编号
 
*/
#include "CyLinkList.h"
class JoseGame
{
public:
//参数缺省只能是 右缺省
JoseGame(int,int =1, int =3,int=1);
 
void playGame();
 
//output
void show();
 
~JoseGame(void);
private:
int size; //人数
int winer; //保留人数
int ending; //结束点id 
int start; //开始位置
CyLinkList joseRing; //成员对象 
 
};

