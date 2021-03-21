#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>
#include"structure.h"

int userLoginRegister(struct User use[], int *useCount, struct User *user);     //用户登陆与注册
void interface_reader();    //读者操作菜单界面
void interface_login();
void interface_manager();   //管理员操作菜单界面

void saveUserInfo(struct User use[], int useCount);     //保存用户信息
int readUserInfo(struct User use[]);    //读取用户信息

void saveRecordInfo(struct  Record rec[], int recCount);     //保存借阅信息
int readRecordInfo(struct Record rec[]);    //读取借阅信息
int borrowBookInfo(struct Record rec[], int recCount, struct Book boo[], int booCount, struct User user);   //开始借阅图书
int returnBookInfo(struct Record rec[], int recCount, struct Book boo[], int booCount, struct User user);   //归还图书
void myRecordInfo(struct Record rec[], int recCount, struct User user);     //查询我的借阅信息

void saveBookInfo(struct Book boo[], int booCount);     //保存图书信息
int readBookInfo(struct Book boo[]);    //读取图书信息
int addBookInfo(struct Book boo[], int booCount);   //添加图书信息
void modifyBookInfo(struct Book boo[], int booCount);   //修改图书信息
int deleteBookInfo(struct Book boo[], int booCount);    //删除图书信息
void browserBookInfo(struct Book boo[], int booCount);      //浏览图书信息
void queryBookInfo(struct Book boo[], int booCount);    //查询图书信息
void sortBookInfo(struct Book boo[], int booCount);     //排序图书信息
void statisBookInfo(struct Book boo[], int booCount);   //统计图书信息
