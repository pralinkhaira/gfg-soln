//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find hIndex
 int hIndex(std::vector<int>& citations) {
    std::sort(citations.begin(), citations.end()); // Sort citations in ascending order
    int n = citations.size();
    int hIndex = 0;
    for (int i = 0; i < n; i++) {
        int lc = n - i; // Number of papers with at least citations[i] citations
        if (citations[i] >= lc) {
            hIndex = lc;
            break;
        }
    }
    return hIndex;
}
};

//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.hIndex(arr);

        cout << result << endl;

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends