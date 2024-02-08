//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    unordered_map<int, vector<int>> g;
    unordered_map<int, bool> vis;
    
    void dfs(int s)
    {
        vis[s]= true;
        for(auto i:g[s]) if(!vis[i]) dfs(i);
    }
    int isCircle(int N, vector<string> A)
    {
        // code here
        for(auto i:A)
        {
            g[i[0]].push_back(i.back());
            g[i.back()].push_back(i[0]);
        }
        
        int count = 0;
        for(auto i: g)
        {
            if(!vis[i.first]) dfs(i.first), count++;
        }
        if(count > 1) return 0; // if no. of graph is more than 1; 
        
        for(auto i:g) if((g[i.first].size())%2 != 0 ) return 0;
        return true;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends