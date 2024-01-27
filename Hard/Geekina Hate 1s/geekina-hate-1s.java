//{ Driver Code Starts
import java.io.*;
import java.util.*;
public class Main{
 
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter ot = new PrintWriter(System.out);

        int t = Integer.parseInt(br.readLine().trim());
        Solution soln = new Solution();
        while(t-- > 0){
            String s[] = br.readLine().trim().split(" ");
            int n = Integer.parseInt(s[0]);
            int k = Integer.parseInt(s[1]);
            ot.println(soln.findNthNumer(n, k));
        }
        ot.close();
    }
  
} 
// } Driver Code Ends
class Solution{
    public long findNthNumer(int n, int k){
          long low = 0, high = (long)(1e18);
        dp = new Long[2][65][65];
        while(low <= high){
            long mid = low + (high - low) / 2;
            long count = find(mid, k);
            if(count >= n)
                high = mid - 1;
            else
                low = mid + 1;}
        return low;
    }
    private long find(long n, int k){
        char s[] = Long.toBinaryString(n).toCharArray();
        reset();
        return dp(s, s.length, 1, k);
    }
    private long dp(char s[], int n, int tight, int k){
        if(k < 0)
            return 0;
        if(n == 0){
            return 1;
        }
        if(dp[tight][k][n] != null)
            return dp[tight][k][n];
        int ub = (tight == 1 ? (int)(s[s.length - n] - '0') : 1);
        long ans = 0;
        for(int dig = 0; dig <= ub; dig++){
            if(dig == ub)
                ans += dp(s, n - 1, tight, k - dig);
            else
                ans += dp(s, n - 1, 0, k - dig);
        }
        return dp[tight][k][n] = ans;
    }
    private void reset(){
        for(int i = 0; i < 65; i++){
            Arrays.fill(dp[0][i], null);
            Arrays.fill(dp[1][i], null);
        }
    }
    private Long dp[][][];}