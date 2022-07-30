//test
#include "CyLinkList.h"
#include "JoseGame.h"
int main()
{
int n  = 41;
 
//随机种子
srand(time(NULL));
int s = rand()%41+1; //[0,40]
int ending =rand()%41+1;
int winer = rand()%41+1;
 
cout << s << "," << ending<<","<<winer <<endl;
//cin >> n;
JoseGame jose(n,winer,ending, s);
jose.show();
jose.playGame();
 
//CyLinkList list1;
/*CyLinkList list(3);
list.show();
int val;
for (int i=0;i<4; i++)
{        
cout<< boolalpha <<list.delNode(val) <<",";
cout << val <<endl;
}
 
list.show();
 
list.moveLeft(3);
list.show();
list.delNode();
list.show();*/
return 0;
}

