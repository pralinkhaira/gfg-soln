//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int solve(int ind, int sum, string &str, int n, vector<vector<int>>&dp){
	    if(ind==n) return 1;
	    if(dp[ind][sum]!=-1) return dp[ind][sum];
	    int ans=0, curr=0;
	    for(int i=ind;i<n;i++){
	        curr+=str[i]-'0';
	        if(curr>=sum){
	            ans+=solve(i+1, curr, str, n, dp);
	        }
	    }
	    return dp[ind][sum]=ans;
	}
	
	int TotalCount(string str){
	    // Code here
	    int n=str.length();
	    vector<vector<int>>dp(n+1, vector<int>(9*n+1,-1));
	    return solve(0, 0, str, n,dp);
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends