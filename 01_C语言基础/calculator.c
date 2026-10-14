#include <stdio.h>
int main()
{
    double a,b,result; //此处用double，强调输入数字可为小数
    char op;           //char指输入字符,只能存 1 个字符；
    printf("简易计算器\n");  //\n换行，让输出页面更清晰明了
    printf("请输入算式： ");
    if(scanf("%lf %c %lf",&a,&op,&b) != 3) //scanf返回的是输入的值的个数，此处要求为三个值,注意 %c 会读进空白字符，靠格式串里的空格跳过
    {
       printf("输入格式不符,正确格式为:数字 运算符 数字");
       return 1; //如果不对则退出程序(非 0 = 异常退出，0 = 正常结束)
    }
    else
    {
        switch(op) //switch-case适用于特定值对应特定情况
        {
            case'+'://单引号是字符常量（值就是 ASCII 码 ）；双引号 "+" 是字符串，不能做 case
               result = a + b;
               break; //break为该情况的出口
            case'-':
               result = a - b;
               break;
            case'*':
               result = a * b;
               break;
            case'/':
               if (b == 0)
               {
                printf("除数不能为0!");
                return 1;
               }
               result = a / b;
               break;
            default:printf("仅支持运算符+ - * /");//default不可少，所有情况都不符合时执行
        }
        printf("%lf %c %lf = %lf",a,op,b,result) ; 
    }
    return 0;
}