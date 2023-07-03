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
	cout << left << setw(12) << "����";
	cout << left << setw(10) << "ʱ��";
	cout << left << setw(6) << "����";
	cout << left << setw(8) << "�ܼ�";
	cout << left << setw(23) << "�˺�";
	cout << left << setw(6) << "����" << endl;
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
	ofs << ordList.size() << endl; //��д�붩������
	for (int i = 0; i < ordList.size(); i++)
	{
		ofs << ordList[i].m_number << " " << ordList[i].m_time << " " << ordList[i].m_customers
			<< " " << ordList[i].m_price << " " << ordList[i].menu_number << " " << ordList[i].menu_count << endl;
	}
	ofs.close();
}

void order::showMenu()
{
//���˵�
		string sel = "0";
		system("cls");
		cout << "\t\t\t**********��ӭ������������ϵͳ**********" << endl;
		cout << "\t\t\t����Խ������²���:" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             1   ��Ӷ�����Ϣ             |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             2   ɾ��������Ϣ             |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             3   �޸Ķ�����Ϣ             |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             4   ��ѯ������Ϣ             |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             5   ����˵�����             |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             6   ͳ��Ӫ������             |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             7   ���ϵͳ����             |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t|             0   �˳�                     |" << endl;
		cout << "\t\t\t|------------------------------------------|" << endl;
		cout << "\t\t\t��ѡ��0-7����";
		cin >> sel;
		while (sel != "0" && sel != "1" && sel != "2" && sel != "3" && sel != "4" && sel != "5" && sel != "6" && sel != "7")
		{
			cout << "\t\t\t���벻�Ϸ�,������ѡ��0-7����";
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
		cout << "\t\t**********************��ӭ������Ӷ�������*************************" << endl;
		cout << "\t\t��ǰ���ж�����" << endl;
		showAllList();
		cout << endl;
		cout << "\t\t------------------" << endl;
		cout << "\t\t1 ��Ӷ�����Ϣ" << endl;
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
			while (flag=="1")
			{
				cout << "\t\t�����붩����" << endl;
				cout << "\t\t�����ţ� ";
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
							cout << "\t\t�õ����Ѵ��ڣ����������룺 ";
							check = true;
							break;
						}
					}
				} while (check);
				cout << "\t\t�µ�ʱ�䣺 ";
				cin >> o.m_time;
				cout << "\t\t�Ͳ������� ";
				cin >> o.m_customers;
				cout << "\t\t�����ܼۣ� ";
				cin >> o.m_price;
				cout << "\t\t�˺ţ� ";
				cin >> o.menu_number;
				cout << "\t\t������";
				cin >> o.menu_count;
				ordList.push_back(o);
				writeFile();
				cout << "\n\t\t�ö�����Ϣ��ӳɹ����Ƿ������ӣ���1 �� 0 ��" << endl;
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

void order::deleteList()
{
	while (true)
	{
		system("cls");
		cout << "\t\t***********************��ӭ����ɾ��������Ϣ����***********************" << endl;
		string sel = "0";
		cout << "\t\t-----------------" << endl;
		cout << "\t\t1 ������ɾ��" << endl;
		cout << "\t\t2 ��ʱ��ɾ��" << endl;
		cout << "\t\t3 �������˵�" << endl;
		cout << "\t\t-----------------" << endl;
		cout << "\t\t�����ѡ��1-3��" << endl;
		cin >> sel;
		while (sel != "1" && sel != "2" && sel != "3")
		{
			cout << "\t\t���벻�Ϸ�,������ѡ��1-3����";
			cin >> sel;
		}
		if (sel == "1")
		{
			int keyNum;
			bool flag = false;
			cout << "\t\t�������ɾ���ĵ��ţ� ";
			cin >> keyNum;
			for (vector<order>::iterator it = ordList.begin(); it != ordList.end(); ++it)
			{
				if (it->m_number == keyNum)
				{
					flag = true;
					cout << "\t\t��ɾ���Ķ�����Ϣ���£� " << endl;
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					cout << "\t\t";
					order::showHeader();
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					cout << "\t\t";
					it->showListInfo();
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
						ordList.erase(it);
						writeFile();
						cout << "\t\tɾ���ɹ���" << endl;
						break;
					}
				}
			}
			if (!flag) cout << "\t\t���޴˵����޷�ɾ����\n" << endl;
			cout << "\t\t";
			system("pause");
		}
		else if (sel == "2")
		{
			int keyTime;
			bool flag = false;
			cout << "\t\t�������ɾ��������ʱ�䣺";
			cin >> keyTime;
			for (vector<order>::iterator it = ordList.begin(); it != ordList.end(); ++it)
			{
				if (it->m_time == keyTime)
				{
					flag = true;
					cout << "\t\t��ɾ�����ŵ���Ϣ���£�" << endl;
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					cout << "\t\t\t";
					order::showHeader();
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					cout << "\t\t";
					it->showListInfo();
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
						ordList.erase(it);
						writeFile();
						cout << "\t\tɾ���ɹ���" << endl;
						break;
					}
				}
			}
			if (!flag) cout << "\t\t���޴˵����޷�ɾ����\n" << endl;
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
		cout << "\t\t***********************��ӭ�����޸Ķ�����Ϣ����***********************" << endl;
		string sel = "0";
		cout << "\t\t-----------------" << endl;
		cout << "\t\t1 �޸Ķ���������Ϣ" << endl;
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
			cout << "\t\t��������޸Ķ����ĵ��ţ�";
			cin >> keyNum;
			for (int i = 0; i < ordList.size(); i++)
			{
				if (ordList[i].m_number == keyNum)
				{
					flag = true;
					cout << "\t\t���޸Ķ���������Ϣ���£�" << endl;
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					cout << "\t\t";
					order::showHeader();
					cout << "\t\t-----------------------------------------------------------------------" << endl;
					cout << "\t\t";
					ordList[i].showListInfo();
					cout << "\t\t-----------------------------------------------------------------------" << endl;

					order s = ordList[i];
					cout << "\t\t�������޸ĺ�ĵ��ţ�";
					bool check = false;
					do
					{
						check = false;
						cin >> s.m_number;
						for (int j = 0; j < ordList.size(); ++j)
						{
							if (s.m_number == ordList[j].m_number && i != j)
							{
								cout << "\t\t�õ����ѱ�¼�룬���������뵥�ţ�";
								check = true;
								break;
							}
						}
					} while (check);
					cout << "\t\t�������޸ĺ��ʱ�䣺";
					cin >> s.m_time;
					cout << "\t\t�������޸ĺ�ľͲ�������";
					cin >> s.m_customers;
					cout << "\t\t�������޸ĺ���ܼۣ�";
					cin >> s.m_price;
					cout << "\t\t�������޸ĺ�Ĳ˺ţ�";
					cin >> s.menu_number;
					cout << "\t\t�������޸ĺ��������";
					cin >> s.menu_count;
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
						ordList[i] = s;
						cout << "\t\t�޸ĳɹ���" << endl;
						writeFile();
						break;
					}
				}
			}
			if (!flag) cout << "\t\t���޴��ˣ��޷��޸ģ�\n" << endl;
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
		cout << "\t\t**************��ӭ�������ϵͳ���ݹ���***************" << endl;
		cout << "\t\t------------------" << endl;
		cout << "\t\t1 ȷ�����ϵͳ����" << endl;
		cout << "\t\t2 �������˵�" << endl;
		cout << "\t\t------------------" << endl;
		cout << "\t\t������ѡ��1-2����";
		cin >> sel;
		while (sel != "1" && sel != "2")
		{
			cout << "\t\t���벻�Ϸ�,���������롾1-2����";
			cin >> sel;
		}
		if (sel == "1")
		{
			ordList.clear();
			cout << "\t\t��ճɹ���" << endl;
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
	cout << "\t\t\t�ܼ�����" << sum << "Ԫ" << endl;
	system("pause");
}
