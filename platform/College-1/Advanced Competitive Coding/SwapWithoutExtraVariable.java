import java.util.Arrays;

class temp {
    private static int[] swap(int a, int b) {
        a = a + b;
        b = a - b;
        a = a - b;
        return new int[] { a, b };
    }

    public static void main(String[] args) {
        System.out.println(Arrays.toString(swap(Integer.parseInt(args[0]), Integer.parseInt(args[1]))));
    }
}