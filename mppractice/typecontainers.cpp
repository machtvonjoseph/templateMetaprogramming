#include <boost/mp11.hpp>
#include <boost/core/demangle.hpp>
#include <type_traits>
#include <iostream>
#include <typeinfo>
#include <tuple>
#include <string>

using L1= std::tuple <int, double, float>;
using R1= boost::mp11::mp_push_front<L1, float>;

template<class T> using makechar = char;
// template<class T> struct make_char { typedef char type; };
// template<class T> using make_char_now = typename make_char<T>::type;



int main(){
    for(int i=0; i<5; i++){
        using R1 = boost::mp11::mp_push_front<R1, float>;// R1;
        using S1 = boost::mp11::mp_size<R1>;
    std::cout<< S1::value<<std::endl;
    }
    using C1= boost::mp11::mp_transform<makechar, L1>;
    using X = boost::mp11::mp_front<C1>;
    X val = 'c';
    std::cout<< val<<std::endl;
}