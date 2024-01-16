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
            String input_line[] = read.readLine().trim().split("\\s+");
            int m = Integer.parseInt(input_line[0]);
            int n = Integer.parseInt(input_line[1]);
            
            Solution ob = new Solution();
            System.out.println(ob.numberSequence(m, n));
        }
    }
}

// } Driver Code Ends

class Solution{
    static int helper(int index,int num,int m,int n){
        if(index>n||num>m){
            return 0;
        }
        if(index==n){
            if(num<=m){
                return 1;
            }
            return 0;
        }
        int pick=0;        
        for(int i=0;i<=m-num;i++){
            if(2*num+i<=m){
                pick+=helper(index+1,2*num+i,m,n);
            }            
        }
        return pick;
    }


    static int numberSequence(int m, int n)
    {
        // code here
        int count=0;
        for(int i=1;i<=m;i++){
            count+=helper(1,i,m,n);
        }
        return count;
    }

}