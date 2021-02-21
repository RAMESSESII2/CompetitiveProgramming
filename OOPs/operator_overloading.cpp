#include<iostream>
using namespace std;
void file_i_o(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("cerr.txt", "w", stderr);
#endif
}

class Complex{
    private:
        int real, imag;
    public:
        Complex(int r = 0, int i = 0){
            real = r;
            imag = i;
        }

        void print(){
            cout << real << " + " << imag << "i" << endl;
        }
        Complex operator +(Complex c){
            Complex temp;
            temp.real = real + c.real;
            temp.imag = imag + c.imag;
            return temp;
        }
};

int main(){
    file_i_o();

    Complex c1(5, 4);
    c1.print();

    Complex c2(2, 3);

    Complex c3;

    c3 = c1 + c2;
    c3.print();

    int width{ 5 }; // direct list initialization of value 5 into variable width (preferred)
    int height = { 6 }; // copy list initialization of value 6 into variable height

    int a = 5, b = 6; // copy initialization
    int c(7), d(8); // direct initialization
    int e{9}, f{10}; // list initialization (preferred)
    cout << width << " " << height <<endl;

    return 0;
}
