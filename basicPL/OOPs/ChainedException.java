import java.io.*;

public class ChainedException
{
    public static void divide(int a, int b)
    {
      if(b == 0)
      {
        ArithmeticException ae = new ArithmeticException("top layer");
        ae.initCause(new IOException("cause"));
        throw ae;
      }
      else
      {
        System.out.println(a/b);
      }
    }
    //unchecked excetpions are not needed to be caught
    static void newMethod() throws ArithmeticException{
      int a = 5/0;
    }
    static void newMethod2(){
      //checked exceptions are needed to be caught
      try{
        throw new IOException("device error ");
      }
      catch(Exception e){
        System.out.println("nadkjajdk");
      }
      // throw new ArithmeticException("AEEX");
    }
    //error because we're not handling newMethod3() anywhere in the program
    // static void newMethod3() throws IOException{
    //   throw new IOException("catch IO");
    // }

    public static void main(String[] a)
    {
      try 
      {
        divide(5, 0);
      }
      catch(ArithmeticException ae) {
        System.out.println( "caught : " +ae);
        System.out.println("actual cause: "+ae.getCause());
      }
      newMethod2();
      newMethod();
    }
}
