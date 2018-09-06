//
// Created by dekai on 2018/9/6.
// 本例子多摘自数据结构
//


#include <stdio.h>

//malloc函数需要引入此头
#include <stdlib.h>

//可以在程序中使用return false/true;  其实你也可以#define true 1 和 #define false 0
#include <stdbool.h>

//顺序表空间大小，暂设定为100
#define ListSize 100

/**
 * typedef可以为一个数据类型起一个新的别名！ 此处，仅仅用DataType来代替int而已
 *
 * 为什么要进行起一个别名，因为书序表的数据类型可以为各种，用typedef修改后，可一改全改
 */
typedef char* DataType;

typedef struct {
    DataType data[ListSize];    //顺序表数组，存储表结点数据
    int length;                 //顺序表当前的表长（实际存储元素的个数）
}SeqList;   //顺序表的结构体

//一共有三个参数 分别是 所要插入的顺序表指针 ，所要插入的位置索引 ，所要插入的数据
//即此函数的功能为 在SeqList顺序表的i位置上插入数据x
int insertList(SeqList *L,DataType x,int i) {
    int j;
    //判断i插入位置是否合法
    if( i<1  || i>L->length+1) {
        printf("\nPosition error!! maybe you want to add one at the end,if yes,you can use function:addList\n");
        return false;
    }

    //判断此时的顺序表L长度是否已经为最大值，即已经饱和，不能再插入哪怕一个数据
    if( L->length >= ListSize ) {
        printf("\noverflow\n");
        return false;
    }

    //从顺序表的最后一个数据开始，不停的将数据后移，直至到所指定位置
    //注意传入的int i ,是我们人类认为的从1开始数数所得的位置，而C语言的数据，下标是从0开始的所以i要减去1
    for( j=L->length;j>i-1;j-- ) {
        L->data[j] = L->data[j-1];
    }
    L->data[i-1] = x;
    L->length++;

    return true;
}

//在SeqList顺序表的最后插入数据
int addList(SeqList *L,DataType x) {
    //如果顺序表空间已满
    if( L->length > ListSize )
        return false;

    L->data[L->length] = x;
    L->length++;

    return true;
}

//打印列表，第二个参数int i 可以指定打印的长度
int selectList(SeqList *L,int i) {
    if( !L )
        return false;

    //如果所传长度i 超过顺序表长度或小于0，则默认复制当前顺序表的长度
    if( i <=0 || i > L->length ) {
        i = L->length;
    }

    printf("\n数据列表长度为：%d \n数据列表为：",L->length);
    for (int j = 0; j < i; ++j) {
        printf("%s \t",L->data[j]);
    }
    printf("\n");
    return true;
}

//删除某一个元素，第二个参数int i 指定删除参数的坐标
int deleteList(SeqList *L,int i) {
    if( !L )
        return false;

    //如果所传长度i 超过顺序表长度或小于0，则默认复制当前顺序表的长度
    if( i <=0 || i > L->length ) {
        printf("\nPosition error!!\n");
        return false;
    }

    for (;i<=L->length;i++) {
        L->data[i-1] = L->data[i];
    }

    L->length--;

    return true;
}

int main() {
    SeqList *listD = (SeqList *)malloc(sizeof(SeqList));

    //添加数据
    addList(listD,"KENY");
    addList(listD,"HALL");
    addList(listD,"YOO");
    addList(listD,"Battery");
    selectList(listD,0);

    //在第二个位置前，插入一个Sina
    insertList(listD,"Sina",2);
    selectList(listD,0);

    //删除第三个元素
    deleteList(listD,3);
    selectList(listD,0);
}