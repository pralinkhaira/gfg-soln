//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            
            int  k = Integer.parseInt(read.readLine());
            int  n = Integer.parseInt(read.readLine());
            int arr[][] = new int[n][n];
            String input_line1[] = read.readLine().trim().split("\\s+");
            int c = 0;
            for(int i=0;i<n;i++){
                for(int j = 0;j<n;j++){
                    arr[i][j] = Integer.parseInt(input_line1[c]);
                    c++;
                }
            }
            Solution obj = new Solution();
            System.out.println(obj.numberOfPath(n, k, arr));
        }
    }
}

// } Driver Code Ends


class Solution {
    long numberOfPath(int n, int k, int [][]arr) {
        // code here
        long[][][] t = new long[n+1][n+1][k+1];
        for(long[][] layer: t)
            for(long[] row : layer)
                Arrays.fill(row,-1);
        return solve(arr,k,n-1,n-1,t);
            
    }
    
    long solve(int[][] arr, int k,int i, int j, long[][][] t) {
        
        if(i<0 || j<0 || k<0)
            return 0;
        if(i==0 && j==0 && arr[i][j]==k)    
            return 1;
        if(t[i][j][k] != -1)
            return t[i][j][k];
        return t[i][j][k] = solve(arr,k-arr[i][j],i-1,j,t) + solve(arr,k-arr[i][j],i,j-1,t);    
    }
}