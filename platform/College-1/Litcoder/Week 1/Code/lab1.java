import java.util.Scanner;
public class lab1 {
    public static void main(String[] args) {

    Scanner input = new Scanner(System.in);
    int size = input.nextInt();
    int[] arr = new int[size];
    for(int index=0;index<size;index++) {
        arr[index] = input.nextInt();
    }
    findArrRatio(size,arr);
    input.close();
}

public static void findArrRatio(int size, int[] arr) {
    double ratioPositive = 0;
    double ratioNegative = 0;
    double ratioZero = 0;
    for(int index = 0;index<size;index++) {
        if(arr[index]>0) {
            ratioPositive++;
        } else if(arr[index]<0) {
            ratioNegative++;
        } else {
            ratioZero++;
        }
    }
    ratioPositive = ratioPositive / size;
    ratioNegative = ratioNegative / size;
    ratioZero = ratioZero / size;
    System.out.printf("%.3f%n",ratioPositive);
    System.out.printf("%.3f%n",ratioNegative);
    System.out.printf("%.3f",ratioZero);
    }
}
