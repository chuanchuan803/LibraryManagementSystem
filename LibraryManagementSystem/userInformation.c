#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structure.h"
#include"statement.h"


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
        interface_login();

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
