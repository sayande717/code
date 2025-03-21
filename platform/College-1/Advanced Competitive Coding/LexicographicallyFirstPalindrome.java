public class LexicographicallyFirstPalindrome {     
    private static String getPalindromicString(String s) {  
    
        int[] freq = new int[26];  
        // Stores the frequency of each character.
        for (char c : s.toCharArray()) {
            // 'c' - 'a' = 2, so we increment index 2 by 1.
            freq[c - 'a']++;
        }
    
        StringBuilder front = new StringBuilder();
        StringBuilder odd = new StringBuilder();  
    
        for (int i = 0; i < 26; i++) {  
            // Check for odd characters, append them
            if (freq[i] % 2 == 1) {
                odd.append((char) (i + 'a'));  
            }
            
            // Append half of the number of even characters to the front
            for (int j = 0; j < freq[i] / 2; j++) {
                front.append((char) (i + 'a'));  
            }
        }
        
        if (odd.length() > 1) {
            return "No such Palindromic String exists";  
        }
        
        // Reverse the front, add it to rear.
        String rear = front.reverse().toString();
        return front.reverse().toString() + odd + rear;  
    }

    public static void main(String[] args) {  
        String str = "malayalam";  
        System.out.println("The lexicographic first palindromic string is: " + getPalindromicString(str));  
    }  
}  
