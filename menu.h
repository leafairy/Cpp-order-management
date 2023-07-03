#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;
class Menu
{
private:
	vector<Menu> menuList;
public:
	Menu(int m_number,string m_name,double m_price,double m_cost) {
		this->m_number = m_number;
		this->m_name = m_name;
		this->m_price = m_price;
		this->m_cost = m_cost;
	}

	Menu() {}
	//菜号、菜名、价格、成本
	int m_number;
	string m_name;
	double m_price;
	double m_cost;
	void readFile();
	void writeFile();
	void showAllDish();
	void showHeader();
	void showDishInfo();
	void showMenu();
	void insertDish();
	void deleteDish();
	void updateDish();
	~Menu() {}
};

