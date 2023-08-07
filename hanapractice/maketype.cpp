#include <boost/hana.hpp>
#include <boost/any.hpp>
#include <cassert>
#include <string>
#include <typeindex>
#include <typeinfo>
#include <utility>
#include <iostream>

namespace hana = boost::hana;

struct Person {
  BOOST_HANA_DEFINE_STRUCT(Person,
    (std::string, name),
    (int, age)
  );
};

auto serialize = [](std::ostream& os, auto const& object) {
  hana::for_each(hana::members(object), [&](auto member) {
    os << member << std::endl;
  });
};


int main(){
Person john{"John", 30};
serialize(std::cout, john);
}