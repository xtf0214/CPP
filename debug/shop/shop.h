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

struct Goods  //��Ʒ�ṹ��
{
	string id;  //��Ʒ���
	string name;  //��Ʒ����
	float price;  //��Ʒ����
	string producer;  //�����̼�
	int store;  //�����
};

struct OrderItem  //������ṹ��
{
	string id;  //���
	string name;  //����
	float price;  //����
	int count;  //����
};

typedef struct
{
	Goods* elem;  //�׵�ַ
	int length;
}SqlList;  //��Ʒ����
typedef struct
{
	OrderItem* elem;
	int length;
}OrderSqlList;  //��������

status InitListSq(SqlList& L);
status InitOListSq(OrderSqlList& L);  //�����ʼ��

int locateElem_Sq(SqlList& L, string id);  //����id��ѯ��Ʒ
int Find_Name(SqlList& L, string name);  //�������Ʋ�ѯ��Ʒ

status ListInsert(SqlList& L, Goods g);  //������Ʒ���ϼ�����Ʒ
status ListOInsert(OrderSqlList& L, OrderItem o);  //��������


int ListUpdate(SqlList& L, string id, int count);  //��Ʒ����

void PrintAllGoods(SqlList& L);  //��ӡ��Ʒ��Ϣ
void PrintOrder(OrderSqlList &L);  //��ӡ����

void Save_Disk(SqlList& L);
void Save_Order_Disk(OrderSqlList& L);