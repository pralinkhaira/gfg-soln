//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int longestStringChain(vector<string>& words) {
       int ans=1;
        vector<unordered_set<string>> arr(11);
        unordered_map<string, int> m;
        for(auto &s:words) {
            if(s.size()==1) m[s]=1;
            arr[s.size()].insert(s);
        }
        for(int i=2;i<=10;i++) {
            for(auto &s:arr[i]) {
                m[s]=1;
                for(int j=0;j<s.size();j++) {
                    string ns=s.substr(0,j) + s.substr(j+1);
                    if(arr[i-1].count(ns)) m[s]=max(m[s],1+m[ns]);
                    ans=max(ans, m[s]);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends