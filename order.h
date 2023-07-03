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
	int m_customers; //就餐人数
	int m_number;//订单号
	int m_time;//下单时间
	double m_price;//订单总价
	int menu_number;//菜号
	int menu_count;//数量
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

