//{ Driver Code Starts
//Initial template for JAVA

import java.util.*;
import java.io.*;
import java.lang.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());

        while (t-- > 0) {
            ArrayList<ArrayList<Integer>> list = new ArrayList<>();
            String st[] = read.readLine().trim().split("\\s+");
            int n = Integer.parseInt(st[0]);
            int m = Integer.parseInt(st[1]);

            for (int i = 0; i < n; i++)
                list.add(i, new ArrayList<Integer>());

            ArrayList<ArrayList<Integer>> prerequisites = new ArrayList<>();
            for (int i = 1; i <= m; i++) {
                String s[] = read.readLine().trim().split("\\s+");
                int u = Integer.parseInt(s[0]);
                int v = Integer.parseInt(s[1]);
                list.get(v).add(u);
                ArrayList<Integer> pair = new ArrayList<>();
                pair.add(u);
                pair.add(v);
                prerequisites.add(pair);
            }

            int[] res = new Solution().findOrder(n, m, prerequisites);
            
            if(res.length==0)
                System.out.println("No Ordering Possible");
            else
            {
                if (check(list, n, res) == true)
                    System.out.println("1");
                else
                    System.out.println("0");
            }
        }
    }
    static boolean check(ArrayList<ArrayList<Integer>> list, int V, int[] res) {
        int[] map = new int[V];
        for (int i = 0; i < V; i++) {
            map[res[i]] = i;
        }
        for (int i = 0; i < V; i++) {
            for (int v : list.get(i)) {
                if (map[i] > map[v]) return false;
            }
        }
        return true;
    }
}

// } Driver Code Ends
class Solution
{
    static boolean[] vis;
    static int[] in;
    static ArrayList<Integer>[] g; 
    static Queue<Integer> q; 
    static ArrayList<Integer> a; 
    
    
    static void graph(ArrayList<ArrayList<Integer>> p){
        for(int i=0;i<p.size();i++){
            g[p.get(i).get(1)].add(p.get(i).get(0));
            in[p.get(i).get(0)]++;
        }
    }
    
    
    static int[] topo(){
        
         for(int i=0;i<in.length;i++){
            if(in[i]==0){
                q.add(i);
                vis[i]=true;
            } 
         }
         
         while(!q.isEmpty()){
            int x=q.remove();
            a.add(x);
            for(int i=0;i<g[x].size();i++){
                in[g[x].get(i)]--;
                if(!vis[g[x].get(i)] && in[g[x].get(i)]==0){
                vis[g[x].get(i)]=true;
                q.add(g[x].get(i));
                }
            }
            
         }
        int[] arr=new int[in.length];
         
         if(a.size()==in.length){
            for(int i=0;i<a.size();i++) arr[i]=a.get(i);
            return arr;
         }
         arr=new int[0];
         return arr;
    }
    
    
    static int[] findOrder(int n, int m, ArrayList<ArrayList<Integer>> prerequisites) 
    {
        vis=new boolean[n];
        in=new int[n];
        g=new ArrayList[n];
        a=new ArrayList();
        q=new LinkedList();
        for(int i=0;i<n;i++)
            g[i]=new ArrayList();
            
        graph(prerequisites);  
       
        return topo();
        
            
    }
}