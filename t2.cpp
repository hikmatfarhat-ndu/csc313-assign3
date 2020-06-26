#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <map>
#include "map.h"
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"


TEST_CASE("erasure", "1") {
    std::vector<std::pair<std::string, double>> v{ { "student5", 90 },
    { "student2",92.4 },{ "student1",44 },{ "student4",54 },{ "student6",44 },
    { "student3",44 } };
    ::map<std::string, double> m;
    for (auto& x : v)
        m.insert(x);
    m.erase("student5");
    m.erase("student1");
    m.insert({ "student7",84 });
    m.insert({"student8", 93});
    ::map<std::string,double>::iterator itr = m.begin(10);
    //append the keys from custom map in order to a vector r1
    std::vector<std::string> r1;
    while (itr!=m.end(10)) {
        r1.push_back((*itr).first) ;
        ++itr;
    }

    std::map<std::string, double> stdm;
    for (auto& x : v)
        stdm.insert(x);
   stdm.erase("student5");
    stdm.erase("student1");
    stdm.insert({ "student7",84 });
    stdm.insert({ "student8", 93 });
    std::map<std::string, double>::iterator stditr = stdm.begin();
    //append the keys from custom map in order to a vector r2   
    std::vector<std::string> r2;
    while (stditr != stdm.end()) {
        r2.push_back((*stditr).first);
        ++stditr;
    }


     REQUIRE(r1==r2);

}

