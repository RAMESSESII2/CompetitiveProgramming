class Foo{
    public int a = 5;
    Foo(){
        System.out.println("Foo called ");
    }
    public void addFive(){ a+=5; System.out.println("Foo a = "+ this.a); }
}

class Bar extends Foo{
    public int a = 4;
    Bar(){
        System.out.println("Bar called ");
    }
    public void addFive(){ 
        a+=5; 
        System.out.println("Bar a = "+ this.a); }
}

class Two extends Foo{
    public double a = 4;
    Two(){
        System.out.println("two called ");
    }
    public void addFive(){ a+=5; System.out.println("two a = "+ this.a); }
}
public class SameVariables{
    public static void main(String[] args){
        Bar obj1 = new Bar();
        //this method prints Bar class "a"
        obj1.addFive();
        //this will print Bar class "a"
        System.out.println("NOw a is " + obj1.a);
        //this will print Foo class "a"
        System.out.println("NOw a is " + ((Foo)obj1).a);
        obj1.addFive();

        Foo obj2 = new Bar();
        //this method prints Bar class "a"
        obj2.addFive();
        //this will print Foo class "a"
        System.out.println("NOw a is " + obj2.a);
        //this method prints Bar class "a"
        System.out.println("NOw a is " + ((Bar)obj2).a);

        Foo obj3 = new Two();
    }
}
