

#include <iostream>
#include <exception>
#include <vector>
#include <string>
#include "map.h"
//using namespace std;

int main(int argc, const char* argv[])
{
    std::vector<std::pair<std::string, double>> v{ { "student5", 90 },
    { "student2",92.4 },{ "student1",44 },{ "student4",54 },{ "student6",44 },
    { "student3",44 } };
    map<std::string, double> m;
    for (auto& x : v)
        m.insert(x);
    map<std::string, double>::iterator itr = m.begin(10);
    std::vector<std::string> r1;
    while (itr != m.end(10)) {
        r1.push_back((*itr).first);
        ++itr;
    }
    std::vector<std::string> r2;
    itr = m.end(10);
    while (itr != m.begin(10)) {
        itr--;
        r2.push_back((*itr).first);
    }
    std::reverse(r2.begin(), r2.end());
}

