import java.util.Scanner;

public class Main {
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int a = input.nextInt();
        int b = input.nextInt();
        calculateTime(a,b);
        input.close();
    }

    public static void calculateTime(int hours, int devices)
    {
        int testDuration = 4;
        if(hours<4) {
            System.out.print("Invalid Input");
            return;
        }
        int noOfDevices = (hours/testDuration);
        int remDevices = devices - noOfDevices;
        System.out.println(noOfDevices);
        System.out.print(remDevices);
    }
}
