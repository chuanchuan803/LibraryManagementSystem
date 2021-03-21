#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"structure.h"
#include"statement.h"

//保存图书信息
void saveBookInfo(struct Book boo[], int booCount)
{
    int i;
    FILE *fp;

    fp = fopen("Book.txt", "w");    //以写入的形式打开文件
    if(fp == NULL)    //判断文件是否打开成功
    {
        return;
    }

    if(booCount == 0)    //开始写入文件
    {
        fprintf(fp, "");
    }
    else
    {
        for(i=0; i<booCount; i++)
        {
            fprintf(fp, "%s %s %s %s %s %s %s %s %d %d\n", boo[i].no, boo[i].name, boo[i].author, boo[i].publisher, boo[i].isbn, boo[i].date, boo[i].type, boo[i].structure, boo[i].count, boo[i].bcount);
        }
    }

    fclose(fp);    //写入文件成功，关闭文件
}

//读取图书信息
int readBookInfo(struct Book boo[])
{
    int i = 0;
    FILE *fp;

    fp = fopen("Book.txt", "r");    //以读取的形式打开文件
    if(fp == NULL)    //判断文件是否打开成功
    {
        return 0;
    }

    while(fscanf(fp, "%s %s %s %s %s %s %s %s %d %d\n", boo[i].no, boo[i].name, boo[i].author, boo[i].publisher, boo[i].isbn, boo[i].date, boo[i].type, boo[i].structure, &boo[i].count, &boo[i].bcount) != EOF)    //开始读取文件
    {
        i ++;
    }

    fclose(fp);    //读取文件成功，关闭文件
    return i;    //返回读取的数量
}

//添加图书信息
int addBookInfo(struct Book boo[], int booCount)
{
    int i;
    struct Book input;

    if(booCount == MAX)    //检查当前图书信息是否已满
    {
        printf("当前图书信息已满,无法继续添加!\n\n");
        return booCount;
    }

    printf("请输入图书编号:");    //开始输入图书编号
    scanf("%s", input.no);

    for(i=0; i<booCount; i++)    //检查输入的图书编号是否存在
    {
        if(strcmp(boo[i].no, input.no) == 0)
        {
            break;
        }
    }
    if(i == booCount)    //输入的图书编号不存在，输入其他的信息
    {
        printf("请输入图书名称:");
        scanf("%s", input.name);
        printf("请输入图书作者:");
        scanf("%s", input.author);
        printf("请输入图书出版社:");
        scanf("%s", input.publisher);
        printf("请输入图书ISBN:");
        scanf("%s", input.isbn);
        printf("请输入图书出版时间:");
        scanf("%s", input.date);
        printf("请输入图书分类:");
        scanf("%s", input.type);
        printf("请输入图书结构:");
        scanf("%s", input.structure);
        printf("请输入图书库存数量:");
        scanf("%d", &input.count);

        while(input.count < 0)    //检查图书库存数量是否正确
        {
            printf("请输入正确的图书库存数量:");    //提示输入正确的图书库存数量信息
            scanf("%d", &input.count);
        }
        input.bcount = 0;    //默认图书借出数量为0

        boo[booCount]=input;    //保存图书信息到数组中
        booCount ++;
        printf("添加图书信息成功!\n\n");
    }
    else    //输入的图书编号已存在
    {
        printf("添加图书信息失败,输入的图书编号已存在!\n\n");
    }

    return booCount;
}

//修改图书信息
void modifyBookInfo(struct Book boo[], int booCount)
{
    int i;
    struct Book input;

    if(booCount == 0)    //检查当前图书信息是否为空
    {
        printf("当前图书信息为空,无法继续修改!\n\n");
        return;
    }

    printf("请输入需要修改的图书编号:");    //开始输入图书编号
    scanf("%s", input.no);

    for(i=0; i<booCount; i++)    //检查输入的图书编号是否存在
    {
        if(strcmp(boo[i].no, input.no) == 0)
        {
            break;
        }
    }

    if(i != booCount)    //输入的图书编号存在，输入其他信息
    {
        printf("请输入图书名称:");
        scanf("%s", input.name);
        printf("请输入图书作者:");
        scanf("%s", input.author);
        printf("请输入图书出版社:");
        scanf("%s", input.publisher);
        printf("请输入图书ISBN:");
        scanf("%s", input.isbn);
        printf("请输入图书出版时间:");
        scanf("%s", input.date);
        printf("请输入图书分类:");
        scanf("%s", input.type);
        printf("请输入图书结构:");
        scanf("%s", input.structure);

        printf("请输入图书库存数量:");
        scanf("%d", &input.count);
        while(input.count < 0)    //检查图书库存数量是否正确
        {
            printf("请输入正确的图书库存数量:");    //提示输入正确的图书库存数量信息
            scanf("%d", &input.count);
        }

        printf("请输入图书借出数量:");
        scanf("%d", &input.bcount);
        while(input.bcount<0 || input.bcount>input.count)    //检查图书借出数量是否正确
        {
            printf("请输入正确的图书借出数量:");    //提示输入正确的图书借出数量信息
            scanf("%d", &input.bcount);
        }

        boo[i] = input;    //修改到数组中
        printf("修改图书信息成功!\n\n");
    }
    else    //输入的图书编号不存在
    {
        printf("修改图书信息失败,输入的图书编号不存在!\n\n");
    }
}

//删除图书信息
int deleteBookInfo(struct Book boo[], int booCount)
{
    int i;
    struct Book input;

    if(booCount == 0)    //检查当前图书信息是否为空
    {
        printf("当前图书信息为空,无法继续删除!\n\n");
        return booCount;
    }

    printf("请输入需要删除的图书编号:");    //开始输入图书编号
    scanf("%s", input.no);

    for(i=0; i<booCount; i++)    //检查输入的图书编号是否存在
    {
        if(strcmp(boo[i].no, input.no) == 0)
        {
            break;
        }
    }
    if(i != booCount)    //输入的图书编号存在
    {
        for(; i<booCount-1; i++)    //覆盖删除信息
        {
            boo[i] = boo[i+1];
        }
        booCount --;
        printf("删除图书信息成功!\n\n");
    }
    else    //输入的图书编号不存在
    {
        printf("删除图书信息失败,输入的图书编号不存在!\n\n");
    }

    return booCount;
}

//浏览图书信息
void browserBookInfo(struct Book boo[], int booCount)
{
    int i;

    if(booCount == 0)    //检查当前图书信息是否为空
    {
        printf("当前图书信息为空,无法继续浏览!\n\n");
        return;
    }

    //输出标题
    printf("+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+\n");
    printf("|%-14s|%-14s|%-14s|%-14s|%-14s|%-14s|%-14s|%-14s|%-14s|%-14s|\n","图书编号","图书名称","图书作者","图书出版社","图书ISBN","图书出版时间","图书分类","图书结构","图书库存数量","图书借出数量");
    printf("+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+\n");

    for(i=0; i<booCount; i++)    //遍历图书信息结构体对象数组，输出每个图书信息
    {
        printf("|%-14s|%-14s|%-14s|%-14s|%-14s|%-14s|%-14s|%-14s|%-14d|%-14d|\n", boo[i].no, boo[i].name, boo[i].author, boo[i].publisher, boo[i].isbn, boo[i].date, boo[i].type, boo[i].structure, boo[i].count, boo[i].bcount);
        printf("+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+\n");
    }
    printf("\n");
}

//查询图书信息
void queryBookInfo(struct Book boo[], int booCount)
{
    int i;
    int qobj;
    int flag=0;
    struct Book input;

    if(booCount == 0)    //检查当前图书信息是否为空
    {
        printf("当前图书信息为空,无法继续查询!\n\n");
        return;
    }

    printf("请输入需要查询的对象编号(1.图书名称 2.图书作者 3.图书分类 0.返回菜单):");    //开始输入查询的对象编号
    scanf("%d",&qobj);

    //输入查询的内容
    if(qobj == 0)     //返回菜单，无需输入
    {
        return;
    }
    else if(qobj == 1)    //输入图书名称
    {
        printf("请输入查询的图书名称:");
        scanf("%s", input.name);
    }
    else if(qobj == 2)    //输入图书作者
    {
        printf("请输入查询的图书作者:");
        scanf("%s", input.author);
    }
    else if(qobj == 3)    //输入图书分类
    {
        printf("请输入查询的图书分类:");
        scanf("%s", input.type);
    }
    else    //输入的对象编号不存在
    {
        printf("查询图书信息失败,输入的对象编号不存在!\n\n");
        return;
    }

    for(i=0; i<booCount; i++)    //遍历图书信息结构体对象数组，查询并输出结果
    {
        if((qobj==1 && strcmp(boo[i].name,input.name)==0) || (qobj==2 && strcmp(boo[i].author,input.author)==0) || (qobj==3 && strcmp(boo[i].type,input.type)==0))
        {
            if(flag == 0)    //判断是否需要输出标题
            {
                //输出标题
                printf("+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+\n");
                printf("|%-14s|%-14s|%-14s|%-14s|%-14s|%-14s|%-14s|%-14s|%-14s|%-14s|\n","图书编号","图书名称","图书作者","图书出版社","图书ISBN","图书出版时间","图书分类","图书结构","图书库存数量","图书借出数量");
                printf("+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+\n");
                flag = 1;
            }

            //输出详细图书信息
            printf("|%-14s|%-14s|%-14s|%-14s|%-14s|%-14s|%-14s|%-14s|%-14d|%-14d|\n", boo[i].no, boo[i].name, boo[i].author, boo[i].publisher, boo[i].isbn, boo[i].date, boo[i].type, boo[i].structure, boo[i].count, boo[i].bcount);
            printf("+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+--------------+\n");
        }
    }

    if(flag == 0)    //判断是否有查询结果
    {
        printf("查询无结果!\n");    //没有查询结果
    }
    printf("\n");
}

//统计图书信息
void statisBookInfo(struct Book boo[], int booCount)
{
    int i;
    int sobj;
    int scount=0;
    struct Book input;

    if(booCount == 0)    //检查当前图书信息是否为空
    {
        printf("当前图书信息为空,无法继续统计!\n\n");
        return;
    }

    printf("请输入需要统计的对象编号(1.总库存数量 2.现库存数量 0.返回菜单):");    //开始输入统计的对象编号
    scanf("%d",&sobj);

    if(sobj == 0)    //判断是否返回菜单
    {
        return;     //结束本函数
    }

    for(i=0; i<booCount; i++)    //遍历图书信息结构体对象数组，统计并输出结果
    {
        if(sobj == 1)
        {
            scount += boo[i].count;
        }
        if(sobj == 2)
        {
            scount += (boo[i].count-boo[i].bcount);
        }
    }

    if(sobj == 1)    //统计完成，输出结果
    {
        printf("当前总库存数量为:%d\n\n", scount);
    }
    if(sobj == 2)
    {
        printf("当前现库存数量为:%d\n\n", scount);
    }

}
