#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include "map.h"
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"


TEST_CASE("check_insert_inorder", "0") {
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
TEST_CASE("check_erase_inorder", "0") {
	std::vector<std::pair<std::string, int>> v{ {"one",90},{"two",94},{"three",88},{"four",65} };
	map<std::string, double> m;
	for (auto& x : v)
		m.insert(x);
	m.erase("one");
	v.erase(v.begin());
	std::string r1 = m.inorder();
	std::sort(v.begin(), v.end(), [](auto p, auto q) {return p.first < q.first; });
	std::string r2 = "";
	for (auto& x : v) {
		r2 = r2 + x.first + "=>";
	}
	REQUIRE(r1 == r2);

}
//
//TEST_CASE("erasure", "1") {
//	std::vector<std::pair<std::string, double>> v{ { "student5", 90 },
//	{ "student2",92.4 },{ "student1",44 },{ "student4",54 },{ "student6",44 },
//	{ "student3",44 } };
//	::map<std::string, double> m;
//	for (auto& x : v)
//		m.insert(x);
//	m.erase("student5");
//	m.erase("student1");
//	m.insert({ "student7",84 });
//	m.insert({ "student8", 93 });
//	::map<std::string, double>::iterator itr = m.begin();
//	//append the keys from custom map in order to a vector r1
//	std::vector<std::string> r1;
//	while (itr != m.end()) {
//		r1.push_back((*itr).first);
//		++itr;
//	}
//
//	std::map<std::string, double> stdm;
//	for (auto& x : v)
//		stdm.insert(x);
//	stdm.erase("student5");
//	stdm.erase("student1");
//	stdm.insert({ "student7",84 });
//	stdm.insert({ "student8", 93 });
//	std::map<std::string, double>::iterator stditr = stdm.begin();
//	//append the keys from custom map in order to a vector r2   
//	std::vector<std::string> r2;
//	while (stditr != stdm.end()) {
//		r2.push_back((*stditr).first);
//		++stditr;
//	}
//
//
//	REQUIRE(r1 == r2);
//
//}


