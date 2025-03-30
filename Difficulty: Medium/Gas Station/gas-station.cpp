//{ Driver Code Starts
// C++ program to find union of
// two sorted arrays
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


/*You are required to complete this method*/
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int total = 0;
        int req = 0;
        
        // Calculate total gas and cost
        for (int i = 0; i < cost.size(); i++) {
            req += cost[i];
            total += gas[i];
        }
        
        // If total gas is less than required cost, return -1
        if (total < req) return -1;
        
        int ans = 0;
        int currgas = 0;
        
        // Find the valid starting station
        for (int i = 0; i < gas.size(); i++) {
            currgas += gas[i] - cost[i];
            if (currgas < 0) {
                ans = i + 1;  // Move to the next station
                currgas = 0;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
/* Driver program to test above function */
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {

        vector<int> gas, cost;
        string input1;
        getline(cin, input1);
        stringstream ss(input1);
        int number1;
        while (ss >> number1) {
            gas.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream sss(input2);
        int number2;
        while (sss >> number2) {
            cost.push_back(number2);
        }
        Solution ob;
        int ans = ob.startStation(gas, cost);

        cout << ans << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends