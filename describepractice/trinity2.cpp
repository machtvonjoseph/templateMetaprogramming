#include <boost/describe.hpp>
#include <boost/mp11.hpp>
#include <boost/pfr/core.hpp>
#include <vector>
#include <typeinfo>
#include <iostream>


using namespace boost::describe;


class MyClass {
    public:
    int x=1;
    int y=2;
    BOOST_DESCRIBE_CLASS(MyClass, (), (), (), (x,y))
};


template<class T>
class numa{
    public:
    using type = T;
    int val;
    template<class F> using makenuma = numa<T>;

    boost::mp11::mp_for_each<describe_members<T, mod_any_access>>(&](auto D){

    std::cout << "." << D.name << " = " ;//<< *D.pointer << std::endl;
    using B =  decltype(D);

    B isanint;
        std::cout<<typeid(isanint).name()<<std::endl;
    //   using innerNuma = makenuma<decltype(D)::type>;
    //    innerNuma newval;
    // std::cout<<typeid(newval).name()<<std::endl;

    });


};



//template<class F> using makenuma = numa<F>;

int main (){
    int num = 5;
    std::cout<<typeid(num).name()<<std::endl;
    numa<MyClass> n;
    std::cout<<typeid(n).name()<<std::endl;






}