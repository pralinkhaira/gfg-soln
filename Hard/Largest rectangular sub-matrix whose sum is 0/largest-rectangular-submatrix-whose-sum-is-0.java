//{ Driver Code Starts
import java.io.*;
import java.util.*;


class IntArray
{
    public static int[] input(BufferedReader br, int n) throws IOException
    {
        String[] s = br.readLine().trim().split(" ");
        int[] a = new int[n];
        for(int i = 0; i < n; i++)
            a[i] = Integer.parseInt(s[i]);
        
        return a;
    }
    
    public static void print(int[] a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }
    
    public static void print(ArrayList<Integer> a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }
}


class IntMatrix
{
    public static int[][] input(BufferedReader br, int n, int m) throws IOException
    {
        int[][] mat = new int[n][];
        
        for(int i = 0; i < n; i++)
        {
            String[] s = br.readLine().trim().split(" ");
            mat[i] = new int[s.length];
            for(int j = 0; j < s.length; j++)
                mat[i][j] = Integer.parseInt(s[j]);
        }
        
        return mat;
    }
    
    public static void print(int[][] m)
    {
        for(var a : m)
        {
            for(int e : a)
                System.out.print(e + " ");
            System.out.println();
        }
    }
    
    public static void print(ArrayList<ArrayList<Integer>> m)
    {
        for(var a : m)
        {
            for(int e : a)
                System.out.print(e + " ");
            System.out.println();
        }
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            
            int[] nm = IntArray.input(br, 2);
            
            
            int[][] a = IntMatrix.input(br, nm[0], nm[1]);
            
            Solution obj = new Solution();
            ArrayList<ArrayList<Integer>> res = obj.sumZeroMatrix(a);
            
            if(res.size() == 0) {
                System.out.println(-1);
                
            } else {
            
                IntMatrix.print(res);
            }        
        }
    }
}

// } Driver Code Ends

class Solution {
    public static ArrayList<ArrayList<Integer>> sumZeroMatrix(int[][] a) {
        // code here
        
        int n = a.length;
        int m = a[0].length;

        int[][] prefixSum = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefixSum[i][j] = a[i][j];
                if (i > 0) {
                    prefixSum[i][j] += prefixSum[i - 1][j];
                }
                if (j > 0) {
                    prefixSum[i][j] += prefixSum[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    prefixSum[i][j] -= prefixSum[i - 1][j - 1];
                }
            }
        }

        int maxSize = 0;
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();

        for (int c1 = 0; c1 < m; c1++) {
            for (int c2 = c1; c2 < m; c2++) {
                for (int r1 = 0; r1 < n; r1++) {
                    for (int r2 = r1; r2 < n; r2++) {

                        int sum = prefixSum[r2][c2];
                        if (r1 > 0) {
                            sum -= prefixSum[r1 - 1][c2];
                        }
                        if (c1 > 0) {
                            sum -= prefixSum[r2][c1 - 1];
                        }
                        if (r1 > 0 && c1 > 0) {
                            sum += prefixSum[r1 - 1][c1 - 1];
                        }

                        if (sum == 0 && (r2 - r1 + 1) * (c2 - c1 + 1) > maxSize) {
                            maxSize = (r2 - r1 + 1) * (c2 - c1 + 1);
                            result.clear();
                            for (int i = r1; i <= r2; i++) {
                                ArrayList<Integer> row = new ArrayList<>();
                                for (int j = c1; j <= c2; j++) {
                                    row.add(a[i][j]);
                                }
                                result.add(row);
                            }
                        }
                    }
                }
            }
        }

        return result;
    }
}    
