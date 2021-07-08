import java.util.Scanner;
public class Student {
   private String name;
   private int age;
   Student(){
       this("Raman", 8);
   }
   Student(String name, int age){
      this.name = name;
      this.age = age;
   }
   // public void SetValues(String name, int age){
   //    this(name, age);
   // }
   public void display() {
      System.out.println("name: "+this.name);
      System.out.println("age: "+this.age);
   }
   public static void main(String args[]) {
      Scanner sc = new Scanner(System.in);
      System.out.println("Enter the name of the student: ");
      String name = sc.nextLine();
      System.out.println("Enter the age of the student: ");
      int age = sc.nextInt();
      Student obj = new Student();
      // obj.SetValues(name, age);
      obj.display();
   }
}
