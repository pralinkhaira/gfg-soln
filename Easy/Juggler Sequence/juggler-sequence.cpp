//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<long long>res;
  void solve(long long n){
      if(n==1){
          res.push_back(n);
          return;
      }
      res.push_back(n);
      if(n&1) solve(n*sqrt(n));
      else solve(sqrt(n));
  }
    vector<long long> jugglerSequence(long long n) {
        solve(n);
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        Solution ob;
        vector<long long> ans = ob.jugglerSequence(n);
        for (long long u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends