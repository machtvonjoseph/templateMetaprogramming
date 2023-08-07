#include <boost/describe.hpp>
#include <boost/mp11.hpp>
#include <boost/pfr/core.hpp>
#include <vector>
#include <typeinfo>
#include <iostream>


using namespace boost::describe;

using L1= std::tuple <>;

class MyClass {
    public:
    int x=1;
    int y=2;
    BOOST_DESCRIBE_CLASS(MyClass, (), (), (), (x,y))
};


template<class T>
class numa : public T{
    public:
    using type = T;
    int val;
    //template<class F> using makenuma = numa<T>;
};

template<class F> using makenuma = numa<F>;

int main (){
    int num = 5;
    std::cout<<typeid(num).name()<<std::endl;
    numa<MyClass> n;
    std::cout<<n.x<<std::endl;
    std::cout<<typeid(n).name()<<std::endl;
    using mynuma = makenuma<MyClass>;
    mynuma newval;
    std::cout<<typeid(newval).name()<<std::endl;



    // boost::mp11::mp_for_each<describe_members<MyClass, mod_any_access>>([&](auto D){
    // using R0 = boost::mp11::mp_push_front<L1, decltype(D)>;
    // using R1 = boost::mp11::mp_append<R1, R0>;
    // std::cout << "." << D.name << " = " ;//<< *D.pointer << std::endl;
    // std::cout<<typeid(decltype(D)).name()<<std::endl;
    // using B = boost::mp11::mp_front<R1>;
    
    // B isanint;
    //     std::cout<<typeid(isanint).name()<<std::endl;
    // //   using innerNuma = makenuma<decltype(D)::type>;
    // //    innerNuma newval;
    // // std::cout<<typeid(newval).name()<<std::endl;
    // // using S1 = boost::mp11::mp_size<A1>;
    // // std::cout<< S1::value<<std::endl;  
    // });
  

}