//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        stack<int> st;
        for (const string& token : arr) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Pop the top two operands
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                
                // Perform the operation
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b); // Division rounds towards zero
            } else {
                // Push the operand onto the stack
                st.push(stoi(token));
            }
        }
        
        // The result will be the only element in the stack
        return st.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends