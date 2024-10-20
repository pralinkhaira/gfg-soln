//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    int countgroup(vector<int>& a) {
        int n = a.size();
        int ans = 0, mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            ans ^= a[i];
        }
        if (ans == 0) {
            long long val = 1; 
            for (int i = 0; i < n - 1; i++) {
                val = (val * 2) % mod; 
            }
            return (val - 1 + mod) % mod; 
        } else {
            return 0; 
        }
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int ans = obj.countgroup(arr);
        cout << ans << endl;
    }
}

// } Driver Code Ends