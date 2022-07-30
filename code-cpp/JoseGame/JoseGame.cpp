#include "JoseGame.h"
/*游戏
从start开始
*/
void JoseGame:: playGame()
{
//step0: 初始化,将cur从1左移至start
joseRing.moveLeft(start-1);
 
for (int i=0; i<size-winer; i++)
{
//step1:左移ending-1位
joseRing.moveLeft(ending-1);
//step2: delete Node
int id_del;
cout<< boolalpha <<joseRing.delNode(id_del) <<",";
cout << id_del <<": ";
joseRing.show();
}
 
 
}
 
/*构造函数: 创建对象,初始化
@param nums: 人数
@param w: 保留人数,默认值为1
@param ending: 被删除编号,默认值3
@param s: 开始的编号:默认值为1
*/
JoseGame::JoseGame(int nums, int w, int ending,int s)
: joseRing(nums)
{
this->size = nums;
this->winer = w;
this->ending = ending;
this->start = s;
}
 
//output
void JoseGame::show()
{
cout << this->size<<endl;
joseRing.show();
}
 
JoseGame::~JoseGame(void)
{
}

