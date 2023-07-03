#include "menu.h"

void Menu::readFile()
{
	ifstream ifs;
	ifs.open("Menu.txt", ios::out);
	int n = 0;
	ifs >> n;
	for (int i = 0; i < n; i++)
	{
		Menu m;
		ifs >> m.m_number >> m.m_name >> m.m_price >> m.m_cost;
		menuList.push_back(m);
	}
	ifs.close();
}

void Menu::writeFile()
{
	ofstream ofs;
	ofs.open("Menu.txt", ios::out);
	ofs << menuList.size() << endl; //先写入菜单数量
	for (int i = 0; i < menuList.size(); i++)
	{
		ofs << menuList[i].m_number << " " << menuList[i].m_name << " " << menuList[i].m_price << " " << menuList[i].m_cost << endl;
	}
	ofs.close();
}

void Menu::showAllDish()
{

}

void Menu::showHeader()
{

}

void Menu::showDishInfo()
{

}

void Menu::showMenu()
{
	//主菜单
	string sel = "0";
	system("cls");
	cout << "\t\t\t**********欢迎来到菜单管理系统**********" << endl;
	cout << "\t\t\t你可以进行以下操作:" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             1   添加新的菜单             |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             2   删除一个菜单             |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             3   修改已有菜单             |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             0   退出                     |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t请选择【0-3】：";
	cin >> sel;
	while (sel != "0" && sel != "1" && sel != "2" && sel != "3")
	{
		cout << "\t\t\t输入不合法,请重新选择【0-3】：";
		cin >> sel;
	}
	if (sel == "1")
	{
		this->insertDish();
		this->showMenu();
	}
	else if (sel == "2")
	{
		this->deleteDish();
		this->showMenu();
	}
	else if (sel == "3")
	{
		this->updateDish();
		this->showMenu();
	}
	else if (sel == "0")
	{
		exit(0);
	}
}

void Menu::insertDish()
{
	while (true)
	{
		system("cls");
		cout << "\t\t**********************欢迎来到添加菜单功能*************************" << endl;
		cout << "\t\t当前已有菜单：" << endl;
		showAllDish();
		cout << endl;
		cout << "\t\t------------------" << endl;
		cout << "\t\t1 添加菜单信息" << endl;
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
			while (flag == "1")
			{
				cout << "\t\t请输入菜单号" << endl;
				cout << "\t\t菜单号： ";
				Menu m;
				bool check = false;
				do
				{
					check = false;
					cin >> m.m_number;
					for (int i = 0; i < m.menuList.size(); i++)
					{
						if (m.m_number == menuList[i].m_number)
						{
							cout << "\t\t该单号已存在，请重新输入： ";
							check = true;
							break;
						}
					}
				} while (check);
				cout << "\t\t菜名： ";
				cin >> m.m_name;
				cout << "\t\t价格： ";
				cin >> m.m_price;
				cout << "\t\t成本：";
				cin >> m.m_cost;
				menuList.push_back(m);
				writeFile();
				cout << "\n\t\t该菜单信息添加成功！是否继续添加？（1 是 0 否）" << endl;
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

void Menu::deleteDish()
{
	while (true)
	{
		system("cls");
		cout << "\t\t***********************欢迎来到删除菜单信息功能***********************" << endl;
		string sel = "0";
		cout << "\t\t-----------------" << endl;
		cout << "\t\t1 选择待删菜号" << endl;
		cout << "\t\t2 返回主菜单" << endl;
		cout << "\t\t-----------------" << endl;
		cout << "\t\t请进行选择【1-2】" << endl;
		cin >> sel;
		while (sel != "1" && sel != "2")
		{
			cout << "\t\t输入不合法,请重新选择【1-2】：";
			cin >> sel;
		}
		if (sel == "1")
		{
			int keyNum;
			bool flag = false;
			cout << "\t\t请输入待删除的单号： ";
			cin >> keyNum;
			for (vector<Menu>::iterator it = menuList.begin(); it != menuList.end(); ++it)
			{
				if (it->m_number == keyNum)
				{
					flag = true;
					cout << "\t\t待删除的菜单信息如下： " << endl;
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					cout << "\t\t";
					Menu::showHeader();
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					cout << "\t\t";
					it->showDishInfo();
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
						menuList.erase(it);
						writeFile();
						cout << "\t\t删除成功！" << endl;
						break;
					}
				}
			}
			if (!flag) cout << "\t\t查无此号，无法删除！\n" << endl;
			cout << "\t\t";
			system("pause");
		}
		else
		{
			break;
		}
	}

}

void Menu::updateDish()
{
	while (true)
	{
		system("cls");
		cout << "\t\t***********************欢迎来到修改菜单信息功能***********************" << endl;
		string sel = "0";
		cout << "\t\t-----------------" << endl;
		cout << "\t\t1 修改菜单基本信息" << endl;
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
			cout << "\t\t请输入待修改菜单的单号：";
			cin >> keyNum;
			for (int i = 0; i < menuList.size(); i++)
			{
				if (menuList[i].m_number == keyNum)
				{
					flag = true;
					cout << "\t\t待修改菜单基本信息如下：" << endl;
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					cout << "\t\t";
					Menu::showHeader();
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					cout << "\t\t";
					menuList[i].showDishInfo();
					cout << "\t\t-----------------------------------------------------------------------" << endl;

					Menu s = menuList[i];
					cout << "\t\t请输入修改后的单号：";
					bool check = false;
					do
					{
						check = false;
						cin >> s.m_number;
						for (int j = 0; j < menuList.size(); ++j)
						{
							if (s.m_number == menuList[j].m_number && i != j)
							{
								cout << "\t\t该单号已被录入，请重新输入单号：";
								check = true;
								break;
							}
						}
					} while (check);
					cout << "\t\t请输入修改后的菜号：";
					cin >> s.m_number;
					cout << "\t\t请输入修改后的菜名：";
					cin >> s.m_name;
					cout << "\t\t请输入修改后的价格：";
					cin >> s.m_price;
					cout << "\t\t请输入修改后的成本：";
					cin >> s.m_cost;
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
						menuList[i] = s;
						cout << "\t\t修改成功！" << endl;
						writeFile();
						break;
					}
				}
			}
			if (!flag) cout << "\t\t查无此号，无法修改！\n" << endl;
		}
		else
		{
			break;
		}
		cout << "\t\t";
		system("pause");
	}
}

