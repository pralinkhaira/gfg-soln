//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
          int iz = 0 , jz = 0;
        int i = s1.size()-1, j = s2.size()-1 ,carry = 0;
        string res ="";
        while(s1[iz]=='0') iz++;
        while(s2[jz]=='0') jz++;
        while(i>=iz || j>=jz || carry){
            int n1 = 0 , n2 =0;
            if(i>=iz) n1 =s1[i] - '0';
            if(j>=jz) n2 =s2[j] - '0';
            int sum = n1 + n2 + carry;
            int digit = sum%2;
            carry = sum/2;
           res += ('0'+digit);
            i--;
            j--;
        }
        if(res.size()==0) return "0";
        reverse(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends