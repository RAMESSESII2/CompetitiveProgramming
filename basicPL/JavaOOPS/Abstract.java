import java.io.*;
abstract class Shape{
    private String color;
    abstract double area();
    public abstract String toString();
    public Shape(){
        System.out.println("Shape constructor ");
    }
    public Shape(String color){
        System.out.println("Shape constructor called ");
        this.color = color;
    }

    public String getColor(){
        return color;
    }
}
class Circle extends Shape{
    double radius;
    public Circle(String color, double radius){
        super(color);
        System.out.println("Cirlce constructor called ");
        this.radius = radius;
    }
    double area(){
        return Math.PI*Math.pow(radius, 2);
    }
    public String toString(){
        return "Circle color is " + super.getColor() + "and area is: "+area();
    }
}

class Line extends Shape{
    double length;
    public Line(double l){
        super();
        this.length = l;
        System.out.println("Inside line constructor");
    }
    double area(){
        return 0.0;
    }
    public String toString(){
        return "Area is " + area();
    }
}

public class Abstract{
    public static void main(String[] a){
        Shape l1 = new Line(4.3);
        l1.toString();
        Shape s1 = new Circle("Red", 9);
        Circle s2 = new Circle("Red", 10);
        System.out.println(s1.toString());
        System.out.println(s2.toString());
    }
}
