//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            
            String input[] = read.readLine().split(" ");
            String a = input[0];
            
            Solution ob = new Solution();
            if(ob.sameFreq(a)){
                System.out.println(1);
            }
            else{
                System.out.println(0);
            }
        }
    }
}
// } Driver Code Ends

class Solution {
    boolean sameFreq(String s) {
        // code here
        HashMap<Character,Integer> m = new HashMap<>();
        HashMap<Integer,Integer> ml = new HashMap<>();
        HashSet<Integer> h = new HashSet<>();
        for(int i=0;i<s.length();i++){
            m.put(s.charAt(i),m.getOrDefault(s.charAt(i),0)+1);
        }
        for(char x :m.keySet()){
            h.add(m.get(x));
            ml.put(m.get(x),ml.getOrDefault(m.get(x),0)+1);
        }
        if(h.size() > 2){
            return false;
        }
        if(h.size() == 1){
            return true;
        }
        ArrayList<Integer> l = new ArrayList<>(h);
        if(Math.abs(l.get(0) - l.get(1)) == 1){
            if(l.get(0) > l.get(1)){
                if(ml.get(l.get(0)) == 1){
                    return true;
                }
            }
            else{
                if(ml.get(l.get(1)) == 1){
                    return true;
                }
            }
        }
        if((l.get(0)==1 || l.get(1)==1) && ml.get(1) == 1){
            return true;
        }
        return false;
    }
}