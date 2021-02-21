/* TOPIC: std::vector */      

/* NOTES: */
/* 1. std::vector is a sequence container and also known as Dynamic Array or Array List. */
/* 2. Its size can grow and shrink dynamically, and no need to provide size at compile time. */

/* ELEMENT ACCESS */
/* at(), [], front(), back(), data() */

/* MODIFIERS: */
/* insert(), emplace(), push_back(), emplace_back(), pop_back(), resize(), swap(), erase(), clear() */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(int a, int b){
    return a>b;
}

int main(){
    std::vector<int> arr {23,234,54,63,}; //Uniform Initialization
    std::vector<int> arr3 = {234,34,56,-234}; //initializer list
    arr3.at(4) = 324;
    arr[3] = 34;
    vector<int> v;
    v.reserve(100);
    int n;
    cout << v.max_size()<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        v.emplace_back(temp);
        cout << v.capacity()<< v.size()<<endl;
    }
    cout << "before sorting" << endl;
    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
    sort(v.begin(), v.end(), compare);
    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }
}
