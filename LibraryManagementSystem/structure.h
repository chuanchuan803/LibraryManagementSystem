#ifndef STRUCTURE_H
#define STRUCTURE_H

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

#endif // STRUCTURE_H
