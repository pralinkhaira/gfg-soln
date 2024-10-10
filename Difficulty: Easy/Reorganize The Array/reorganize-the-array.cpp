//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> rearrange(const vector<int>& arr) {
        unordered_map<int,int> mp;
        
        int n = arr.size();
        for(int i=0; i<n; i++){
            if(arr[i] >= 0) 
             mp[arr[i]]++;
        }
        
        vector<int> ans;
        
        for(int i=0; i<n; i++) {
            if(mp.find(i) != mp.end()){
                ans.push_back(i);
            }
            else{
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution solution;
        vector<int> ans = solution.rearrange(arr);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends