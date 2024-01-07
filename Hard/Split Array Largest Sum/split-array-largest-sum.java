//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            
            String St[] = read.readLine().split(" ");
            
            int N = Integer.parseInt(St[0]);
            int K = Integer.parseInt(St[1]);
            
            String S[] = read.readLine().split(" ");
            
            int[] arr = new int[N];
            
            for(int i=0 ; i<N ; i++)
                arr[i] = Integer.parseInt(S[i]);

            Solution ob = new Solution();
            System.out.println(ob.splitArray(arr,N,K));
        }
    }
}
// } Driver Code Ends

class Solution {
    
    static boolean possible(int[] arr, int k, int sum) {
        int curSum = 0;
        
        for (int i = 0; i < arr.length && k > 0; i++) {
            if (arr[i] > sum) {
                return false;
            } else if (arr[i] + curSum <= sum) {
                curSum += arr[i];
            } else {
                curSum = arr[i];
                k--;
            }
        }
        
        return k > 0;
    }
    
    static int splitArray(int[] arr, int N, int K) {
        int l = 0, h = 1000000000, ans = -1;
        
        while (l <= h) {
            int mid = (l + h) >>> 1;
            
            if (possible(arr, K, mid)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return ans;
    }
}
