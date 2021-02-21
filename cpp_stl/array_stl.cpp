//Topic: std::array
//
//Syntax: std::array<T,N> array;
// NOTICE: 
/* 1. std::array is a container that encapsulates fixed size arrays. */
/* 2. array size is needed at compile time. */
/* 3. Assign by value is actually by value. */
/* 4. Access Elements: */
/*    a. at() */
/*    b. [] */
/*    c. front() */
/*    d. back() */
/*    e. data() // gives access to the underlying array */
//  When it is passed to a funtion, pointer is not passed as in C so we get copy of this array and hence the original array is not modified.

#include<iostream>
#include<array>
using namespace std;

int main(){
    std::array<int, 5> myarr;
    
    //Initialisation
    array<int, 5> arr = {2,3,564,4,2};
    array<int, 5> arr2 {2312,3,564,234,2};

    myarr = {3,23,5 ,123,5};
    for( int i=0; i<5; i++){
        cout<<arr.at(i)<<" ";
    }
    cout << endl;
    for( int i=0; i<5; i++){
        cout<<arr2[i+1]<<" ";
    }
    cout << endl;
    for( int i=0; i<5; i++){
        cout<<myarr.at(i)<<" ";
    }
    array<int,0> arr1{}; //an empty array
    array<int, 5> arr23{}; //array of size 5, elements 0
    array<int, 5> arr3{10, 20, 30};
    array<int, 5> arr4{10, 20, 30, 50, 50};
    array<int, 5> arr5{-34, -23, 10, 20, 30};
    for (auto d : arr3)
    {
        std::cout << d << std::endl;
    }

    cout<< "size of arr1: " << arr1.size() << endl;
    cout<< "size of arr2: " << arr2.size() << endl;
    cout<< "size of arr2: " << arr23.size() << endl;
    cout<< "size of arr3: " << arr3.size() << endl;
    cout<< "size of arr4: " << arr4.size() << endl;
    cout<< "size of arr5: " << arr5.size() << endl;
    
}

