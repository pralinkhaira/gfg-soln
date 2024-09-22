//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
        public:
      int lps(string str) {
        // Your code goes here
        string combined = str;
        int i = 0, j = 1;
        vector<int>lps(combined.size(),0);
        while(j<combined.size()){
            if(combined[j] == combined[i]){
                lps[j++] = ++i;
            }else if(!i){
                j++;
            } else {
                i = lps[i-1];
            }
        }
        return lps[lps.size()-1];
    }


};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends