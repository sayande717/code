import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        String[] arrStr = str.split(" ");
        int arrLen = arrStr.length;
        int sum = 0;
        if(arrLen>10) {
            System.out.print("Array size must be between 1 and 10");
            return;
        }
        try {
            for(int index=0;index<arrLen;index++) {
                int element = Integer.parseInt(arrStr[index];
                if(element<-10 || element>10) {
                    System.out.print("Array elements must be from -10 to 10");
                    return;
                }
                sum = sum + element;
            }
        } catch(NumberFormatException e) {
            System.out.print("Array elements must be integers");
            return;
        }
        System.out.println((sum==0)?"True":"False");
        System.out.print(arrLen);
        input.close();
    }
}
