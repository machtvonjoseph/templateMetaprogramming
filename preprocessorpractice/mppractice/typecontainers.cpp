#include <boost/mp11.hpp>
#include <boost/core/demangle.hpp>
#include <type_traits>
#include <iostream>
#include <typeinfo>
#include <tuple>
#include <string>

using L1= std::tuple <int, double, float>;
using M1= boost::mp11::mp_list<int, double>;
//using R1= boost::mp11::mp_push_front<M1, float>;
using S1 = boost::mp11::mp_size<M1>;
template<class T> using makechar = char;
// template<class T> struct make_char { typedef char type; };
// template<class T> using make_char_now = typename make_char<T>::type;



int main(){


    using T1 = boost::mp11::mp_size_t<1>;

    std::cout<< T1::value<<std::endl;
    for(int i=0; i<5; i++){
       // using R1 = boost::mp11::mp_push_front<R1, float>;// R1;
        
    std::cout<< S1::value<<std::endl;
    }
    using C1= boost::mp11::mp_transform<makechar, L1>;
    using X = boost::mp11::mp_front<C1>;
    X val = 'c';
    std::cout<< val<<std::endl;

    
}