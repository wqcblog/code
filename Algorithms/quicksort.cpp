/*
分治思想
1.确定分界点 左边界 右边界 中间 或随机
2.调整区间 满足所有小于分界点的在左边 所有大于分界点的在右边
实现的方法：
(1)建立额外数组a[] b[] 保留小于x 大于x的结果 再放置结果到原数组中
(2)使用两个指针从左右两侧向中间扫描，左边发现大于x的值时右边开始扫描找到小于x的值进行交换，接着左边继续扫描，当两个指针相遇时完成
3.递归处理左右两端
*/
#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int n;
int q[N];
void quick_sort(int q[], int l, int r){
    if(l>=r)
        return;
    int x = q[l], i = l - 1, j = r + 1;//与下面do的写法有关 左右各后退一步
    //int x=q[r]或int x=q[(l+r+1)/2](通用取中间 数据加强时也可以通过)
    while(i<j){
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if(i<j)
            swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    //quick_sort(q,1,i-1);
    //quick_sort(q,i,r)
    quick_sort(q, j + 1, r);
}
//注意边界问题 如1,2这两个数 否则死循环 无限递归

 int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n;i++)
        scanf("%d", &q[i]);
    quick_sort(q, 0, n-1);
    for (int i = 0; i < n;i++)
        printf("%d ", q[i]);
    return 0;
}
