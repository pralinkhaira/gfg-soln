//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++ 
        

        
    
        
        
        int maxProfit(vector<int>& price) {
    //Tabulation Apporach
    int n = price.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));
    for(int idx = n-1;idx>=0;idx--){
        for(int isBuying = 0;isBuying<=1;isBuying++){
            for(int tsc = 0;tsc<=2;tsc++){
                if (isBuying && tsc < 2) {
                    int pick = -price[idx] + dp[idx + 1][0][tsc];
                    int notPick = dp[idx + 1][1][tsc]; 
                    dp[idx][isBuying][tsc] = max(pick, notPick);
                }else  if (!isBuying && tsc < 2) {
                    int pick = price[idx] + dp[idx + 1][1][tsc+1];
                    int notPick = dp[idx + 1][0][tsc]; 
                    dp[idx][isBuying][tsc] = max(pick, notPick);
                }
            }
        }
    }
    return dp[0][1][0];
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends