//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        vector<int> mem(2401);
        for(int i=0;i<arr.size();i++){
            mem[arr[i]]++;
            mem[dep[i]+1]--;
        }
        int cnt = 0;
        int ret = 0;
        for(int i=0;i<=2400;i++){
            cnt += mem[i];
            ret = max(ret, cnt);
        }
        
        return ret;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, dep;
        string input;

        // Read first array (arr)
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Read second array (dep)
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            dep.push_back(number);
        }

        // Assuming Solution class is defined elsewhere with a method findPlatform
        Solution ob;
        cout << ob.findPlatform(arr, dep);

        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends