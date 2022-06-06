#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<stdio.h>

#define MAXSIZE 100
#define OK 1
#define ERROR0 -3
#define ERROR1 0
#define ERROR2 -1
#define OVERFLOW0 -2

using namespace std;

typedef int status;
typedef int ElemType;

struct Goods  //商品结构体
{
	string id;  //商品编号
	string name;  //商品名称
	float price;  //商品单价
	string producer;  //生产商家
	int store;  //库存量
};

struct OrderItem  //销售项结构体
{
	string id;  //编号
	string name;  //名称
	float price;  //单价
	int count;  //数量
};

typedef struct
{
	Goods* elem;  //首地址
	int length;
}SqlList;  //商品链表
typedef struct
{
	OrderItem* elem;
	int length;
}OrderSqlList;  //订单链表

status InitListSq(SqlList& L);
status InitOListSq(OrderSqlList& L);  //链表初始化

int locateElem_Sq(SqlList& L, string id);  //根据id查询商品
int Find_Name(SqlList& L, string name);  //根据名称查询商品

status ListInsert(SqlList& L, Goods g);  //新增商品，上架新商品
status ListOInsert(OrderSqlList& L, OrderItem o);  //新增订单


int ListUpdate(SqlList& L, string id, int count);  //商品销售

void PrintAllGoods(SqlList& L);  //打印商品信息
void PrintOrder(OrderSqlList &L);  //打印订单

void Save_Disk(SqlList& L);
void Save_Order_Disk(OrderSqlList& L);