//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());

        while (t-- > 0) {
            int n = Integer.parseInt(read.readLine());

            Solution ob = new Solution();

            System.out.println(ob.countAndSay(n));

            System.out.println("~");
        }
    }
}
// } Driver Code Ends

class Solution {
    public String countAndSay(int n) {
        String base = "1";
        
        while (--n > 0) {
            StringBuilder temp = new StringBuilder();
            char ch = base.charAt(0);
            int count = 1;
            
            for (int i = 1; i < base.length(); i++) {
                if (base.charAt(i) == ch) {
                    count++;
                } else {
                    temp.append(count);
                    temp.append(ch);
                    ch = base.charAt(i);
                    count = 1;
                }
            }
            temp.append(count);
            temp.append(ch);
            
            base = temp.toString();
        }
        
        return base;
    }
}
