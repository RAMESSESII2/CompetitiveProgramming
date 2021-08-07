#include<bits/stdc++.h>
using namespace std;

class HashTable{
    private:
        static const int tableSize = 10;
        list<pair<int, string> > table[tableSize];
        int i;
    public:
        HashTable(int k){
            this->i = k; // constructor check, no role of this variable in this program
            cout << "constructor called \n" << endl;
        }
        bool isEmpty() const;
        int hashFunction(int key);
        void insertItem(int key, string value);
        void removeItem(int key);
        void searchTable(int key);
        void printTable();
};

bool HashTable::isEmpty() const{
    bool empty = true;
    for( int i = 0; i < tableSize; i++){
        if( table[i].empty() ) continue;
        else {
            empty = false;
            break;
        }
    }
    return empty;
}

int HashTable::hashFunction(int key){
    return (key)%tableSize;
}

void HashTable::insertItem(int key, string value){
    int hashVal = hashFunction(key);
    auto bIter = table[hashVal].begin();
    bool keyExists = false;
    for(; bIter != table[hashVal].end(); bIter++){
        if( bIter->first == key ){
            keyExists = true;
            bIter->second = value;
            cout << " already exists and updated" << endl;
            break;
        }
    }
    if( keyExists == false ){
        table[hashVal].push_back({key, value});
        cout << "added " << endl;
    }
    return;
}

void HashTable::removeItem(int key){
    int hashVal = hashFunction(key);
    auto bIter = table[hashVal].begin();
    bool keyExists = false;
    for(; bIter != table[hashVal].end(); bIter++){
        if( bIter->first == key ){
            keyExists = true;
            bIter = table[hashVal].erase(bIter);
            cout << " already exists and updated" << endl;
            break;
        }
    }
    if( keyExists == false ){
            cout << " already exists and updated" << endl;
    }
    return;
}

void HashTable::printTable(){
    for( int i{}; i < tableSize; i++ ){
        if( table[i].size() == 0 ) continue;
        auto itr = table[i].begin();
        for(; itr != table[i].end(); itr++){
            cout << " Key: " << itr->first << " Value: " <<itr->second << endl;
        }
    }
}

int main(){
    HashTable HT(23);
    if( HT.isEmpty() ) {
        cout << "CORRECT " << endl;
    }
    else{
        cout << "INCORRECT " << endl;
    }
    HT.insertItem(905, "Jim");
    HT.insertItem(800, "Tom");
    HT.insertItem(700, "JOn Un");
    HT.insertItem(101, "SOme ");
    HT.insertItem(102, "obama ");
    HT.insertItem(105, "kalam ");
    HT.insertItem(105, "Tagore");
    HT.printTable();

    HT.removeItem(102);
    HT.removeItem(800);
    HT.printTable();
    if( !HT.isEmpty() ) {
        cout << "CORRECT " << endl;
    }
    else{
        cout << "INCORRECT " << endl;
    }
}
