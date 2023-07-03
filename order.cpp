#include "order.h"
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <iomanip>
#include "menu.h"
void order::init()
{
	readFile();
}

void order::showHeader()
{
	cout << left << setw(12) << "单号";
	cout << left << setw(10) << "时间";
	cout << left << setw(6) << "人数";
	cout << left << setw(8) << "总价";
	cout << left << setw(23) << "菜号";
	cout << left << setw(6) << "数量" << endl;
}

void order::showListInfo()
{
	cout << left << setw(12) << m_number;
	cout << left << setw(10) << m_time;
	cout << left << setw(6) << m_customers;
	cout << left << setw(8) << m_price;
	cout << left << setw(23) << menu_number;
	cout << left << setw(6) << menu_count << endl;
}

void order::showAllList()
{
	system("cls");
	cout << "\t\t-----------------------------------------------------------------------" << endl;
	cout << "\t\t";
	order::showHeader();
	cout << "\t\t-----------------------------------------------------------------------" << endl;
	for (int i = 0; i < ordList.size(); i++)
	{
		cout << "\t\t";
		ordList[i].showListInfo();
	}
	cout << "\t\t-----------------------------------------------------------------------" << endl;
	cout << "\t\t";
	system("pause");
}

void order::readFile()
{
	ifstream ifs;
	ifs.open("ordList.txt", ios::out);
	int n = 0;
	ifs >> n;
	for (int i = 0; i < n; i++)
	{
		order o;
		ifs >> o.m_number >> o.m_time >> o.m_customers >> o.m_price >> o.menu_number >> o.menu_count;
		ordList.push_back(o);
	}
	ifs.close();
}

void order::writeFile() 
{
	ofstream ofs;
	ofs.open("ordList.txt", ios::out);
	ofs << ordList.size() << endl; //先写入订单数量
	for (int i = 0; i < ordList.size(); i++)
	{
		ofs << ordList[i].m_number << " " << ordList[i].m_time << " " << ordList[i].m_customers
			<< " " << ordList[i].m_price << " " << ordList[i].menu_number << " " << ordList[i].menu_count << endl;
	}
	ofs.close();
}

void order::showMenu()
{
//主菜单
		string sel = "0";
		system("cls");
		cout << "\t\t\t**********欢迎来到订单管理系统**********" << endl;
		cout << "\t\t\t你可以进行以下操作:" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             1   添加订单信息             |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             2   删除订单信息             |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             3   修改订单信息             |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             4   查询订单信息             |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             5   进入菜单管理             |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             6   统计营收数据             |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             7   清空系统数据             |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             0   退出                     |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t请选择【0-7】：";
		cin >> sel;
		while (sel != "0" && sel != "1" && sel != "2" && sel != "3" && sel != "4" && sel != "5" && sel != "6" && sel != "7")
		{
			cout << "\t\t\t输入不合法,请重新选择【0-7】：";
			cin >> sel;
		}
		if (sel == "1")
		{
			this->insertList();
			this->showMenu();
		}
		else if (sel == "2")
		{
			this->deleteList();
			this->showMenu();
		}
		else if (sel == "3")
		{
			this->updateList();
			this->showMenu();
		}
		else if (sel == "4")
		{
			showAllList();
			this->showMenu();
		}
		else if (sel == "5")
		{
			Menu m;
			m.showMenu();
			this->showMenu();
		}
		else if (sel == "6")
		{
			this->sumProfits();
			this->showMenu();
		}
		else if (sel == "7")
		{
			this->clearList();
			this->showMenu();
		}
		else if (sel == "0")
		{
			exit(0);
		}
}

void order::insertList()
{
	while (true)
	{
		system("cls");
		cout << "\t\t**********************欢迎来到添加订单功能*************************" << endl;
		cout << "\t\t当前已有订单：" << endl;
		showAllList();
		cout << endl;
		cout << "\t\t------------------" << endl;
		cout << "\t\t1 添加订单信息" << endl;
		cout << "\t\t2 返回主菜单" << endl;
		cout << "\t\t------------------" << endl;
		cout << "\t\t请选择【1-2】：";
		string select;
		cin >> select;
		while (select != "1" && select != "2")
		{
			cout << "\t\t输入不合法，请重新输入";
			cin >> select;
		}
		if (select == "1")
		{
			string flag = "1";
			while (flag=="1")
			{
				cout << "\t\t请输入订单号" << endl;
				cout << "\t\t订单号： ";
				order o;
				bool check = false;
				do
				{
					check = false;
					cin >> o.m_number;
					for (int i = 0; i < o.ordList.size(); i++)
					{
						if (o.m_number == ordList[i].m_number)
						{
							cout << "\t\t该单号已存在，请重新输入： ";
							check = true;
							break;
						}
					}
				} while (check);
				cout << "\t\t下单时间： ";
				cin >> o.m_time;
				cout << "\t\t就餐人数： ";
				cin >> o.m_customers;
				cout << "\t\t订单总价： ";
				cin >> o.m_price;
				cout << "\t\t菜号： ";
				cin >> o.menu_number;
				cout << "\t\t数量：";
				cin >> o.menu_count;
				ordList.push_back(o);
				writeFile();
				cout << "\n\t\t该订单信息添加成功！是否继续添加？（1 是 0 否）" << endl;
				cout << "\t\t请进行选择【0-1】：";
				cin >> flag;
				while (flag != "0" && flag != "1")
				{
					cout << "\t\t输入不合法,请重新选择【0-1】：";
					cin >> flag;
				}
			}
			cout << "\t\t";
			system("pause");
		}
		else
		{
			break;
		}
	}
}

void order::deleteList()
{
	while (true)
	{
		system("cls");
		cout << "\t\t***********************欢迎来到删除订单信息功能***********************" << endl;
		string sel = "0";
		cout << "\t\t-----------------" << endl;
		cout << "\t\t1 按单号删除" << endl;
		cout << "\t\t2 按时间删除" << endl;
		cout << "\t\t3 返回主菜单" << endl;
		cout << "\t\t-----------------" << endl;
		cout << "\t\t请进行选择【1-3】" << endl;
		cin >> sel;
		while (sel != "1" && sel != "2" && sel != "3")
		{
			cout << "\t\t输入不合法,请重新选择【1-3】：";
			cin >> sel;
		}
		if (sel == "1")
		{
			int keyNum;
			bool flag = false;
			cout << "\t\t请输入待删除的单号： ";
			cin >> keyNum;
			for (vector<order>::iterator it = ordList.begin(); it != ordList.end(); ++it)
			{
				if (it->m_number == keyNum)
				{
					flag = true;
					cout << "\t\t待删除的订单信息如下： " << endl;
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					cout << "\t\t";
					order::showHeader();
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					cout << "\t\t";
					it->showListInfo();
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					cout << "\t\t确认删除？（1 是 0 否）" << endl;
					cout << "\t\t请进行选择【0-1】：";
					string ch = "0";
					cin >> ch;
					while (ch != "0" && ch != "1")
					{
						cout << "\t\t输入不合法,请重新选择【0-1】：";
						cin >> ch;
					}
					if (ch == "0") break;
					else
					{
						ordList.erase(it);
						writeFile();
						cout << "\t\t删除成功！" << endl;
						break;
					}
				}
			}
			if (!flag) cout << "\t\t查无此单，无法删除！\n" << endl;
			cout << "\t\t";
			system("pause");
		}
		else if (sel == "2")
		{
			int keyTime;
			bool flag = false;
			cout << "\t\t请输入待删除订单的时间：";
			cin >> keyTime;
			for (vector<order>::iterator it = ordList.begin(); it != ordList.end(); ++it)
			{
				if (it->m_time == keyTime)
				{
					flag = true;
					cout << "\t\t待删除单号的信息如下：" << endl;
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					cout << "\t\t\t";
					order::showHeader();
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					cout << "\t\t";
					it->showListInfo();
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					cout << "\t\t确认删除？（1 是 0 否）" << endl;
					cout << "\t\t请进行选择【0-1】：";
					string ch = "0";
					cin >> ch;
					while (ch != "0" && ch != "1")
					{
						cout << "\t\t输入不合法,请重新选择【0-1】：";
						cin >> ch;
					}
					if (ch == "0") break;
					else
					{
						ordList.erase(it);
						writeFile();
						cout << "\t\t删除成功！" << endl;
						break;
					}
				}
			}
			if (!flag) cout << "\t\t查无此单，无法删除！\n" << endl;
			cout << "\t\t";
			system("pause");
		}
		else
		{
			break;
		}
	}

}

void order::updateList()
{
	while (true)
	{
		system("cls");
		cout << "\t\t***********************欢迎来到修改订单信息功能***********************" << endl;
		string sel = "0";
		cout << "\t\t-----------------" << endl;
		cout << "\t\t1 修改订单基本信息" << endl;
		cout << "\t\t2 返回主菜单" << endl;
		cout << "\t\t-----------------" << endl;
		cout << "\t\t请进行选择【1-2】：";
		cin >> sel;
		while (sel != "1" && sel != "2")
		{
			cout << "\t\t输入不合法,请重新选择【1-3】：";
			cin >> sel;
		}

		if (sel == "1")
		{
			bool flag = false;
			int keyNum;
			cout << "\t\t请输入待修改订单的单号：";
			cin >> keyNum;
			for (int i = 0; i < ordList.size(); i++)
			{
				if (ordList[i].m_number == keyNum)
				{
					flag = true;
					cout << "\t\t待修改订单基本信息如下：" << endl;
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					cout << "\t\t";
					order::showHeader();
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					cout << "\t\t";
					ordList[i].showListInfo();
					cout << "\t\t-----------------------------------------------------------------------" << endl;

					order s = ordList[i];
					cout << "\t\t请输入修改后的单号：";
					bool check = false;
					do
					{
						check = false;
						cin >> s.m_number;
						for (int j = 0; j < ordList.size(); ++j)
						{
							if (s.m_number == ordList[j].m_number && i != j)
							{
								cout << "\t\t该单号已被录入，请重新输入单号：";
								check = true;
								break;
							}
						}
					} while (check);
					cout << "\t\t请输入修改后的时间：";
					cin >> s.m_time;
					cout << "\t\t请输入修改后的就餐人数：";
					cin >> s.m_customers;
					cout << "\t\t请输入修改后的总价：";
					cin >> s.m_price;
					cout << "\t\t请输入修改后的菜号：";
					cin >> s.menu_number;
					cout << "\t\t请输入修改后的数量：";
					cin >> s.menu_count;
					cout << "\t\t是否确认修改？（1 是 0 否）" << endl;
					cout << "\t\t请进行选择【0-1】：";
					string ch = "0";
					cin >> ch;
					while (ch != "0" && ch != "1")
					{
						cout << "\t\t输入不合法,请重新选择【0-1】：";
						cin >> ch;
					}

					if (ch == "0") break;
					else
					{
						ordList[i] = s;
						cout << "\t\t修改成功！" << endl;
						writeFile();
						break;
					}
				}
			}
			if (!flag) cout << "\t\t查无此人，无法修改！\n" << endl;
		}
		else
		{
			break;
		}
		cout << "\t\t";
		system("pause");
	}
}

void order::clearList()
{
	while (true)
	{
		string sel = "0";
		system("cls");
		cout << "\t\t**************欢迎来到清空系统数据功能***************" << endl;
		cout << "\t\t------------------" << endl;
		cout << "\t\t1 确认清空系统数据" << endl;
		cout << "\t\t2 返回主菜单" << endl;
		cout << "\t\t------------------" << endl;
		cout << "\t\t请慎重选择【1-2】：";
		cin >> sel;
		while (sel != "1" && sel != "2")
		{
			cout << "\t\t输入不合法,请重新输入【1-2】：";
			cin >> sel;
		}
		if (sel == "1")
		{
			ordList.clear();
			cout << "\t\t清空成功！" << endl;
			cout << "\t\t";
			system("pause");
			writeFile();
		}
		else
		{
			break;
		}
	}

}

void order::sumProfits()
{
	system("cls");
	double sum = 0;
	for (vector<order>::iterator it = ordList.begin(); it < ordList.end(); ++it)
	{
		sum += it->m_price;
	}
	cout << "\t\t\t总计卖出" << sum << "元" << endl;
	system("pause");
}
