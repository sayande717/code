import java.util.Scanner;

public class Main {
    public static String convert(String str) {
        String[] words = str.split(" ");
        for (int wordIndex = 0; wordIndex < words.length; wordIndex++) {
            for (int charIndex = 0; charIndex < words[wordIndex].length(); charIndex++) {
                char current = Character.toLowerCase(words[wordIndex].charAt(charIndex));
                if (current == 'a' || current == 'e' || current == 'i' || current == 'o' || current == 'u') {
                    words[wordIndex] = words[wordIndex] + "ma";
                } else {
                    words[wordIndex] = words[wordIndex].substring(1) + words[wordIndex].charAt(0) + "ma";
                }
                for (int index = 0; index <= wordIndex; index++) {
                    words[wordIndex] = words[wordIndex] + "a";
                }
            }
        }
        String outStr = String.join(" ", words);
        return outStr;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        System.out.print(convert(str));
        input.close();
    }
}
