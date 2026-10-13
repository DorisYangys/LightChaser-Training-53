#include<stdio.h>
int main()
{
    int i;
    int sum = 0; //对sum初始化
    for (i = 1; i <= 100; i++) //for循环有三块，（起点；继续条件；运算过程）
    {
        if (i % 2 != 0) //常用的判断奇偶数的方法
        {
            sum += i;
        }
    }
    printf("1~100的奇数和 = %d\n",sum);
    return 0;
}