#include <iostream>
#include <boost/pfr/core.hpp>


struct foo {
    int some_integer = 4;
    char c = 'a';
};

int main() {
    foo f;
    std::cout<<f.some_integer<<std::endl;
    auto& r1 = boost::pfr::get<0>(f);
    r1 = 5;
    std::cout<<f.some_integer<<std::endl;
}