

#include <iostream>
#include <exception>
#include <vector>
#include <string>
#include "map.h"

int main()
{
	::map<std::string, int> m;
	m.insert({ "one",1 });
	m.insert({ "two",2 });
	m.insert({ "three",3 });
	m["four"] = 7;
	m["one"] = 11;

	Node<std::string,int>* h= m.begin(10);
	h = m.end(10);
	h = m.next(h);
	h = m.prev(h);
	::map<std::string, int>::iterator itr = m.begin();
	itr = m.end();

}


