import java.io.*;

interface A{
    int j = 4;
}
interface B{
    int k = 4;
}

class TWoInterfaces implements A, B{
    public static void main(String args[]){
        TWoInterfaces t = new TWoInterfaces();
        System.out.print(B.k);
    }
}
