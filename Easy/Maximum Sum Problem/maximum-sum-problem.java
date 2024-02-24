//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    int n = sc.nextInt();
                    Solution ob = new Solution();
                    System.out.println(ob.maxSum(n));
                }
        }
}    
// } Driver Code Ends

class Solution
{
    public int maxSum(int n) 
    { 
        int[]dp = new int[n+1];
        util(n,dp);
        return dp[n];
    } 
    
    static int util(int n, int[] dp){
         if(dp[n] != 0){
            return dp[n];
        }
        if(n <= 0){
            return 0;
        }
       
        dp[n] = Math.max(util(n/2,dp) + util(n/3,dp) + util(n/4, dp), n);
        return dp[n];
    }
}
