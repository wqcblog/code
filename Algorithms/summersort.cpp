/*
分治思想 双指针算法
1.确定分界点 mid=(l+r)/2
2.递归排序
3.归并 合二为一
*/
#include <iostream>
using namespace std;
const int N = 1000010;
int n;
int q[N], tmp[N];
void merge_sort(int q[],int l,int r){
    if(l>=r)
        return;
    int mid = l + r >> 1;//确定分界点
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);//开始递归
    int k = 0, i = l, j = mid + 1;//归并
    while(i<=mid&&j<=r)
      if(q[i]<=q[j])
          tmp[k++] = q[i++];
      else
          tmp[k++] = q[j++];
    while(i<=mid)
        tmp[k++] = q[i++];
    while(j<=r)
        tmp[k++] = q[j++];//将有一侧结束之后另一侧的后续值补充到tmp中
    for (i = l, j = 0; i <= r;i++,j++)
        q[i] = tmp[j];
}
//归并的"两个"数组均为有序，依次扫描比较更小值放置到临时数组中
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n;i++)
        scanf("%d", &q[i]);
    merge_sort(q, 0, n - 1);
    for (int i = 0; i < n;i++)
        printf("%d ", q[i]);
}
