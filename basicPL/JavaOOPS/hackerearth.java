class hackerearth{
    public static void main(String[] args){
        hack1 h1 = new hack2();
        hack2 h2 = new hack2();
        hack1 h;
        h = h1;
        h.hack_method();
        h.hack_method();
    }
}

class hack1{
    hack1(){
        System.out.println("hello");
    }
    void hack_method(){
        System.out.println("hackerearth");
    }
}

class hack2 extends hack1{
    hack2(){
        System.out.println("hi");
    }
    void hack_method(){
    System.out.println("hello world");
    }
}
