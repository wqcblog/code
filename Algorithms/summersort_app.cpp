//求一个数组逆序对的数量 下标i<j a[i]>a[j]
//问题的本质就是在合并的时候直接放置不用比较的元素实际上就是该元素能够组成的逆序对的数量
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N];
int nums;
unsigned long result = 0;

void merge_sort(int a[], int l, int r)
{
    if (l >= r) return;
    int mid = ( l + r  ) / 2;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    int temp[r - l + 1];
    int lptr = l;
    int rptr = mid + 1;
    int tempptr = 0;
    while(lptr <= mid && rptr <= r)
    {
        if(a[lptr] <= a[rptr])
        {
            temp[tempptr++] = a[lptr++];
        } else {
            temp[tempptr++] = a[rptr++];
            result += (mid - lptr + 1);//注意这里，是直接加的，后面的不需要比较了。
        }
    }
    while ( lptr <= mid )
    {
        temp[tempptr++] = a[lptr++];
    }
    while ( rptr <= r )
    {
        temp[tempptr++] = a[rptr++];
    }
    for (int i = l, j = 0; i <= r; i ++, j ++)
    {
        a[i] = temp[j];
    }
}

int main(){
    scanf("%d", &nums);
    for(int i = 0; i < nums; i++)
    {
        scanf("%d", &a[i]);
    }
    merge_sort(a, 0, nums-1);
    cout << result;
    return 0;
}
