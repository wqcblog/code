/*算法思想：
算法思想：求n位的字符串的全排列，先确定第0位，然后对后面n-1位进行全排列，在对n-1为进行全排列时，先确定第1位，然后对后面的n-2位进行全排列...由此得到递归函数和递归的结束条件。全排列即交换位置，到n-2位时，就是将n-2和n-1交换位置。
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SWAP(x,y,t) ((t) = (x),(x) = (y),(y) = (t))   //宏定义一个交换函数
/*镜像反转函数*/
void reverse(char *a, char *b){
    int t = 0;
    /*比较的是下标，不是字符数据的值*/
    while (a < b){
        SWAP(*a, *b, t);
        a++;
        b--;
    }
}

//递归算法
/*
例子：abc
第一位是a固定，对后面的bc交换位置得abc,acb.
当a和b交换位置之后，得到bac，对ac进行全排列bac,bca.
当a和c交换位置之后，得到cba，对ba进行全排列得cba,cab
*/
bool isSwap(char *list, int begin, int end)
{
    for (int i = begin; i < end; i++)
    {
        if (list[i] == list[end])
            return false;
    }
    return true;
}//避免重复调用递归，确保只有一次首元素的使用
void perm(char *list, int i, int n)//n为数组长度，第一次i初始值为0，递归时i代表深度
{
    int j, temp;
    if (i == n){//i表示递归的深度，到达n时代表此次已完成一次排列
        printf("%s\n", list);
    }
    else
    {
        for (j = i; j < n; j++) //从当前深度i进一步递归，当前递归需要改变n-i次首位的元素
        {
            if (isSwap(list, i, j))
            {
                SWAP(list[i], list[j], temp); //交换位置，改变首位的元素
                perm(list, i + 1, n);
                SWAP(list[i], list[j], temp); //递归调用完成后恢复元素的位置保证元素的顺序性
            }
        }
            }
}

/*计算下一个排列*/
//非递归算法
bool nextPermutation(char list[]){
    int temp;
    /*从字符串的最后一位开始向前扫描*/
    char *pEnd = list + strlen(list)-1;
    if (list == pEnd)
        return false;//扫描结束退出

    char *p, *q, *pFind; //从最后向前扫描，p指向字符串的前一位，q指向字符串的后一位
    p = pEnd;
    while (p != list) {
        q = p;
        --p;
        if (*p < *q){
            pFind = pEnd;
            while (*pFind <= *p)
                --pFind;//快速排序的好处：便于接下来的交换
            SWAP(*pFind, *p, temp); //从后往前找到第一个比p大的值交换位置
            reverse(q, pEnd);//q到最后元素的字符串进行反转
            return true;
        }
    }
    return false;
}

int qSortCmp(const void *pa, const void *pb){
    return *(char*)pa - *(char*)pb;//指针类型的转换以及取指针指向的元素
}

int main() {
    int n;
    printf("input:");
    scanf("%d", &n);
    char list[n+1];
    char a = 'a';
    for (int i = 0;i<n; i++,a++)
        list[i] = a;
    list[n] = '\0';

    printf("solution1:\n");
    //递归解法
    perm(list, 0, strlen(list));

    printf("\nsolution2:\n");
    //非递归解法
    /*先对字符串进行快速排序，从小到大排列*/
    qsort(list, strlen(list), sizeof(list[0]), qSortCmp);
    //参数变量依次为待排序数组地址，待排序元素数量，待排序元素大小，比较函数
    /*
    qsort 函数的用法规定，“比较函数”的原型应是：int 函数名(const void * elem1, const void * elem2);该函数的两个参数，elem1 和elem2，指向待比较的两个元素。也就是说， * elem1 和* elem2 就是待比较的两个元素。该函数必须具有以下行为：
　　1) 如果 * elem1 应该排在 * elem2 前面，则函数返回值是负整数（任何负整数都行）。
　　2) 如果 * elem1 和* elem2 哪个排在前面都行，那么函数返回0
　　3) 如果 * elem1 应该排在 * elem2 后面，则函数返回值是正整数（任何正整数都行）
    */
    do{
        printf("%s\n",list);//第一次打印本身
    } while (nextPermutation(list));
    return 0;
}
















