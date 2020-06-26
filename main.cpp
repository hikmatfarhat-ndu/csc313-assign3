

#include <iostream>
#include <exception>
#include <vector>
#include <string>
#include "map.h"
//#include <map>
//using namespace std;

int main()
{
	{::map<int, int> m;
	m.insert({ 10,1 });
	m.insert({ 20,2 });
	m.insert({ 15,3 });
	m.insert({ 17,4 });
	m.insert({ 25,5 });
	m.insert({ 5,5 });
	m.insert({ 8,3 });
	m.insert({ 2,3 });
	m.erase(20);
	m.erase(15);
	m.erase(10);
	::map<int, int>::iterator itr = m.begin();
	(*itr).second = 666;
	m[8] = 205;

	for (; itr != m.end(); ++itr)
		std::cout << (*itr).first << "," << (*itr).second << std::endl;
	itr = m.begin();
	std::cout << "\n---------------\n";
	for (; itr != m.end(); ++itr)
		std::cout << itr->first << "," << itr->second << std::endl;
	auto i = m.find(5);
	(++i)->second = 333;

	std::cout << "\n" << i->first << "," << i->second << std::endl;
	}


	{
		std::vector<std::pair<std::string, int>> v
		{ {"one",90},{"two",94},{"three",88},{"four",65},{"ty",60}
		,{"tz",80 },{"ty",90} };
		map<std::string, double> m;
		//checks if insert is implemented
		for (auto& x : v)
			m.insert(x);
		//tests using inorder
		m.erase("two");
		v.erase(v.begin() + 1);
		std::string r1 = m.inorder();
		std::sort(v.begin(), v.end(), [](auto p, auto q) {return p.first < q.first; });
		std::string r2 = "";
		for (auto& x : v) {
			r2 = r2 + x.first + "=>";
		}
		std::cout << "done\n ";
	}
	{	map<std::string, double> m;
		m.insert({ "one",1 });
		m.erase("one");
		m.erase("one");
		std::string s = m.inorder();
		std::cout << s << std::endl;
	}
}

