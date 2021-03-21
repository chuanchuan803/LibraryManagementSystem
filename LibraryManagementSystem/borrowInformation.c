#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>
#include"structure.h"
#include"statement.h"

//保存借阅信息
void saveRecordInfo(struct Record rec[], int recCount)
{
    int i;
    FILE *fp;

    fp = fopen("Record.txt", "w");    //以写入的形式打开文件
    if(fp == NULL)    //判断文件是否打开成功
    {
        return;
    }

    if(recCount == 0)    //开始写入文件
    {
        fprintf(fp, "");
    }
    else
    {
        for(i=0; i<recCount; i++)
        {
            fprintf(fp, "%s %s\n", rec[i].no, rec[i].username);
        }
    }

    fclose(fp);    //写入文件成功，关闭文件
}

//读取借阅信息
int readRecordInfo(struct Record rec[])
{
    int i = 0;
    FILE *fp;

    fp = fopen("Record.txt", "r");    //以读取的形式打开文件
    if(fp == NULL)    //判断文件是否打开成功
    {
        return 0;
    }

    while(fscanf(fp, "%s %s\n", rec[i].no, rec[i].username) != EOF)    //开始读取文件
    {
        i ++;
    }

    fclose(fp);    //读取文件成功，关闭文件
    return i;    //返回读取的数量
}

//开始借阅图书
int borrowBookInfo(struct Record rec[], int recCount, struct Book boo[], int booCount, struct User user)
{
    int i;
    int j;
    struct Record input;

    if(recCount == MAX)    //检查当前借阅信息是否已满
    {
        printf("当前借阅信息已满,无法继续添加!\n\n");
        return recCount;
    }

    printf("请输入图书编号:");    //开始输入图书编号
    scanf("%s", input.no);
    for(i=0; i<booCount; i++)    //检查输入的图书编号是否存在
    {
        if(strcmp(boo[i].no,input.no) == 0)
        {
            break;
        }
    }

    if(i == booCount)    //判断输入的图书编号不存在
    {
        printf("借阅图书信息失败,输入的图书编号不存在!\n\n");
        return 0;
    }

    if(boo[i].count == boo[i].bcount)    //判断输入的图书信息库存数量不充足
    {
        printf("借阅图书信息失败,当前图书库存数量不足!\n\n");
        return 0;
    }

    for(j=0; j<recCount; j++)    //检查当前用户是否已借阅输入的图书编号
    {
        if(strcmp(rec[j].no,input.no)==0 && strcmp(rec[j].username,user.username)==0)
        {
            break;
        }
    }

    if(j != recCount)    //当前用户已借阅输入的图书编号
    {
        printf("借阅图书信息失败,您已借阅本图书信息!\n\n");
        return 0;
    }

    //开始借阅图书
    strcpy(input.username, user.username);    //复制用户名到借阅记录信息中
    rec[recCount] = input;    //保存借阅信息到数组中
    recCount ++;
    boo[i].bcount ++;    //修改图书借出数量信息
    printf("借阅图书信息成功!\n\n");

    return recCount;
}

//归还图书
int returnBookInfo(struct Record rec[], int recCount, struct Book boo[], int booCount, struct User user)
{
    int i;
    int j;
    struct Record input;

    if(recCount == 0)    //检查当前借阅信息是否为空
    {
        printf("当前借阅信息为空,无法继续归还!\n\n");
        return 0;
    }

    printf("请输入图书编号:");    //开始输入图书编号
    scanf("%s", input.no);

    for(i=0; i<booCount; i++)    //检查输入的图书编号是否存在
    {
        if(strcmp(boo[i].no,input.no) == 0)
        {
            break;
        }
    }

    if(i == booCount)    //输入的图书编号不存在
    {
        printf("归还图书信息失败,输入的图书编号不存在!\n\n");
        return 0;
    }

    for(j=0; j<recCount; j++)    //图书编号存在，检查借阅信息是否存在
    {
        if(strcmp(rec[j].no,input.no)==0 && strcmp(rec[j].username,user.username)==0)
        {
            break;
        }
    }

    if(j == recCount)    //借阅信息不存在
    {
        printf("归还图书信息失败,您未借阅该图书信息!\n\n");
        return 0;
    }

    for(; j<recCount-1; j++)    //开始归还图书信息，覆盖删除借阅信息
    {
        rec[j] = rec[j+1];
    }
    recCount--;
    boo[i].bcount--;    //修改图书借出数量信息
    printf("归还图书信息成功!\n\n");

    return recCount;
}

//查询我的借阅信息
void myRecordInfo(struct Record rec[], int recCount, struct User user)
{
    int i;
    int flag = 0;

    if(recCount == 0)    //检查当前借阅信息是否为空
    {
        printf("当前借阅信息为空,无法继续查询!\n\n");
        return;
    }

    for(i=0; i<recCount; i++)    //遍历借阅信息结构体对象数组，输出每个借阅信息
    {
        if(strcmp(rec[i].username,user.username) == 0)    //判断是否需要输出标题
        {
            if(flag == 0)    //输出标题
            {
                printf("+--------------+--------------+\n");
                printf("|%-14s|%-14s|\n","图书编号","用户名");
                printf("+--------------+--------------+\n");
                flag=1;
            }
            //输出详细借阅信息
            printf("|%-14s|%-14s|\n", rec[i].no, rec[i].username);
            printf("+--------------+--------------+\n");
        }
    }

    if(flag == 0)    //判断没有查询结果
    {
        printf("暂无我的借阅信息!\n");
    }
    printf("\n");
}
