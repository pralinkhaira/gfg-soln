//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
//   int fib(int n){
      
//       if(n==0||n==1){
//           return n;
//       }
      
//       return fib(n-1)+fib(n-2);
//   }
    vector<int> Series(int n) {
        // Code here
        vector<int> ans(n+1);
        // for(int i=0;i<=n;i++){
        //     ans.push_back(fib(i));
        // }
        
        // return ans;
        
        ans[0]=0;
        ans[1]=1;
        for(int i=2;i<=n;i++){
            ans[i]=(ans[i-1]+ans[i-2])%1000000007;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends