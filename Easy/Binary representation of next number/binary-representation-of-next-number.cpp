//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
         int num = 0, n = s.size(), zero = false;
        
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '0') {
                s[i] = '1';
                zero = true;
                break;
            } else
                s[i] = '0';
        }
        
        if(!zero)
            s = '1' + s;
            
        int i = 0;
        while(i < s.size() and s[i] == '0')
            i++;
        
        return s.substr(i);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends