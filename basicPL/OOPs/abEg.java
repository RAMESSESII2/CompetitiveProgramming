abstract class parent{
    parent(){
        System.out.println("Base class constructor called");
    }
    abstract void ab();
}
public class abEg extends parent{
    public static void main(String[] args){
        abEg obj = new abEg();
        obj.ab();
    }
    void ab(){
    }
}
