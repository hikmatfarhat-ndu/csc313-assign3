

#include <iostream>
#include <exception>
#include <vector>
#include <string>
#include "map.h"
//#include <map>
//using namespace std;

int main()
{
	::map<int, int> m;
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
	::map<int, int>::iterator itr=m.begin(10);
	(*itr).second = 666;
	m[8] = 205;

	for (; itr != m.end(10); ++itr)
		std::cout << (*itr).first << "," << (*itr).second << std::endl;
	itr = m.begin(10);
	std::cout << "\n---------------\n";
	for (; itr != m.end(10); ++itr)
		std::cout << itr->first << "," << itr->second << std::endl;
	auto i = m.find(5);
	(++i)->second = 333;

	std::cout <<"\n"<< i->first << "," << i->second << std::endl;
}

