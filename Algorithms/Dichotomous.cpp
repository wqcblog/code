/*
向上取整[mid,r] [1,mid-1]
向下取整[1,mid] [mid+1,r]


当想找满足性质的右边界值
找中间值 mid = (l+r+1)/2
if(check(mid))等于true或者是false
check(m)是检查m是在不满足性质的区间
更新l或者r

当想找满足性质的左边界值
1. 找中间值 mid = (l+r)/2
2. if(check(mid))等于true或者是false
check(m)是检查m是在满足性质的区间
3. 更新l或者r
*/
//一个有序的数组，查找几个数的范围(一次找头 一次找尾)
#include <iostream>
using namespace std;
const int N = 100010;
int n, m;
int q[N];
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n;i++)
        scanf("%d", &q[i]);
        while(m--){
            int x;
            scanf("%d", &x);
            int l = 0, r = n - 1;
            while(l<r){
                int mid = l + r >> 1;
                if (q[mid] >= x)
                    r = mid;
                else l = mid + 1;
            }
            if(q[l]!=x)
                cout << "-1 -1" << endl;
                else{
                    cout << l << ' ';
                    int l = 0, r = n - 1;
                    while(l<r){
                        int mid = l + r + 1 >> 1;
                        if(q[mid]<=x)
                            l = mid;
                        else
                            r = mid - 1;
                    }
                    cout << l << endl;
                }
        }
        return 0;
}
