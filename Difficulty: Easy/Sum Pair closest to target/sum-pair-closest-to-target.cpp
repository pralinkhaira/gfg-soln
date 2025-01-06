//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        
        sort(arr.begin(), arr.end());
        
        int i = 0;
        int j = arr.size() - 1;
        int min_diff = INT_MAX;
        vector<int> res;
        while (i < j){
        
            
            int diff = target - arr[i] - arr[j];
            
            if (abs(diff) < min_diff){
                min_diff = abs(diff);
                res = {arr[i], arr[j]};
            }
            
            if (min_diff == 0) return res;
            
            
            if (diff > 0) i++;
            if (diff < 0) j--;
        }
        return res;
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
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends