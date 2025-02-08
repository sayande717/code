import java.util.Scanner;

public class Main {
    private boolean isOdd(int num) {
        return (num % 2) != 0;
    }

    private int findSingleSum(int num) {
        // Base Case
        if (num < 10) {
            return num;
        }
        int sum = 0;
        int rem;
        while (num != 0) {
            rem = num % 10;
            sum += rem;
            num = num / 10;
        }
        num = sum;
        return findSingleSum(num);
    }

    private char returnChar(int num) {
        char[] oddToChar = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
        return oddToChar[num - 1];
    }

    public static void main(String[] args) {
        Main ob = new Main();
        Scanner input = new Scanner(System.in);
        String[] inputs = input.nextLine().split(" ");
        String outStr = "";
        for (int index = 0; index < inputs.length; index++) {
            int currentNumber = Integer.parseInt(inputs[index]);
            currentNumber = ob.findSingleSum(currentNumber);
            if (ob.isOdd(currentNumber)) {
                outStr += ob.returnChar(currentNumber);
            } else {
                outStr += currentNumber;
            }
        }
        System.out.print(outStr);
        input.close();
    }
}
