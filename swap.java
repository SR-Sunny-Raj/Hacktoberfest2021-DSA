public class SwapNumbers {
    public static void main(String[] args) {

        float first = 2.31f, second = 5.48f;

        System.out.println("Before swap: ");
        System.out.println("First number = " + first);
        System.out.println("Second number = " + second);

        // Value of the first number is stored to temporary
        float temporary = first;

        // Value of the second number is assigned to first
        first = second;

        // Value of temporary (initial value of first) is assigned to second
        second = temporary;

        System.out.println("After swap:");
        System.out.println("First number = " + first);
        System.out.println("Second number = " + second);
    }
}
