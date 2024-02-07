//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    void dfs(int node,vector<vector<pair<int,int>>> &g,int &mw,int &end,int vis[]){
        vis[node]=1;
        for(auto e:g[node]){
            if(vis[e.first]==0){
                mw=min(mw,e.second);
                end=e.first;
                dfs(e.first,g,mw,end,vis);
            }
        }
    }
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        int vis[n+1]={0};
        vector<vector<int>> ans;
        vector<int> in(n+1,0);
        vector<int> out(n+1,0);
        vector<vector<pair<int,int>>> g(n+1);
        for(int i=0;i<p;i++){
            in[b[i]]=1;
            out[a[i]]=1;
            g[a[i]].push_back({b[i],d[i]});
        }
        for(int i=1;i<=n;i++){
            if(in[i]==0&&out[i]==1 and vis[i]==0){
                int s=i;
                int e;
                int mw=INT_MAX;
                dfs(i,g,mw,e,vis);
                ans.push_back({s,e,mw});
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends