#include "shop.h"
status InitListSq(SqlList &L)
{
	L.elem = new Goods[MAXSIZE];
	if (!L.elem)
	{
		exit(OVERFLOW0);
	} //�ڴ�����ʧ�ܣ�ֱ���˳�����
	L.length = 0;
	return OK;
}; //��ʼ����Ʒ����

status InitOListSq(OrderSqlList &L)
{
	L.elem = new OrderItem[MAXSIZE];
	if (!L.elem)
	{
		exit(OVERFLOW0); //�ڴ�����ʧ�ܣ�ֱ���˳�����
	}
	L.length = 0;
	return OK;
}; //��ʼ��order����

int locateElem_Sq(SqlList &L, string e) //��ѯ�±�
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i].id == e) // id��ѯ
		{
			return i;
		}
	}
	return 0;
}
int Find_Name(SqlList &L, string name)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i].name == name)
		{
			return i;
		}
	}
	return -1;
}

status ListInsert(SqlList &L, Goods g) //��Ʒ�ϼܣ��������
{
	if (L.length == MAXSIZE)
		return ERROR2;
	L.elem[L.length] = g;
	++L.length;
	return OK;
}
status ListOInsert(OrderSqlList &L, OrderItem o) //���������
{
	if (L.length == MAXSIZE)
		return ERROR2;
	L.elem[L.length] = o;
	++L.length;
	return OK;
}

int ListUpdate(SqlList &L, string id, int count) //�޸���Ʒ��棬����
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i].id == id)
		{
			L.elem[i].store -= count;
		}
	}
	return 1;
}

void PrintAllGoods(SqlList &L) //��ӡ��Ʒ
{
	for (int i = 0; i < L.length; i++)
	{
		cout << "��Ʒ��ţ�" << L.elem[i].id << ",���ƣ�" << L.elem[i].name << ",�۸�" << L.elem[i].price << ",�����̣�" << L.elem[i].producer << ",�������" << L.elem[i].store << endl;
	}
}
void PrintOrder(OrderSqlList &L) //��ӡ����
{
	for (int i = 0; i < L.length; i++)
	{
		cout << "��Ʒ��ţ�" << L.elem[i].id << ",���ƣ�" << L.elem[i].name << ",���ۣ�" << L.elem[i].price << ",����������" << L.elem[i].count << endl;
	}
}

void Save_Disk(SqlList &L) //����goods�ļ�
{
	fstream Fileout("c:/goods.txt", ios::out);
	if (!Fileout)
	{
		cout << "�ļ�д��ʧ�ܣ�" << endl;
		exit(ERROR0);
	}
	Fileout << "id"
			<< "name"
			<< "price"
			<< "producer"
			<< "store" << endl;
	for (int i = 0; i < L.length; ++i)
	{
		Fileout << L.elem[i].id << ' ' << L.elem[i].name << ' ' << L.elem[i].price << ' ' << L.elem[i].producer << ' ' << L.elem[i].store << endl;
	}
	Fileout.close();
	return;
}
void Save_Order_Disk(OrderSqlList &L)
{
	fstream Fileout("c:/order.txt", ios::out);
	if (!Fileout)
	{
		cout << "������ӡʧ��" << endl;
		exit(ERROR0);
	}
	Fileout << "id"
			<< "name"
			<< "count"
			<< "price" << endl;
	for (int i = 0; i < L.length; ++i)
	{
		Fileout << L.elem[i].id << ' ' << L.elem[i].name << ' ' << L.elem[i].count << ' ' << L.elem[i].price << endl;
	}
	Fileout.close();
	return;
}