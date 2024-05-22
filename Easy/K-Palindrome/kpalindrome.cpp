//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int kPalindrome(string str, int n, int k)
    {
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int start=n-1;start>=0;start--){
            for(int end=start+1;end<n;end++){
                if(str[start]==str[end]){
                    dp[start][end]=dp[start+1][end-1];
                }else{
                    int prev1=1e8;
                    int prev2=1e8;
                    if(start+1<n){
                        prev1=dp[start+1][end];
                    }
                    if(end-1>=0){
                        prev2=dp[start][end-1];
                    }
                    dp[start][end]=1+min(prev1,prev2);
                }
            }
        }
        int ans=dp[0][n-1];
        
        if(ans<=k){
            return 1;
        }else{
            return 0;
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends