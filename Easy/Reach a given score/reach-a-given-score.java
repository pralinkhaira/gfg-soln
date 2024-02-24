//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class GFG {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        while(t > 0)
        {
            int n = in.nextInt();
            Geeks obj = new Geeks();
            System.out.println(obj.count(n));
            t--;
        }
    }
}
// } Driver Code Ends


class Geeks {
    
    public long count(int n) {
        long[] dp = new long[(int)n+1];
        Arrays.fill(dp, 0);
        dp[0] = 1;
        
        // Add your code here.
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i] + dp[i - 3];
        }
        for (int i = 5; i <= n; i++) {
            dp[i] = dp[i] + dp[i - 5];
        }
        for (int i = 10; i <= n; i++) {
            dp[i] = dp[i] + dp[i - 10];
        }
        
        return dp[n];
    }
    
}