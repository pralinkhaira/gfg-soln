//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int dp[100001][3][2];
  int solve(vector<int>&prices,int k,int ind,int flag)
  {
      if(k==0 && flag==0)
      return 0;
      if(ind==prices.size())
      return 0;
      else if(dp[ind][k][flag]!=-1)
      return dp[ind][k][flag];
      else
      {
          if(flag==0)
          {
              int take=-prices[ind]+solve(prices,k-1,ind+1,1);
              int notake=solve(prices,k,ind+1,0);
              return dp[ind][k][flag]=max(take,notake);
          }
          else
          {
              int take=prices[ind]+solve(prices,k,ind+1,0);
              int notake=solve(prices,k,ind+1,1);
              return dp[ind][k][flag]=max(take,notake);
          }
      }
      
      
  }
    int maxProfit(vector<int> &prices) {
        memset(dp,-1,sizeof(dp));
        return solve(prices,2,0,0);
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends