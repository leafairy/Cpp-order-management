#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include "order.h"
#include "menu.h"
using namespace std;
int main()
{
	order od;
	od.init();
	od.showMenu();
	return 0;
}