//牛顿迭代法求解次方根问题,还可以用于求一元多项式的解
/*
数学题的话,令y = x³ - n, 然后求根（曲线与x轴的交点）
根据定理得到，多次求切线后会最终收敛到根.（假设是有根的情况下，“多次” 相当于二分里的精度问题）
*/
#include<iostream>
using namespace std;

double cubic(double num){
    double x1 = num;
    double x0;
    for (int i = 0; i < 100; i++){
        x0=x1;
        x1 =x0-(x0*x0*x0-num)/(3*x0*x0);
}
    return x1;
}

int main()
{
    double n; scanf("%lf",&n);

    printf("%.6lf", cubic(n));

    return 0;
}
