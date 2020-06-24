#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include "map.h"
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"


TEST_CASE("Test0", "0") {
	std::vector<std::pair<std::string,int>> v { {"one",90},{"two",94},{"three",88},{"four",65}};
	map<std::string,double> m;
	for(auto& x:v)
		m.insert(x);	
	std::string r1=m.inorder();
	std::sort(v.begin(),v.end(),[](auto p,auto q){return p.first<q.first;});
	std::string r2="";
	for(auto& x:v){
		r2=r2+x.first+"=>";
	}
	REQUIRE(r1==r2);

}
