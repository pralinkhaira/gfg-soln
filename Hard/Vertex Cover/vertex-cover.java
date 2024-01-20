//{ Driver Code Starts
import java.io.*;
import java.util.*;


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
            
            int n; 
            n = Integer.parseInt(br.readLine());
            
            
            int m; 
            m = Integer.parseInt(br.readLine());
            
            
            int[][] edges = IntMatrix.input(br, m, 2);
            
            Solution obj = new Solution();
            int res = obj.vertexCover(n, m, edges);
            
            System.out.println(res);
            
        }
    }
}

// } Driver Code Ends

class Solution {

    static boolean isPsbl(int n, int m, int mid, List<List<Integer>> adjlst) {
        int base = (1 << mid) - 1;
        int last = 1 << n;

        while (base < last) {
            boolean[][] vis = new boolean[n + 1][n + 1];

            int ec = 0;

            for (int j = 1, u = 1; j < last; j = j << 1, u++) {
                if ((base & j) != 0) {
                    for (int v = 1; v <= n; v++) {
                        if (adjlst.get(u).contains(v) && !vis[u][v]) {
                            ec++;
                            vis[u][v] = true;
                            vis[v][u] = true;
                        }
                    }
                }
            }

            if (ec == m) return true;

            int rmst = base & -base;

            int res = base + rmst;

            base = (((res ^ base) >> 2) / rmst) | res;
        }

        return false;
    }

    public static int vertexCover(int n, int m, int[][] edges) {
        List<List<Integer>> ans = new ArrayList<>();

        for (int i = 0; i <= n; i++) {
            ans.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            ans.get(edge[0]).add(edge[1]);
            ans.get(edge[1]).add(edge[0]);
        }

        int l = 1, r = n;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (isPsbl(n, m, mid, ans)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
}     
