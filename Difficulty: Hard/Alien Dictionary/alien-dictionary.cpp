//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    public:
    string ans;
    vector<bool> vis,cur;
    unordered_set<int> g[26]; // Graph
    
    void topological_sort(int r) {
        vis[r]=cur[r]=1;
        for(int i:g[r]) 
            if(!vis[i])
                topological_sort(i);
        
        ans=char(97+r)+ans;
        cur[r]=0;
    }
    
    string findOrder(string arr[], int N, int K) {
        ans="";
        vis.assign(26,0); 
        cur=vis;
      
         for(int i=1;i<N;i++) {
          string a=arr[i-1],b=arr[i];
          int l=0,n=min(a.size(),b.size());
          while(l<n && a[l]==b[l]) 
                l++;
          if(l!=n) g[a[l]-'a'].insert(b[l]-'a');
         }
      
       for(int i=0;i<K;i++)
            if(!vis[i])
                topological_sort(i);
        return ans;
    }
};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends