//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &arr, vector<int> &profit) {
        // code here
        int n = arr.size();
        vector<pair<int, int>> p;
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            p.push_back({profit[i], arr[i]}); // Corrected access
            maxi = max(maxi, arr[i]);
        }

        sort(p.rbegin(), p.rend());
        set<int> s;
        for (int i = 1; i <= maxi; i++) {
            s.insert(i);
        }

        int sum = 0, cnt = 0;

        for (int i = 0; i < p.size(); i++) {
            if (s.empty()) break;
            auto it = s.upper_bound(p[i].second);

            if (it != s.begin()) {
                it--;
                sum += p[i].first;
                cnt++;
                s.erase(it);
            }
        }

        return {cnt, sum};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends