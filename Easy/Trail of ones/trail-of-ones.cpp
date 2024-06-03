//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     int numberOfConsecutiveOnes(int n) {
        vector<long long int> dp(n+1, 0);               
        const int M = 1e9+7;
        int p=1;
        for(int i=2; i<=n; i++){
        dp[i] = ((dp[i-1]+dp[i-2])%M+p)%M;
        p = (p*2)%M;
        } 
        return static_cast<int>(dp[n]);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends