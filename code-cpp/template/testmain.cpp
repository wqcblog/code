#include "Node.h"
#include "LinkList.h"
#include "User.h"
//模板实例化
 
/*
TestCase:
 
0:[]
3:[Tom0 11,Tom1 22,Tom2 33]
Not Exist!false:Tom0 1,3:[Tom0 11,Tom1 22,Tom2 33]
true:Tom0 11,2:[Tom1 22,Tom2 33]
true:Tom1 22,1:[Tom2 33]
true:Tom2 33,0:[]
*/
 
void testDelObj(){
int iArray[3] = {11,22,33};
string sArray[3] = {"Tom0", "Tom1", "Tom2"};
 
User uArray[3];
 
for(int i=0; i<3; i++){
uArray[i].set(sArray[i], iArray[i] );
}
 
LinkList<User> uList;
uList.show();
 
 
uList.createListArr(uArray, 3);
uList.show();
User temp;
temp.set("Tom0", 1);
cout<<boolalpha << uList.delElem(temp) ; 
cout << ":"<< temp <<",";
 
uList.show();
 
for(int i=0; i<3; i++){
 
cout<<boolalpha << uList.delElem(uArray[i]) ; 
cout << ":"<< uArray[i] <<",";
 
uList.show();
}
 
 
}
 
 
 
/*
TestCase:
0:[]
3:[11,22,33]
Not Exist!false:-404,3:[11,22,33]
true:11,2:[22,33]
true:22,1:[33]
true:33,0:[]
0:[]
3:[Tom0,Tom1,Tom2]
Not Exist!false:-404,3:[Tom0,Tom1,Tom2]
true:Tom0,2:[Tom1,Tom2]
true:Tom1,1:[Tom2]
true:Tom2,0:[]
*/
void testDelElem(){
 
LinkList<int> iList;
iList.show();
 
int iArray[3] = {11,22,33};
iList.createListArr(iArray, 3);
iList.show();
int temp=-404;
cout<<boolalpha << iList.delElem(temp) ; 
cout << ":"<< temp <<",";
 
iList.show();
 
for(int i=0; i<3; i++){
 
cout<<boolalpha << iList.delElem(iArray[i]) ; 
cout << ":"<< iArray[i] <<",";
 
iList.show();
}
 
 
 
LinkList<string> sList;
sList.show();
 
string sArray[3] = {"Tom0", "Tom1", "Tom2"};
sList.createListArr(sArray, 3);
 
sList.show();
 
string tmp="-404";
cout<<boolalpha << sList.delElem(tmp) ; 
cout << ":"<< tmp <<",";
sList.show();
 
for(int i=0; i<3; i++){
 
cout<<boolalpha << sList.delElem(sArray[i]) ; 
cout << ":"<< sArray[i] <<",";
 
sList.show();
}
}
 
 
 
/*
TestCase:
0:[]
3:[11,22,33]
true:33,2:[11,22]
true:22,1:[11]
true:11,0:[]
false:-404,0:[]
0:[]
3:[Tom0,Tom1,Tom2]
true:Tom2,2:[Tom0,Tom1]
true:Tom1,1:[Tom0]
true:Tom0,0:[]
false:-404,0:[]
*/
void testDelBack(){
 
LinkList<int> iList;
iList.show();
 
int iArray[3] = {11,22,33};
iList.createListArr(iArray, 3);
iList.show();
for(int i=0; i<4; i++){
int tmp=-404;
cout<<boolalpha << iList.delBack(tmp) ; 
cout << ":"<< tmp <<",";
 
iList.show();
}
 
 
 
LinkList<string> sList;
sList.show();
 
string sArray[3] = {"Tom0", "Tom1", "Tom2"};
sList.createListArr(sArray, 3);
sList.show();
for(int i=0; i<4; i++){
string tmp="-404";
cout<<boolalpha << sList.delBack(tmp) ; 
cout << ":"<< tmp <<",";
 
sList.show();
}
}
 
 
/*
0:[]
true:11,2:[22,33]
true:22,1:[33]
true:33,0:[]
false:-404,0:[]
0:[]
3:[Tom0,Tom1,Tom2]
true:Tom0,2:[Tom1,Tom2]
true:Tom1,1:[Tom2]
true:Tom2,0:[]
false:-404,0:[]
*/
void testDelFirst(){
 
LinkList<int> iList;
iList.show();
 
int iArray[3] = {11,22,33};
iList.createListArr(iArray, 3);
 
for(int i=0; i<4; i++){
int tmp=-404;
cout<<boolalpha << iList.delFirst(tmp) ; 
cout << ":"<< tmp <<",";
 
iList.show();
}
 
 
 
LinkList<string> sList;
sList.show();
 
string sArray[3] = {"Tom0", "Tom1", "Tom2"};
sList.createListArr(sArray, 3);
sList.show();
for(int i=0; i<4; i++){
string tmp="-404";
cout<<boolalpha << sList.delFirst(tmp) ; 
cout << ":"<< tmp <<",";
 
sList.show();
}
}
 
 
 
/*
TestCase:
0:[]
3:[33,22,11]
 
0:[]
3:[Tom2,Tom1,Tom0]
 
0:[]
3:[11,22,33]
0:[]
3:[Tom0,Tom1,Tom2]
 
*/
void testNodeT(){
 
Node<int> node(2021);
 
node.show();
cout <<endl;
 
Node<string> snode("Tom");
snode.show();
}
 
int main()
{
testDelObj();
/*
void (*fn) []() = {testNodeT, testDelFirst, testDelBack, testDelElem, testDelObj};
fn[0]();
*/
 
return 0;
}

