/*
class Test
{
    public static void main(String[] args)
    {
        try
        {
            int a[]= {1, 2, 3, 4};
            for (int i = 1; i <= 4; i++)
            {
                System.out.println ("a[" + i + "]=" + a[i] + "n");
            }
        }
         
        catch (Exception e)
        {
            System.out.println ("error = " + e);
        }
         
        catch (ArrayIndexOutOfBoundsException e)
        {
            System.out.println ("ArrayIndexOutOfBoundsException");
        }
    }
}
*/
/*

class Test
{
    String str = "a";
 
    void A()
    {
        try
        {
            str +="b";
            B();
        }
        catch (Exception e)
        {
            str += "c";
        }
    }
 
    void B() throws Exception
    {
        try
        {
            str += "d";
            C();
        }
        catch(Exception e)
        {
            throw new Exception();
        }
        finally
        {
            str += "e";
        }
 
        str += "f";
 
    }
     
    void C() throws Exception
    {
        throw new Exception();
    }
 
    void display()
    {
        System.out.println(str);
    }
 
    public static void main(String[] args)
    {
        Test object = new Test();
        object.A();
        object.display();
    }
 
}
*/
/*
class Test
{   int count = 0;
 
    void A() throws ArithmeticException
    {
        try
        {
            count++;
             
            try
            {
                count++;
 
                try
                {
                    count++;
                    throw new Exception();
 
                }
                 
                catch(Exception ex)
                {
                    count++;
                    throw new Exception();
                }
            }
             
            catch(Exception ex)
            {
                count++;
            }
        }
         
        catch(Exception ex)
        {
            count++;
        }
 
    }
 
    void display()
    {
        System.out.println(count);
    }
 
    public static void main(String[] args) throws Exception
    {
        Test obj = new Test();
        obj.A();
        obj.display();
        int a = 1/0;
    }
}
*/

/*

public class Test
{
    public static void main(String[] args)
    {
        byte var = 1;
        var = (byte) var * 0; //line 1
        byte data = (byte) (var * 0); //line 2
        System.out.println(var);        
    }
}
*/
class demoClass
{
    int a = 1;
 
    void func()
    {
        demo obj = new demo();
        obj.display();
    }
 
 
    class demo
    {
        int b = 2;
 
        void display()
        {
            System.out.println("na = " + a);
        }
    }
 
    // void get()
    // {
    //     System.out.println("nb = " + b);
    // }
}
 
 
class Test
{
    public static void main(String[] args)
    {
        demoClass obj = new demoClass();
        obj.func();
        // obj.get();
 
    }
}
