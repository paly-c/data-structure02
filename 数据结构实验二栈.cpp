// 数据结构实验二栈.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//入栈和出栈的设计

//结构体指针变量->成员名 ==（*结构体指针变量）.成员名

//#include <stdio.h>
//#include <stdlib.h>          //标准库函数,malloc
//#include <string.h>
//#define MAXsize 1000
//typedef int ElemTpye;
//struct stack {
//    ElemTpye elem[MAXsize];
//    int top;
//    int base;
//    int maxsize;
//}; 
//struct stack InitStack() {
//    struct stack* s;
//    s = (struct stack*)malloc(sizeof(struct stack));
//    if (!s->top) {
//        printf("失败");
//    }
//     s->top=s->base = -1;
//     s->maxsize = MAXsize;
//    return *s;
//}stack;
//void push(struct stack *s, int x) {//x是入栈元素
//    if (s->top < MAXsize - 1) {//栈未满
//        s->top = x;
//        s->top++;
//      
//    }
//    else {
//        
//    }
//}
//int out(struct stack* s) {
//    if (s->top == -1) {
//        return 0;
//    }
//    else {
//        s->top--;
//        return 1;
//    }
//}
//void ceart(struct stack* s){
//    int n, tem = 0, t;
//        printf("请输入你想输入的栈元素的个数\n");
//        scanf_s("%d", &t);
//        printf("请输入你想输入的栈元素（用空格隔开）\n");
//        for (int i = 0; i < t; i++) {
//            scanf_s("%d", &s->elem[i]);
//            s->top++;
//        }
//}
//void PrintStack(struct stack *s) {
//    printf("栈中的元素为:\n");
//    while (s->top != NULL) {
//        printf("%d",s->top);
//        s->top++;
//    }
//    printf("\n");
//
//}
//
//int main()
//{
//    stack s;
//    int n = 0, tem = 0, t, tem1, tem2, tem3;
//    int a, b, c, d;
//    char e, f, g, h;
//    char Y = 'Y';
//    ceart(&s);
//    while (tem == 0) {
//        printf("是否想入栈1////2\n");
//        scanf_s("%d", &a);
//        if (a == 1) {
//            printf("请输入你要入栈的元素\n");
//            scanf_s("%d", &tem1);
//            push(&s, tem1);
//        }
//        printf("是否想栈顶出栈1/////2\n");
//        scanf_s("%d", &b);
//        if (b == 1) {
//            out(&s);
//        }
//        PrintStack(&s);
//        printf("是否不想操作而退出循环1/////2\n");
//        scanf_s("%d", &c);
//        if (c == 1) {
//            tem = 1;
//        }
//    }
//
//}
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#define MAXsize 10
#define MAXsize_add 10
typedef int ElemType;
typedef struct {
    ElemType* top;  //栈顶指针
    ElemType* base; //栈底指针
    int maxsize;    //最大长度
}stack;
void Initstack(stack* s) {//分配初始内存大小
    s->base = (ElemType*)malloc(MAXsize * sizeof(ElemType));
    if (!s->base) {//判断内存是否分配成功
        printf("内存分配失败\n");
        return;
    }
    s->top = s->base;    //初始化栈顶和栈底指向相同
    s->maxsize = MAXsize;    //初始化栈的最大大小
}

void push(stack* s, int x) {
    if (s->top - s->base >= s->maxsize) {//判断栈是否超过了最大长度
        //relloc 重新分配内存，有两个参数，分别是指向地址的指针和内存大小
        s->base = (int*)realloc(s->base, (s->maxsize + MAXsize_add) * sizeof(ElemType));
        //指针名=（数据类型）realloc（要改变内存大小的指针名，新的大小）
        if (!s->base) {
            printf("内存分配失败\n");
            return;
        }
    }
    *(s->top) = x;//top指针向上移动，指向下一个元素,此时还没有内容
    s->top++;
}

ElemType out(stack* s) {
    if (s->top == s->base) {//判断是否为空栈
        printf("该栈为空!\n");
        return -1;
    }
    return *--(s->top);
}

void PrintStack(stack s) {
    if (s.top == s.base) {//判断是否为空栈
        printf("该栈为空!\n");
        return;
    }
    ElemType* p = s.base;
    printf("栈中的元素为:\n");
    while (p < s.top) {
        printf("%d  ", *p);
        p++;
    }
    printf("\n");
}
//数制转换
void zhuanhuan(int n ,int x) {//（n小于10)(n为变成的进制,x为值)
    stack s;
    Initstack(&s);
    int tem1, tem2, tem3,tem4;
    tem4 = x;
    while (x!= 0) {
        tem1 = x % n;
        x = x / n;
        push(&s, tem1);
        if (s.top == s.base) {//判断是否为空栈
            printf("该栈为空!\n");
            return;
        }
    }
    printf("%d转换为%d进制后为:",tem4, n);
    while (s.top != s.base) {
        tem2 =out(&s);
        printf("%d", tem2);
    }
}
void main() {
    stack s;
    Initstack(&s);
    int n = 0, tem = 0, t, tem1, tem2, tem3;
    int a, b, c, d,e;
     while (tem == 0) {//利用while循环实现栈是出入
        printf("是否想入栈1////0(其他）\n");
        scanf_s("%d", &a);
        if (a == 1) {
            printf("请输入你要入栈的元素\n");
            scanf_s("%d", &tem1);
            push(&s, tem1);
        }
        PrintStack(s);
        printf("是否想栈顶出栈1/////0(其他）\n");
        scanf_s("%d", &b);
        if (b == 1) {
            out(&s);
        }
        PrintStack(s);
        printf("是否退出循环1/////0(其他）\n");
        scanf_s("%d", &c);
        if (c == 1) {
            tem = 1;
        }
    }
     printf("请输入你想将数转换成10以下的哪一个进制:\n");
     scanf_s("%d", &d);
     printf("请输入你想将数转换成%d进制的数:\n",d);
     scanf_s("%d", &e);
     zhuanhuan(d, e);
}







