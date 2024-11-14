//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
         priority_queue<int, vector<int>,
        greater<int>> minH;
        int j = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(minH.size() == k) {
                minH.push(arr[i]);
                arr[j++] = minH.top();
                minH.pop();
            }
            else minH.push(arr[i]);
        }
        while(minH.size() > 0) {
            arr[j++] = minH.top();
            minH.pop();
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        obj.nearlySorted(arr, k);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        // cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends