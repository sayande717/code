import java.util.Scanner;

public class Main {
    public static void encryptNumber(String num) {
        int numLength = num.length();
        try {
            if(Integer.parseInt(num) < 0) {
                System.out.print("Enter positive 4-digit integer");
                return;
            } else if(numLength < 4) {
                System.out.print("Provided input is less than 4, enter four digit integers");
                return;
            } else if(numLength > 4) {
                System.out.print("Provided input is more than 4, enter four digit integers");
                return;
            }
        } catch(Exception e) {
            System.out.print("Enter only integer value");
            return;
        }
        int[] outNum = new int[numLength];
        // Encrypt
        for(int index=0;index<numLength;index++) {
            outNum[index] = Integer.parseInt(num.substring(index,index+1))+5;
            if(outNum[index]>=10) {
                outNum[index] = outNum[index]%10;
            }
        }
        // Swap
        int temp = outNum[0];
        outNum[0] = outNum[2];
        outNum[2] = temp;
        temp = outNum[1];
        outNum[1] = outNum[3];
        outNum[3] = temp;
        // Print
        for(int index=0;index<numLength;index++) {
            System.out.print(outNum[index]);
        }
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String inNum = input.nextLine();
        encryptNumber(inNum);
        input.close();
    }
}
