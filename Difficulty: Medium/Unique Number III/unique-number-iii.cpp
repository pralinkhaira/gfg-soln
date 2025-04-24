//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int getSingle(vector<int> &arr) {
        int ones = 0, twos = 0, mask;

        for (int num : arr) {

            // Bits in both 'ones' and current number
            twos |= ones & num;

            // XOR to get odd frequency bits
            ones ^= num;

            // Remove common bits (appear 3 times)
            mask = ~(ones & twos);
            ones &= mask;
            twos &= mask;
        }

        return ones;
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
        int ans = ob.getSingle(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends