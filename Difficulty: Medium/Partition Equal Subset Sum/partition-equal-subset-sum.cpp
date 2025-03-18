//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
     int solve(vector<int>&arr,int sum){
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(j == 0){
                    dp[i][j] = 1;
                }
                else if(i != 0 and j >= arr[i-1]){
                    dp[i][j] = (dp[i-1][j]|dp[i-1][j-arr[i-1]]);
                }
                else if(i != 0){
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
    bool equalPartition(vector<int>& arr) {
        int sum = 0;
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
        }
        if((sum&1)){
            return false;
        }
        return solve(arr,sum/2);
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

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends