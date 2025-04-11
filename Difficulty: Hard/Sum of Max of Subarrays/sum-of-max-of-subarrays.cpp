//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int sumOfMax(vector<int> &arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] < arr[i]) s.pop();
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        while (!s.empty()) s.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] <= arr[i]) s.pop();
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int count = (i - left[i]) * (right[i] - i);
            sum += (long long)arr[i] * count;
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int result = ob.sumOfMax(arr);
        cout << result;
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends