//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
int mod=1e9+7;
class Solution
{
    public:
    int help(int i,int j,vector<vector<int>>& memo)
    {
        //base case
        if(i==0 and j==0)
        return 1;
        
        if(i<0 or j<0)
        return 0;
        
        //memo check
        if(memo[i][j]!=-1)
        return memo[i][j];
        
        //recursive calls
        //and small calculation
        int a=help(i-1,j,memo);
        int b=help(i,j-1,memo);
        
        return memo[i][j]=(a+b)%mod;
    }
    int ways(int x, int y)
    {
        vector<vector<int>> memo(x+1,vector<int>(y+1,-1));
        return help(x,y,memo);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends