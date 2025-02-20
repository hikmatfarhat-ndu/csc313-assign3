#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <map>
#include "map.h"
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"


TEST_CASE("check_next_prev", "1") {
	std::vector<std::pair<std::string, int>> v{ {"one",90},{"two",94},{"three",88},{"four",65} };
	map<std::string, double> m;
	for (auto& x : v)
		m.insert(x);
	std::string r1 = "";
	auto itr = m.begin(10);
	while (itr != m.end(10)) {
		r1 += itr->_myval.first;
		itr = m.next(itr);
	}
	/* sort */
	std::sort(v.begin(), v.end(), [](auto p, auto q) {return p.first < q.first; });
	std::string r2 = "";
	for (auto& x : v)
		r2 += x.first;

	REQUIRE(r1 == r2);

}

