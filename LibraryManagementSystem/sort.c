#include<stdio.h>
#include<stdlib.h>
#include"structure.h"
#include"statement.h"

//排序图书信息
void sortBookInfo(struct Book boo[], int booCount)
{
    int i;
    int j;
    int sobj;
    int stype;
    struct Book temp;

    if(booCount == 0)    //检查当前图书信息是否为空
    {
        printf("当前图书信息为空,无法继续排序!\n\n");
        return;
    }

    printf("请输入需要排序的对象编号(1.总库存数量 2.现库存数量 0.返回菜单):");    //开始输入排序的对象编号
    scanf("%d", &sobj);

    if(sobj == 0)    //判断是否返回菜单
    {
        return;    //结束本函数
    }

    printf("请输入需要排序的方式编号(1.升序排序 2.降序排序):");    //输入排序的方式
    scanf("%d", &stype);
    if(sobj<1 || sobj>2 || stype<1 || stype>2)    //检查编号输入是否正确
    {
        printf("排序图书信息失败,输入的编号不存在!\n\n");
        return;
    }

    for(i=0; i<booCount-1; i++)    //使用冒泡排序法进行排序
    {
        for(j=0; j<booCount-i-1; j++)
        {
            //判断是否达到交换条件
            if((sobj==1 && stype==1 && boo[j].count>boo[j+1].count) || (sobj==1 && stype==2 && boo[j].count<boo[j+1].count) || (sobj==2 && stype==1 && (boo[j].count-boo[j].bcount)>(boo[j+1].count-boo[j+1].bcount)) || (sobj==2 && stype==2 && (boo[j].count-boo[j].bcount)<(boo[j+1].count-boo[j+1].bcount)))
            {
                //交换两个结构体变量值
                temp = boo[j];
                boo[j] = boo[j+1];
                boo[j+1] = temp;
            }
        }
    }

    //排序完成,输出排序结果
    //输出标题
    printf("+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+\n");
    printf("|%-14s|%-14s|%-14s|%-14s|%-14s|%-14s|%-14s|%-14s|%-14s|%-14s|\n","图书编号","图书名称","图书作者","图书出版社","图书ISBN","图书出版时间","图书分类","图书结构","图书库存数量","图书借出数量");
    printf("+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+\n");

    //遍历图书信息结构体对象数组,输出每个图书信息
    for(i=0; i<booCount; i++)
    {
        printf("|%-14s|%-14s|%-14s|%-14s|%-14s|%-14s|%-14s|%-14s|%-14d|%-14d|\n", boo[i].no, boo[i].name, boo[i].author, boo[i].publisher, boo[i].isbn, boo[i].date, boo[i].type, boo[i].structure, boo[i].count, boo[i].bcount);
        printf("+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+\n");
    }
    printf("\n");
}
