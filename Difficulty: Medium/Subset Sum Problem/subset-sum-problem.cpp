//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    /*bool func(int ind, int sum, vector<int>& arr, vector<vector<int>> &dp){
        if(sum==0) return true;
        if(ind==0){
            if(arr[0]==sum) return true;
            else return false;
        }
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        bool nottake= func(ind-1, sum, arr, dp);
        bool take= false;
        if(arr[ind]<=sum){
            take= func(ind-1, sum-arr[ind], arr, dp);
        }
        if(take==true || nottake==true) return dp[ind][sum]=true;
        return dp[ind][sum]= false;
    }*/
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n= arr.size();
        vector<vector<bool>> dp(n, vector<bool> (sum+1, false));
        for(int i=0; i<n; i++){
            dp[i][0]= true;
        }
        dp[0][arr[0]]=true;
        for(int ind=1; ind<n; ind++){
            for(int j=1; j<=sum; j++){
                bool nottake= dp[ind-1][j];
                bool take= false;
                if(arr[ind]<=j){
                    take= dp[ind-1][j-arr[ind]];
                }
                if(take==true || nottake==true) dp[ind][j]=true;
                else dp[ind][j]= false;
            }
        }
        return dp[n-1][sum];
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends