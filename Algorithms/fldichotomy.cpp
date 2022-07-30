//浮点数二分法找平方根
#include <iostream>
using namespace std;
int main(){
    double x;
    cin >> x;
    double l = 0, r = x;
    while(r-l>1e-8){//保留小数大二位，此处对应六位小数
        double mid = (l + r) / 2;
        if(mid*mid>=x)
            r = mid;
        else
            l = mid;
    }
    //相当于for(int i=0;i<100;i++) 区间长度除于2的100次方
    printf("%lf\n", l);
    return 0;
}
