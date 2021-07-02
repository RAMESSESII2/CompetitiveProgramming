class MultiThreading{
    public static void main(String args[]){
        hack_thread h = new hack_thread();
        h.start();
        while(h.isAlive()){
            try{
                h.sleep(10);
            }
            catch(Exception e){
                System.out.println("hello");
            }
            System.out.println("hackerearth");
        }
    }
}

class hack_thread extends Thread{
    public void run(){
        System.out.println("hi");
    }
}
