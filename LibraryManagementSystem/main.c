#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>

#define MAX 100 //声明常量表示图书信息结构体数组长度
#define STR 50  //声明常量表示字符数组长度

//声明图书信息结构体
struct Book
{
    char no[STR];           //图书编号
    char name[STR];         //图书名称
    char author[STR];       //图书作者
    char publisher[STR];    //图书出版社
    char isbn[STR];         //图书ISBN
    char date[STR];         //图书出版时间
    char type[STR];         //图书分类
    char structure[STR];    //图书结构
    int count;              //图书库存数量
    int bcount;             //图书借出数量
};

//声明借阅信息结构体
struct Record
{
    char no[STR];           //图书编号
    char username[STR];     //用户名
};

//声明用户信息结构体
struct User
{
    char username[STR];     //用户名
    char password[STR];     //密码
    char identify[STR];     //用户身份(读者/管理员)
};

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

//保存用户信息
void saveUserInfo(struct User use[], int useCount)
{
    int i;
    FILE *fp;

    fp = fopen("User.txt", "w");    //以写入的形式打开文件
    if(fp == NULL)    //判断文件是否打开成功
    {
        return;
    }

    if(useCount == 0)    //开始写入文件
    {
        fprintf(fp, "");
    }
    else
    {
        for(i=0; i<useCount; i++)
        {
            fprintf(fp, "%s %s %s\n", use[i].username, use[i].password, use[i].identify);
        }
    }

    fclose(fp);    //写入文件成功，关闭文件
}

//读取用户信息
int readUserInfo(struct User use[])
{
    int i = 0;
    FILE *fp;

    fp = fopen("User.txt", "r");    //以读取的形式打开文件
    if(fp == NULL)    //判断文件是否打开成功
    {
        return 0;
    }

    while(fscanf(fp, "%s %s %s\n", use[i].username, use[i].password, use[i].identify) != EOF)    //开始读取文件
    {
        i ++;
    }

    fclose(fp);    //读取文件成功，关闭文件
    return i;    //返回读取的数量
}

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

//借阅图书信息
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

//归还图书信息
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


//用户登陆与注册
int userLoginRegister(struct User use[], int *useCount, struct User *user)
{
    int i;
    int choice;
    int running = 1;
    int login =     0;
    struct User input;

    system("clear");
    while(running)
    {
        //显示主菜单
        printf("================================================\n");
        printf("=               图书信息管理系统               =\n");
        printf("=----------------------------------------------=\n");
        printf("=                 - 欢迎使用 -                 =\n");
        printf("=                                              =\n");
        printf("=                  1.用户登陆                  =\n");
        printf("=                  2.用户注册                  =\n");
        printf("=                  0.退出系统                  =\n");
        printf("=                                              =\n");
        printf("================================================\n");

        //输入功能编号
        printf("请输入您需要执行的功能编号:");
        scanf("%d", &choice);
        switch(choice)    //根据功能编号选择对应功能
        {
            case 0:    //退出系统
                running=0;
                break;

            case 1:    //用户登陆开始输入用户信息
                printf("请输入用户名:");
                scanf("%s", input.username);
                printf("请输入密码:");
                scanf("%s", input.password);
                for(i=0; i<*useCount; i++)    //检查输入的用户信息是否正确
                {
                    if(strcmp(use[i].username,input.username)==0 && strcmp(use[i].password,input.password)==0)
                    {
                        break;
                    }
                }
                if(i != *useCount)    //用户信息输入正确
                {
                    login = 1;    //用户登陆成功
                    *user = use[i];    //赋值用户信息
                    running = 0;    //结束while循环
                }
                else    //输入的用户信息不正确
                {
                    printf("用户登陆失败,请检查用户信息是否正确!\n\n");
                }
                break;

            case 2:    //用户注册
                if(*useCount == MAX)    //检查当前用户基本信息是否已满
                {
                    printf("当前用户基本信息已满,无法继续注册!\n\n");
                    break;
                }
                printf("请输入用户名:");    //开始输入用户信息
                scanf("%s", input.username);
                printf("请输入密码:");
                scanf("%s", input.password);
                printf("请输入用户身份(读者/管理员):");
                scanf("%s", input.identify);
                while(strcmp(input.identify,"读者")!=0 && strcmp(input.identify,"管理员")!=0)    //检查输入的用户身份信息是否正确
                {
                    printf("请输入正确的用户身份(读者/管理员):");    //不正确提示重新输入
                    scanf("%s", input.identify);
                }
                for(i=0; i<*useCount; i++)    //检查输入的用户名是否存在
                {
                    if(strcmp(use[i].username,input.username) == 0)
                    {
                        break;
                    }
                }
                if(i == *useCount)    //输入的用户名不存在
                {
                    use[*useCount] = input;    //保存用户基本信息到数组中
                    *useCount = *useCount+1;
                    saveUserInfo(use, *useCount);    //保存用户基本信息
                    printf("用户注册成功,欢迎使用图书信息管理系统!\n\n");
                }
                else    //输入的用户名存在
                {
                    printf("用户注册失败,可能是该用户信息已存在!\n\n");    //提示用户信息已存在
                }
                break;
        }
        if(running)    //按任意键继续
        {
            char c;
            getchar();
            while ( (c = getchar()) != '\n' && c != EOF );
        }
        system("clear");
    }
    return login;    //返回登陆结果
}

//主函数
int main()
{
    int choice;
    int running = 1;
    struct User user;    //当前登陆的用户
    struct Book boo[MAX];    //声明图书信息结构体数组变量
    int booCount = 0;    //声明图书信息结构体数组元素个数变量
    struct User use[MAX];    //声明用户信息结构体数组变量
    int useCount = 0;    //声明用户信息结构体数组元素个数变量
    struct Record rec[MAX];    //声明借阅信息结构体数组变量
    int recCount = 0;    //声明借阅信息结构体数组元素个数变量

    booCount = readBookInfo(boo);    //读取图书信息
    useCount = readUserInfo(use);    //读取用户信息
    recCount = readRecordInfo(rec);    //读取借阅信息
    running = userLoginRegister(use, &useCount, &user);    //用户登陆与注册

    if(strcmp(user.identify,"读者") == 0)    //判断登陆用户身份
    {
        while(running)    //进入读者操作功能菜单
        {
            //显示读者主菜单
            printf("================================================\n");
            printf("=               图书信息管理系统               =\n");
            printf("=----------------------------------------------=\n");
            printf("=                 - 读者菜单 -                 =\n");
            printf("=                                              =\n");
            printf("=                1.浏览图书信息                =\n");
            printf("=                2.查询图书信息                =\n");
            printf("=                3.借阅图书信息                =\n");
            printf("=                4.归还图书信息                =\n");
            printf("=                5.我的借阅信息                =\n");
            printf("=                0.退出系统                    =\n");
            printf("=                                              =\n");
            printf("================================================\n");

            printf("请输入您需要执行的功能编号:");    //输入功能编号
            scanf("%d",&choice);

            switch(choice)    //根据功能编号选择对应功能
            {
                case 0:    //退出系统
                    running = 0;
                    break;

                case 1:    //浏览图书信息
                    browserBookInfo(boo, booCount);
                    break;

                case 2:    //查询图书信息
                    queryBookInfo(boo, booCount);
                    break;

                case 3:    //借阅图书信息
                    recCount = borrowBookInfo(rec, recCount, boo, booCount, user);
                    saveRecordInfo(rec,recCount);    //保存借阅信息
                    saveBookInfo(boo,booCount);    //保存图书信息
                    break;

                case 4:    //归还图书信息
                    recCount = returnBookInfo(rec, recCount, boo, booCount, user);
                    saveRecordInfo(rec, recCount);    //保存借阅信息
                    saveBookInfo(boo, booCount);    //保存图书信息
                    break;

                case 5:    //我的借阅信息
                    myRecordInfo(rec, recCount, user);
                    break;

                default:    //输入功能编号不存在
                    printf("您输入的功能编号不存在,请重新输入!\n\n");
                    break;
            }
            if(running)    //按任意键继续
            {
                char c;
                getchar();
                while ( (c = getchar()) != '\n' && c != EOF );
            }
            system("clear");
        }
    }
    else if(strcmp(user.identify,"管理员") == 0)    //进入管理员操作功能菜单
    {
        while(running)
        {
            //显示管理员主菜单
            printf("================================================\n");
            printf("=               图书信息管理系统               =\n");
            printf("=----------------------------------------------=\n");
            printf("=                - 管理员菜单 -                =\n");
            printf("=                                              =\n");
            printf("=                1.添加图书信息                =\n");
            printf("=                2.修改图书信息                =\n");
            printf("=                3.删除图书信息                =\n");
            printf("=                4.浏览图书信息                =\n");
            printf("=                5.查询图书信息                =\n");
            printf("=                6.排序图书信息                =\n");
            printf("=                7.统计图书信息                =\n");
            printf("=                0.退出系统                    =\n");
            printf("=                                              =\n");
            printf("================================================\n");

            printf("请输入您需要执行的功能编号:");    //输入功能编号
            scanf("%d", &choice);

            switch(choice)    //根据功能编号选择对应功能
            {
                case 0:    //退出系统
                    running = 0;
                    break;

                case 1:    //添加图书信息
                    booCount = addBookInfo(boo, booCount);
                    saveBookInfo(boo, booCount);    //保存图书信息
                    break;

                case 2:    //修改图书信息
                    modifyBookInfo(boo, booCount);
                    saveBookInfo(boo, booCount);    //保存图书信息
                    break;

                case 3:    //删除图书信息
                    booCount = deleteBookInfo(boo, booCount);
                    saveBookInfo(boo,booCount);    //保存图书信息
                    break;

                case 4:    //浏览图书信息
                    browserBookInfo(boo, booCount);
                    break;

                case 5:     //查询图书信息
                    queryBookInfo(boo, booCount);
                    break;

                case 6:    //排序图书信息
                    sortBookInfo(boo, booCount);
                    break;

                case 7:    //统计图书信息
                    statisBookInfo(boo, booCount);
                    break;

                default:    //输入功能编号不存在
                    printf("您输入的功能编号不存在,请重新输入!\n\n");
                    break;
            }
            if(running)    //按任意键继续
            {
                char c;
                getchar();
                while ( (c = getchar()) != '\n' && c != EOF );
            }
            system("clear");
        }
    }

    //显示结束语
    printf("================================================\n");
    printf("=               图书信息管理系统               =\n");
    printf("=----------------------------------------------=\n");
    printf("=               - 欢迎下次使用 -               =\n");
    printf("================================================\n");
}
