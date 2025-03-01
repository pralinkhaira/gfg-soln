//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        // code here
        int n = s.length();
        if(n == 0) return s; 

        stack<int> st; 
        stack<string> str; 
        string temp = "";
        int num = 0; 

        for(int i = 0; i < n; i++) {
            if(isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            else if(s[i] == '[') {
                st.push(num);
                num = 0; 
                str.push(temp);
                temp = ""; 
            }
            else if(s[i] == ']') {
                int k = st.top();
                st.pop();
                string currentString = str.top();
                str.pop();
                for(int j = 0; j < k; j++) {
                    currentString += temp;
                }
                temp = currentString;
            }
            else {
                temp += s[i];
            }
        }
        return temp;
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
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends