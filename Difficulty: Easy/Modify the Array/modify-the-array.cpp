//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        int n = arr.size();
        
        // Step 1: Modify the array by doubling the current number if it equals the next one.
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] != 0 && arr[i] == arr[i + 1]) {
                arr[i] *= 2;     // Double the current number
                arr[i + 1] = 0;  // Set the next number to 0
            }
        }
        
        // Step 2: Rearrange the array, moving all non-zero numbers to the front.
        int index = 0;  // Pointer to place the next non-zero element
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                arr[index] = arr[i];  // Move non-zero element forward
                index++;
            }
        }
        
        // Step 3: Fill the remaining part of the array with zeros.
        while (index < n) {
            arr[index] = 0;
            index++;
        }
        
        return arr;
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
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends