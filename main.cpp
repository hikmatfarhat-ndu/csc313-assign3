

#include <iostream>
#include <exception>
#include <vector>
#include <string>
#include "map.h"
//using namespace std;

int main()
{
	::map<std::string, int> m;
	Node<std::string,int>* h= m.begin();
	h = m.end();
	h = m.next(h);
	h = m.prev(h);
	::map<std::string, int>::iterator itr = m.begin(10);
	itr = m.end(10);
}

