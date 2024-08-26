//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
    bool solve(string &str,string &ptr,int i ,int j, vector<vector<int>>&dp)
    {
        if(i<0 && j<0)
            return true;
            
        if(i>=0 && j<0)
            return false;
        
        if(i<0 && j>=0)
        {
            for(int k =0;k<=j;k++)
            {
                if(ptr[k] != '*')
                {
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(str[i]==ptr[j] || ptr[j]=='?')
            return dp[i][j]= solve(str,ptr,i-1,j-1,dp);
        else if(ptr[j]=='*')
            return dp[i][j]=  (solve(str,ptr,i-1,j,dp)|| solve(str,ptr,i,j-1,dp));
        else 
            return false;
        
    }
    
    int wildCard(string ptr, string str) {
        
        vector<vector<int>>dp(str.length(),vector<int>(ptr.length(),-1));
        // code here
        return solve(str,ptr,str.size()-1,ptr.size()-1,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends