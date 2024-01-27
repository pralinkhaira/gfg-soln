//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class GFG
{
    private static int get(int[] p, int n) {
        int[][] m = new int[n][n];
        int ans = 1000000000;

        for (int i = 1; i < n; i++)
            m[i][i] = 0;

        for (int L = 2; L < n; L++) {
            for (int i = 1; i < n - L + 1; i++) {
                m[i][i + L - 1] = Integer.MAX_VALUE;

                for (int k = i; k <= i + L - 2; k++) {
                    int q = m[i][k] + m[k + 1][i + L - 1] + p[i - 1] * p[k] * p[i + L - 1];

                    if (q < m[i][i + L - 1]) {
                        m[i][i + L - 1] = q;
                    }
                }
            }
        }

        return m[1][n - 1];
    }

    private static int find(String s, int[] p) {
        List<int[]> arr = new ArrayList<>();
        int ans = 0;

        for (char t : s.toCharArray()) {
            if (t == '(') {
                arr.add(new int[]{-1, -1});
            } else if (t == ')') {
                int[] b = arr.remove(arr.size() - 1);
                int[] a = arr.remove(arr.size() - 1);
                arr.remove(arr.size() - 1);
                arr.add(new int[]{a[0], b[1]});
                ans += a[0] * a[1] * b[1];
            } else {
                arr.add(new int[]{p[t - 'A'], p[t - 'A' + 1]});
            }
        }

        return ans;
    }

    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            int n = Integer.parseInt(in.readLine());
            String a[] = in.readLine().trim().split("\\s+");
            int p[] = new int[n];
            for(int i = 0;i < n;i++)
                p[i] = Integer.parseInt(a[i]);
            
            Solution ob = new Solution();
            String result=ob.matrixChainOrder(p, n);
            if(get(p,n)==find(result,p))
            {
                System.out.println("True");
            }
            else
            {
                System.out.println("False");
            }
        }
    }
}
// } Driver Code Ends

class Solution{
    static String matrixChainOrder(int p[], int n){
        // code here
        int[][] m = new int[n][n];
        int[][] s = new int[n][n];

        // m[i][i] is zero as the cost of multiplying one matrix is zero
        for (int i = 1; i < n; i++) {
            m[i][i] = 0;
        }

        // L is chain length
        for (int L = 2; L < n; L++) {
            for (int i = 1; i < n - L + 1; i++) {
                int j = i + L - 1;
                m[i][j] = Integer.MAX_VALUE;
                for (int k = i; k < j; k++) {
                    int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                    if (cost < m[i][j]) {
                        m[i][j] = cost;
                        s[i][j] = k;
                    }
                }
            }
        }

        // Constructing the output string
        return printOptimalParens(s, 1, n - 1);
    }

    static String printOptimalParens(int[][] s, int i, int j) {
        if (i == j) {
            return String.valueOf((char)('A' + i - 1)); // Naming matrices as 'A', 'B', 'C', etc.
        } else {
            return "(" + printOptimalParens(s, i, s[i][j]) + printOptimalParens(s, s[i][j] + 1, j) + ")";
        }
    
    }
}

