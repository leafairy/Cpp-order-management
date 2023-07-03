#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;
class order
{
private:
	vector<order> ordList;
	
public:
	int m_customers; //�Ͳ�����
	int m_number;//������
	int m_time;//�µ�ʱ��
	double m_price;//�����ܼ�
	int menu_number;//�˺�
	int menu_count;//����
	order() {};
	order(int m_customers, int m_number, int m_time, double m_price, int menu_number, int menu_count)
	{
		this->m_customers = m_customers;
		this->m_number = m_number;
		this->m_time = m_time;
		this->m_price = m_price;
		this->menu_number = menu_number;
		this->menu_count = menu_count;
	}
	~order() {};
	void init();
	void showMenu();
	void insertList();
	void showAllList();
	void showHeader();
	void readFile();
	void writeFile();
	void deleteList();
	void updateList();
	void showListInfo();
	void clearList();
	void sumProfits();
};

