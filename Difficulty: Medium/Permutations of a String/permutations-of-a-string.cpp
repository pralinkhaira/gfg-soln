//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void swap(int a, int b, string &v){
        int temp = v[a];
        v[a] = v[b];
        v[b] = temp;
    }
    void foo(string s, set<string>&ans, int p){
        
        if(p==s.size()){
            string v="";
            for(int i=0;i<s.size();i++){
                v+=s[i];
            }
            ans.insert(s);
            return;
        }
        
        for(int j=p;j<s.size();j++){
            
            swap(j, p, s);
            
            foo(s,ans, p+1);
            swap(j, p, s);
        }
    }
  
    vector<string> findPermutation(string &s) {
        // Code here there
        
        set<string>ans;
        vector<string>v;
        foo(s,ans, 0);
        for(auto a: ans)v.push_back(a);
        return v;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends