import java.io.*;

class Test{
    int a = 1, b  = 2;
    Test(int a, int b){
        this.a = a;
        this.b = b;
    }
    Test get(){
        return this;
    }
    void display(){
        System.out.println("a = " + this.a + " b = "+b);
    }
    public static void main(String[] arg){
        Test ob = new Test(10, 20);
        ob.display();
        //same thing the below does as the above
        ob.get().display();
    }
}
