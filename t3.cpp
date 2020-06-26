#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include "map.h"
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"


TEST_CASE("check_indexing","1"){
	std::vector<std::pair<std::string,double>> v {{ "student5", 90 },
    { "student2",92.4 },{ "student1",44 },{ "student4",54 },{ "student6",44 },
    { "student3",44 }};
    map<std::string,double> m;
	for(auto& x:v)
		m.insert(x);
    map<std::string,double>::iterator itr = m.begin();
    m["student15"] = 3333;

     REQUIRE(m["student15"]==3333);
     

}

