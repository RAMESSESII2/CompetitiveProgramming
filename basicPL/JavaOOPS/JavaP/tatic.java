class languages{
    static int num;
    int first;
    languages(){
        num++;
    }
    public void number(){
        System.out.println("Number now ="+num);
        System.out.println("Value of first="+first);
    }
}

public class tatic{
    static int a;
    static int b;
    static {
    a = 10;
    b = 20;
    }
    public static void main(String args[]){
        languages l1 = new languages();
        l1.number();
        languages l2 = new languages();
        l2.number();

        System.out.println("a ="+a);
        System.out.println("b ="+b);
    }
}