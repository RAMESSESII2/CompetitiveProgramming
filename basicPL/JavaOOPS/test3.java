
class Derived 
{
    public void getDetails()
    {
        System.out.println("Derived class");
    }
}
//compiler time error, because child class method can't be more restrictive than the corresponding paretn class method
  
public class test3 extends Derived
{
    protected void getDetails()
    {
        System.out.println("Test class");
    }
    public static void main(String[] args)
    {
        test3 obj = new test3();  // line xyz
        obj.getDetails();
    }
}
