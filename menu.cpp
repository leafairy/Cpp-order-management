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
	ofs << menuList.size() << endl; //��д��˵�����
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
	//���˵�
	string sel = "0";
	system("cls");
	cout << "\t\t\t**********��ӭ�����˵�����ϵͳ**********" << endl;
	cout << "\t\t\t����Խ������²���:" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             1   ����µĲ˵�             |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             2   ɾ��һ���˵�             |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             3   �޸����в˵�             |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             0   �˳�                     |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t��ѡ��0-3����";
	cin >> sel;
	while (sel != "0" && sel != "1" && sel != "2" && sel != "3")
	{
		cout << "\t\t\t���벻�Ϸ�,������ѡ��0-3����";
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
		cout << "\t\t**********************��ӭ������Ӳ˵�����*************************" << endl;
		cout << "\t\t��ǰ���в˵���" << endl;
		showAllDish();
		cout << endl;
		cout << "\t\t------------------" << endl;
		cout << "\t\t1 ��Ӳ˵���Ϣ" << endl;
		cout << "\t\t2 �������˵�" << endl;
		cout << "\t\t------------------" << endl;
		cout << "\t\t��ѡ��1-2����";
		string select;
		cin >> select;
		while (select != "1" && select != "2")
		{
			cout << "\t\t���벻�Ϸ�������������";
			cin >> select;
		}
		if (select == "1")
		{
			string flag = "1";
			while (flag == "1")
			{
				cout << "\t\t������˵���" << endl;
				cout << "\t\t�˵��ţ� ";
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
							cout << "\t\t�õ����Ѵ��ڣ����������룺 ";
							check = true;
							break;
						}
					}
				} while (check);
				cout << "\t\t������ ";
				cin >> m.m_name;
				cout << "\t\t�۸� ";
				cin >> m.m_price;
				cout << "\t\t�ɱ���";
				cin >> m.m_cost;
				menuList.push_back(m);
				writeFile();
				cout << "\n\t\t�ò˵���Ϣ��ӳɹ����Ƿ������ӣ���1 �� 0 ��" << endl;
				cout << "\t\t�����ѡ��0-1����";
				cin >> flag;
				while (flag != "0" && flag != "1")
				{
					cout << "\t\t���벻�Ϸ�,������ѡ��0-1����";
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
		cout << "\t\t***********************��ӭ����ɾ���˵���Ϣ����***********************" << endl;
		string sel = "0";
		cout << "\t\t-----------------" << endl;
		cout << "\t\t1 ѡ���ɾ�˺�" << endl;
		cout << "\t\t2 �������˵�" << endl;
		cout << "\t\t-----------------" << endl;
		cout << "\t\t�����ѡ��1-2��" << endl;
		cin >> sel;
		while (sel != "1" && sel != "2")
		{
			cout << "\t\t���벻�Ϸ�,������ѡ��1-2����";
			cin >> sel;
		}
		if (sel == "1")
		{
			int keyNum;
			bool flag = false;
			cout << "\t\t�������ɾ���ĵ��ţ� ";
			cin >> keyNum;
			for (vector<Menu>::iterator it = menuList.begin(); it != menuList.end(); ++it)
			{
				if (it->m_number == keyNum)
				{
					flag = true;
					cout << "\t\t��ɾ���Ĳ˵���Ϣ���£� " << endl;
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					cout << "\t\t";
					Menu::showHeader();
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					cout << "\t\t";
					it->showDishInfo();
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					cout << "\t\tȷ��ɾ������1 �� 0 ��" << endl;
					cout << "\t\t�����ѡ��0-1����";
					string ch = "0";
					cin >> ch;
					while (ch != "0" && ch != "1")
					{
						cout << "\t\t���벻�Ϸ�,������ѡ��0-1����";
						cin >> ch;
					}
					if (ch == "0") break;
					else
					{
						menuList.erase(it);
						writeFile();
						cout << "\t\tɾ���ɹ���" << endl;
						break;
					}
				}
			}
			if (!flag) cout << "\t\t���޴˺ţ��޷�ɾ����\n" << endl;
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
		cout << "\t\t***********************��ӭ�����޸Ĳ˵���Ϣ����***********************" << endl;
		string sel = "0";
		cout << "\t\t-----------------" << endl;
		cout << "\t\t1 �޸Ĳ˵�������Ϣ" << endl;
		cout << "\t\t2 �������˵�" << endl;
		cout << "\t\t-----------------" << endl;
		cout << "\t\t�����ѡ��1-2����";
		cin >> sel;
		while (sel != "1" && sel != "2")
		{
			cout << "\t\t���벻�Ϸ�,������ѡ��1-3����";
			cin >> sel;
		}

		if (sel == "1")
		{
			bool flag = false;
			int keyNum;
			cout << "\t\t��������޸Ĳ˵��ĵ��ţ�";
			cin >> keyNum;
			for (int i = 0; i < menuList.size(); i++)
			{
				if (menuList[i].m_number == keyNum)
				{
					flag = true;
					cout << "\t\t���޸Ĳ˵�������Ϣ���£�" << endl;
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					cout << "\t\t";
					Menu::showHeader();
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					cout << "\t\t";
					menuList[i].showDishInfo();
					cout << "\t\t-----------------------------------------------------------------------" << endl;

					Menu s = menuList[i];
					cout << "\t\t�������޸ĺ�ĵ��ţ�";
					bool check = false;
					do
					{
						check = false;
						cin >> s.m_number;
						for (int j = 0; j < menuList.size(); ++j)
						{
							if (s.m_number == menuList[j].m_number && i != j)
							{
								cout << "\t\t�õ����ѱ�¼�룬���������뵥�ţ�";
								check = true;
								break;
							}
						}
					} while (check);
					cout << "\t\t�������޸ĺ�Ĳ˺ţ�";
					cin >> s.m_number;
					cout << "\t\t�������޸ĺ�Ĳ�����";
					cin >> s.m_name;
					cout << "\t\t�������޸ĺ�ļ۸�";
					cin >> s.m_price;
					cout << "\t\t�������޸ĺ�ĳɱ���";
					cin >> s.m_cost;
					cout << "\t\t�Ƿ�ȷ���޸ģ���1 �� 0 ��" << endl;
					cout << "\t\t�����ѡ��0-1����";
					string ch = "0";
					cin >> ch;
					while (ch != "0" && ch != "1")
					{
						cout << "\t\t���벻�Ϸ�,������ѡ��0-1����";
						cin >> ch;
					}

					if (ch == "0") break;
					else
					{
						menuList[i] = s;
						cout << "\t\t�޸ĳɹ���" << endl;
						writeFile();
						break;
					}
				}
			}
			if (!flag) cout << "\t\t���޴˺ţ��޷��޸ģ�\n" << endl;
		}
		else
		{
			break;
		}
		cout << "\t\t";
		system("pause");
	}
}

