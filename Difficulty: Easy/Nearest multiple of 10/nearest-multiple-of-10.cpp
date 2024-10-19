//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string add(string&s, int n){
        int i = s.size()-1;
        int c = n;
        string dum;
        while(i >= 0){
            int sum = s[i]-'0';
            sum += c;
            dum += ((sum%10)+'0');
            c = sum/10;
            i--;
        }
        if(c) dum += (c+'0');
        i = 0;int j = dum.size()-1;
        while(i<=j){
            swap(dum[i],dum[j]);
            i++; j--;
        }
        return dum;
    }
    string roundToNearest(string str) {
        // Complete the function
        int n = str.back()-'0';
        if(str.back() == '0') return str;
        if(str.back() <= '5') str.back() = '0';
        if(n>5) str = add(str,10-n);
        return str;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends