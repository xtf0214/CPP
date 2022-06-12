#include "shop.h"
status InitListSq(SqlList &L)
{
	L.elem = new Goods[MAXSIZE];
	if (!L.elem)
	{
		exit(OVERFLOW0);
	} //内存申请失败，直接退出程序
	L.length = 0;
	return OK;
}; //初始化商品链表

status InitOListSq(OrderSqlList &L)
{
	L.elem = new OrderItem[MAXSIZE];
	if (!L.elem)
	{
		exit(OVERFLOW0); //内存申请失败，直接退出程序
	}
	L.length = 0;
	return OK;
}; //初始化order链表

int locateElem_Sq(SqlList &L, string e) //查询下标
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i].id == e) // id查询
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

status ListInsert(SqlList &L, Goods g) //商品上架，货物更新
{
	if (L.length == MAXSIZE)
		return ERROR2;
	L.elem[L.length] = g;
	++L.length;
	return OK;
}
status ListOInsert(OrderSqlList &L, OrderItem o) //添加至订单
{
	if (L.length == MAXSIZE)
		return ERROR2;
	L.elem[L.length] = o;
	++L.length;
	return OK;
}

int ListUpdate(SqlList &L, string id, int count) //修改商品库存，销售
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

void PrintAllGoods(SqlList &L) //打印商品
{
	for (int i = 0; i < L.length; i++)
	{
		cout << "商品编号：" << L.elem[i].id << ",名称：" << L.elem[i].name << ",价格：" << L.elem[i].price << ",生产商：" << L.elem[i].producer << ",库存数：" << L.elem[i].store << endl;
	}
}
void PrintOrder(OrderSqlList &L) //打印订单
{
	for (int i = 0; i < L.length; i++)
	{
		cout << "商品编号：" << L.elem[i].id << ",名称：" << L.elem[i].name << ",单价：" << L.elem[i].price << ",购买数量：" << L.elem[i].count << endl;
	}
}

void Save_Disk(SqlList &L) //保存goods文件
{
	fstream Fileout("c:/goods.txt", ios::out);
	if (!Fileout)
	{
		cout << "文件写入失败！" << endl;
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
		cout << "订单打印失败" << endl;
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