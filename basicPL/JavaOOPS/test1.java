
class Derived 
{
    public void getDetails(String temp)
    {
        System.out.println("Derived class " + temp);
    }
}
//doesn't work because for overriding, methods should have same signature which includes argument list and return type
  
public class test1 extends Derived
{
    public int getDetails(String temp)
    {
        System.out.println("Test class " + temp);
        return 0;
    }
    public static void main(String[] args)
    {
        test1 obj = new test1();
        obj.getDetails("GFG");
    }
}
