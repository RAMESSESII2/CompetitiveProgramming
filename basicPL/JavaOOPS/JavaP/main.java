// Use of super() function
class Animal {
    Animal() {
        System.out.println("animal is created");
    }
}

class Dog extends Animal {
    Dog() {
        super();
        System.out.println("dog is created");
    }
}

class main {

    public static void main(String[] args) {
        Dog ob = new Dog();
    }
}
