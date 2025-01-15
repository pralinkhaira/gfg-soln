//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
         unordered_map<int, int> prefixSum; // To store cumulative sums
    int sum = 0; // Current cumulative sum
    int maxLength = 0; // Longest subarray length

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i]; // Update the cumulative sum

        // If the cumulative sum equals k, update maxLength
        if (sum == k) {
            maxLength = i + 1;
        }

        // If (sum - k) is found in the map, update maxLength
        if (prefixSum.find(sum - k) != prefixSum.end()) {
            maxLength = max(maxLength, i - prefixSum[sum - k]);
        }

        // Store the cumulative sum in the map if not already present
        if (prefixSum.find(sum) == prefixSum.end()) {
            prefixSum[sum] = i;
        }
    }

    return maxLength;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends