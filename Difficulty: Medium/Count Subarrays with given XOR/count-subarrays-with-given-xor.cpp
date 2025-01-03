//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   long subarrayXor(vector<int> &arr, int k) {
    unordered_map<int, int> freq; // To store frequencies of prefix XORs
    int prefixXor = 0;
    long count = 0;

    for (int num : arr) {
        prefixXor ^= num; // Update the current prefix XOR
        
        // If the XOR of the entire subarray equals k
        if (prefixXor == k) {
            count++;
        }

        // Check if there exists a previous prefixXor such that
        // prefixXor ^ k == prefixXor_prev
        int target = prefixXor ^ k;
        if (freq.find(target) != freq.end()) {
            count += freq[target];
        }

        // Increment the frequency of the current prefix XOR
        freq[prefixXor]++;
    }

    return count;
}
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); // Push numbers into the vector
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after k

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends