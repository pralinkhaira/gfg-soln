//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        //return min(solve(cost,0),solve(cost,1));
        
        int n=cost.size();
        vector<int> memo(n,INT_MAX);
        return min(solve1(cost,0,memo),solve1(cost,1,memo));
    }
private:
    /*int solve(vector<int>& cost,int i){
        if(i>=cost.size()) return 0;
        int ones=solve(cost,i+1)+cost[i];
        int twos=solve(cost,i+2)+cost[i];
        //cout<<ones<<" "<<twos;
        return min(ones,twos);
    }*/
    int solve1(vector<int>& cost,int i,vector<int>& memo){
        if(i>=cost.size()) return 0;
        if(memo[i]!=INT_MAX) return memo[i];
        int ones=solve1(cost,i+1,memo)+cost[i];
        int twos=solve1(cost,i+2,memo)+cost[i];
        memo[i]=min(ones,twos);
        return memo[i];
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends