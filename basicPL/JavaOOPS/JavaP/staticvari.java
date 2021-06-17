class temp{
    static int num;
    static int first;
    static{
        num = 0;
        first = 0;
    }    
    public void number(){
        System.out.println("Number num ="+num);
        System.out.println("Value of first="+first);
    }
}

public class staticvari {
    public static void main(String args[]){
        temp l1 = new temp();
        l1.number();
        temp l2 = new temp();
        l2.number();

    }
}
