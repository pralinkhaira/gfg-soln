//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<char>st;
        for(char c:s){
            if(st.empty()) st.push(c);
            else if((st.top()=='('&&c==')')||(st.top()=='{'&&c=='}')||
            (st.top()=='['&&c==']')){
                st.pop();
            }else{
                st.push(c);
            }
        }
        if(st.empty()){
            return true;
        }else{
            return false;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends