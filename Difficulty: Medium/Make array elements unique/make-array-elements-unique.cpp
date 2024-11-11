//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        // Code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int lastNum = arr[0];
        int steps = 0;
        for(int i=1; i<n; ++i) {
            if(lastNum < arr[i]) {
                lastNum = arr[i];
            } else {
                ++lastNum;
                steps += (lastNum - arr[i]);
            }
        }
        
        return steps;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends