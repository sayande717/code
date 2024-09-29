import java.util.Scanner;

public class Main {
    private static char findMax(char num1, char num2) {
        return (num1 >= num2) ? num1 : num2;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int changes = Integer.parseInt(input.next());
        char[] str = input.next().toCharArray();
        int strLen = str.length;
        int start, end;

        for (start = 0, end = (strLen - 1); start <= end; start++, end--) {
            if (start != end) {
                if (str[start] == str[end] && changes >= 2) {
                    str[start] = str[end] = '9';
                    changes -= 2;
                } else if (str[start] != str[end] && changes >= 1) {
                    str[start] = str[end] = findMax(str[start], str[end]);
                    changes -= 1;
                }
            } else {
                if (changes >= 1) {
                    str[start] = '9';
                    changes -= 1;
                }
            }
        }

        String outStr = new String(str);
        System.out.print(outStr);
    }
}
