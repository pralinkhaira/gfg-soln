//{ Driver Code Starts
//Initial Template for JAVA

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(read.readLine());
            
            String S[] = read.readLine().split(" ");
            
            ArrayList<Integer> arr = new ArrayList<>();
            
            for(int i=0; i<n; i++)
                arr.add(Integer.parseInt(S[i]));

            Solution ob = new Solution();
            ArrayList<ArrayList<Integer>> res = ob.uniquePerms(arr,n);
            for(int i=0; i<res.size(); i++)
            {
                for(int j=0; j<n; j++)
                {
                    System.out.print(res.get(i).get(j) + " ");
                }
                System.out.println();
            }
        }
    }
}
// } Driver Code Ends

class Solution {
   
    
    public static void check(int ind,ArrayList<Integer>arr,int n,HashSet<ArrayList<Integer>>st){
        if(ind==n-1){
            st.add(new ArrayList<>(arr));
            return;
        }
        for(int i=ind;i<n;i++){
            Collections.swap(arr, i, ind);
            check(ind+1,arr,n,st);
            Collections.swap(arr, i, ind);
        }
    }
    static ArrayList<ArrayList<Integer>> uniquePerms(ArrayList<Integer> arr , int n) {
        Collections.sort(arr);   

        HashSet<ArrayList<Integer>>st=new HashSet<>();
        check(0,arr,n,st);
        
        
        ArrayList<ArrayList<Integer>>res=new ArrayList<>(st);
         res.sort((a, b) -> {
            for (int i = 0; i < a.size(); i++) {
                int cmp = a.get(i).compareTo(b.get(i));
                if (cmp != 0) {
                    return cmp;
                }
            }
            return 0;
        });
        return res;
    }
};