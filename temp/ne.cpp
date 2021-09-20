#include <iostream>
using namespace std;

class F
{};

class S: public F
{

};

template<typename X, typename Y>
class check
{
    class F {}; 
    static F find( ... );

    class T {F f[21]; }; 
    static T find( Y* );

public:

enum

{

m=sizeof(T) == sizeof(find(static_cast<X*> (0)))

};

};

template <class Q, class R>
bool checkIf()
{
    return check<Q, R>::m;

}

int main()
{
check<class F, class S> t (F,S); 
cout << checkIf<class F, class S>() <<endl; return 0;
}
