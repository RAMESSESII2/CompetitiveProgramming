/* TOPIC: std::set */

/* NOTES: */
/* 1. std::set is an Associative Container that contains a sorted set of unique objects of type Key. */
/* 2. It is usually implemented using Red-Black Tree. */
/* 3. Insertion, Removal, Search have logarithmic complexity. */
/* 4. If we want to store user defined data type in set then we will have to provide */ 
/*    compare function so that set can store them in sorted order. */
/* 5. We can pass the order of sorting while constructing set object. */

/* BOTTOM LINE: */
/* It store unique elements and they are stored in sorted order (A/D) */

#include<iostream>
#include<set>
#include<string>
#include<functional>
using namespace std;

class Person{
    public:
        float age;
        string name;
    bool operator < (const Person &rhs) const { return age<rhs.age;}
    bool operator > (const Person &rhs) const { return age>rhs.age;}
};

int main(){
    /* std::set<int> myset {3,5,4,35,-435,2,4,5,2};  //<int, less< > > */
    /* std::set<int, greater<>> myset {3,5,4,35,-435,2,4,5,2}; */
    /* set<Person, greater<>> myset = {{34,"sb"}, {354, "ramesse2"}, {787, "pharaoh"}}; */
    set<Person> myset = {{34,"sb"}, {354, "ramesse2"}, {787, "pharaoh"}};
    for(const auto &e: myset){
        cout << e.age << " " << e.name  << endl;
    }
    return 0;
}

