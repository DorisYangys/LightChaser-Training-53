#include<stdio.h>
void swap(int *n,int *m)//调用函数，交换两个变量的值
{
    int temp = *n;//引入第三变量是交换变量常用的方法。 * 是"解引用运算符"
    //temp 必须是 int（不是 int*），要和 *n 的类型一致
    *n = *m;
    *m = temp;
}
int main()
{
    int a = 666;
    int b = 999;
    printf(" 交换前:a = %d,b = %d",a,b);
    swap(&a,&b);//&不可少，要调出变量的地址
     // 所以函数里改的是 main 里这两个变量本身
    printf("交换后:a = %d,b = %d",a,b);
    return 0;
}