#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>
#include"structure.h"
#include"statement.h"

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
            interface_reader();

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
            interface_manager();

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
}
