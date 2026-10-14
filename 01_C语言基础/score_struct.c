#include <stdio.h>
#include <stdlib.h>

struct Student {//造一个学生结构体模板，把姓名和分数捆绑起来
    char name[20];//姓名，用字符数组存，注意此处最多19个字符，最后一个要留给、0
    int score;
};//分号不可少！

int main() {
    int n;
    printf("要录入几个学生？ ");
    if (scanf("%d",&n) != 1 || n <= 0) {
        printf("输入不合法\n");
        return 1;
    } 
    struct Student stu[n];//把所需要记录的学生，装进stu数组
    for(int i = 0;i < n;i++) {//遍历区间，走了n次
        printf("请输入第%d个学生的 姓名 分数： ",i + 1);//i+1是为了在第一行显示第1个，否则显示第0个
        scanf("%19s %d",stu[i].name,&stu[i].score);
        //19s是限制读入长度
        // stu[i].name 是数组，本身是地址，所以【不加 &】
        // stu[i].score 是普通变量，要把值写进去，所以【要加 &】
    }
    printf("\n--- 成绩单 ---\n");
    for (int i = 0;i < n;i++) {
        printf("%-12s %d\n",stu[i].name,stu[i].score);//-是左对齐
    }
    return 0;
}