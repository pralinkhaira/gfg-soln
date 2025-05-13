//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int r = sc.nextInt();
            Solution ob = new Solution();
            System.out.println(ob.nCr(n, r));
            System.out.println("~");
        }

        sc.close();
    }
}
// } Driver Code Ends


class Solution {
    public int nCr(int n, int r) {
        // code here
        if(r > n || r < 0){
            return 0;
        }
        
        if(r > n-r){
            r = n-r;
        }
        
        long bio_coff = 1;
        for(int i=1; i<=r; i++){
            bio_coff *= (n-i+1);
            bio_coff /=i;
        }
        return (int) bio_coff;
            
    }
}