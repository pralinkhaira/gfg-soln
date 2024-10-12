//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int pairWithMaxSum(vector<int>& arr) {
        if (arr.size() < 2)
            return -1;

        int sum = 0;

        // Iterate through the array to find the maximum sum of consecutive pairs
        for (size_t i = 0; i < arr.size() - 1; i++) {
            sum = max(sum, arr[i] + arr[i + 1]);
        }

        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();

    while (tc--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> a;
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution obj;
        int res = obj.pairWithMaxSum(a);
        cout << res << endl;
    }
}
// } Driver Code Ends