package ntou.cs.java2026;
public class ConstructorTest {
    public static void main(String args[]) {
        ThirdWriter writer = new ThirdWriter();
        writer.showLastLine();
    }
}

class BaseWriter {
    public BaseWriter() {
        System.out.println("1. An overriding method cannot be less accessible than the overridden parent method.");
    }

    public BaseWriter(String param) {
        this();
        System.out.println("2. Constructors are not inherited between parent and child classes.");
    }
}

class SecondWriter extends BaseWriter {
    public SecondWriter() {
        this("");
        System.out.println("4. A subclass constructor must call a parent class constructor, either automatically or explicitly.");
    }

    public SecondWriter(String param) {
        super("");
        System.out.println("3. A constructor can call another constructor in the same class using this().");
    }

    public SecondWriter(String param1, int param2) {
        this();
        System.out.println("5. The first statement in a constructor can be either this() or super(), but not both.");
    }

    public SecondWriter(String param1, int param2, boolean param3) {
        this("", 0);
        System.out.println("6. A static method with the same signature as a parent static method hides it rather than overrides it.");
    }

    public void showLastLine() {
        System.out.println("9. A package-private parent method cannot be overridden by a subclass in a different package.");
    }

}

class ThirdWriter extends SecondWriter {
    public ThirdWriter() {
        this("");
        System.out.println("8. The @Override annotation marks a method as overriding a parent class method.");
    }

    public ThirdWriter(String param) {
        super("", 0, true);
        System.out.println("7. A subclass method with the same signature as a parent private method is not an override.");
    }

    public void showLastLine() {
        super.showLastLine();
        System.out.println("10. A public parent method can be overridden by a subclass in a different package.");
    }
}
