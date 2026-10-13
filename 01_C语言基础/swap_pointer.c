#include<stdio.h>
void swap(int *n,int *m)//调用函数
{
    int temp = *n;//引入第三变量是交换变量常用的方法
    *n = *m;
    *m = temp;
}
int main()
{
    int a = 666;
    int b = 999;
    printf(" 交换前:a = %d,b = %d",a,b);
    swap(&a,&b);//&不可少，要调出变量的地址
    printf("交换后:a = %d,b = %d",a,b);
    return 0;
}