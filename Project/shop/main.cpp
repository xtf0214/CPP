#include <iostream>
#include "shop.h"
int main()
{
	SqlList L;
	OrderSqlList O;
	int i = 0;
	int choose = -1;
	Goods e;
	OrderItem o;
	float total = 0;
	string hand_1, hand_2, hand_3, hand_4, hand_5;
	// cout << "**********************************************************************************************" << endl;
	// cout << "*                                   商品销售管理系统                                         *" << endl;
	// cout << "**********************************************************************************************" << endl;
	// cout << "*                                                                                            *" << endl;
	// cout << "*                   1.初始化            2.录入商品信息         3.商品查询                    * " << endl;
	// cout << "*              4.商品上架         5.商品销售      6.浏览全部商品         7.退出              *" << endl;
	// cout << "**********************************************************************************************" << endl;
	
	cout << "*                                   Commodity sales management system                                         *" << endl;
	cout << "**********************************************************************************************" << endl;
	cout << "*                                                                                            *" << endl;
	cout << "*                   1.initialization            2.Enter product information         3.Product query                    * " << endl;
	cout << "*              4.Goods on the shelves         5.Commodity sales      6.Browse all products         7.quit              *" << endl;
	cout << "**********************************************************************************************" << endl;
	while (choose != 0)
	{
		cout << "Please enter an action item{0---7}:";
		cin >> choose;
		switch (choose)
		{
		case 1: //创建链表
		{
			if (InitListSq(L) && InitOListSq(O))
			{
				cout << "Initialization successful!" << endl;
			}
			else
			{
				cout << "initialization failed!" << endl;
			}
			break;
		}
		case 2: //录入链表信息
		{
			int i = 0;
			L.elem = new Goods[MAXSIZE];
			if (!L.elem)
			{
				exit(OVERFLOW0);
			}
			L.length = 0;

			fstream FilePtr;
			FilePtr.open("d:/goods.txt");
			if (FilePtr)
			{
				cout << "File read failed!" << endl;
				exit(ERROR0);
			}

			FilePtr >> hand_1 >> hand_2 >> hand_3 >> hand_4 >> hand_5; //跳过表头
			while (!FilePtr.eof())
			{
				FilePtr >> L.elem[i].id >> L.elem[i].name >> L.elem[i].price >> L.elem[i].producer >> L.elem[i].store;
				i++;
			}
			cout << "Information imported successfully!" << endl;
			L.length = i;
			FilePtr.close();
			break;
		}
		case 3: //查找
		{
			string name;
			cout << "Please enter the product name you are looking for:";
			cin >> name;
			int index = Find_Name(L, name);
			if (index >= 0)
			{
				cout << "Item number found:" << L.elem[index].id << ",name:" << L.elem[index].name << ",price" << L.elem[index].price << ",Manufacturer:" << L.elem[index].producer << ", Inventory:" << L.elem[index].store << endl;
			}
			else
			{
				cout << "Find does not exist!" << endl;
			}
			break;
		}
		case 4: //新增商品
		{
			string id, name, pr;
			float p;
			int s;
			cout << "请输入商品编号:";
			cin >> id;
			cout << "请输入商品名称:";
			cin >> name;
			cout << "请输入商品单价:";
			cin >> p;
			cout << "请输入生产商:";
			cin >> pr;
			cout << "请输入库存:";
			cin >> s;
			e.id = id;
			e.name = name;
			e.price = p;
			e.producer = pr;
			e.store = s;
			int state = ListInsert(L, e);
			if (state == ERROR2)
			{
				cout << "存储位置已满，上架商品失败!" << endl;
			}
			else
			{
				cout << "新增商品成功!" << endl;
			}
			break;
		}
		case 5:
		{
			string buy;
			while (buy != "n")
			{
				string id;
				int c;
				cout << "请输入要购买的商品编号:";
				cin >> id;
				cout << "请输入要购买的商品数量:";
				cin >> c;
				if (ListUpdate(L, id, c))
				{
					cout << "购买成功!" << endl;
				}
				int index = locateElem_Sq(L, id);
				if (index >= 0)
				{
					cout << "商品编号:" << L.elem[index].id << ",名称:" << L.elem[index].name << ",价格:" << L.elem[index].price << ",生产商:" << L.elem[index].producer << "，库存量:" << L.elem[index].store << endl;
				}
				else
				{
					cout << "查找不存在!" << endl;
				}
				o.id = id;
				o.name = L.elem[index].name;
				o.price = L.elem[index].price;
				o.count = c;
				int state = ListOInsert(O, o);
				if (state == ERROR2)
				{
					cout << "存储位置已满，添加订单失败!" << endl;
				}
				else
				{
					cout << "加入订单成功!" << endl;
					total += o.price * o.count;
					cout << "**********************************************************************************************" << endl;
					cout << "总价:" << total << endl;
					cout << "**********************************************************************************************" << endl;
					cout << "是否继续购买？(请输入:y/n)";
					cin >> buy;
				}
			}
			break;
		}
		case 6:
		{
			PrintAllGoods(L);
			cout << "打印完成!" << endl;
			break;
		}
		case 7:
		{
			cout << "**********************************************生成的销售单************************************" << endl;
			PrintOrder(O);
			cout << "需付总金额:" << total << endl;
			cout << "**********************************************************************************************" << endl;
			Save_Disk(L);
			Save_Order_Disk(O);
			cout << "感谢使用!!!" << endl;
			return 0;
		}
		}
	}
}