#include <stdio.h>
#include <stdlib.h>//调用malloc

int main() {
    int n = 0;
    printf("要求几个数的平均值？");
    if ((scanf("%d",&n)) != 1 ) {
        printf("输入不合法\n");
        return 1;
    }
    
    int *p = (int*)malloc(n * sizeof(int));//申请动态地址
    if (p == NULL) {//注意检查有没有申请成功
        printf("内存不足\n");
        return 1;
    }

    int sum =0;
    int cnt = 0;
    printf("请开始输入数字,输入-1则代表结束输入: ");
    for (int i = 0;i < n;i ++) {//遍历循环
        if (scanf("%d",&p[i]) != 1) {
            printf("输入不合法\n");
            free(p);//不合法也要释放指针
            return 1;
        }
        sum += p[i];
        cnt++;
    }

    double avg = 0.0;
    avg = (double)sum / cnt;//注意整数除法，记得强制转换为double类型，防止丢失结果小数部分
    printf("平均数为：%lf\n",avg);//double对应lf
    free(p);//记得释放指针
    p = NULL;//置空
    return 0;
}