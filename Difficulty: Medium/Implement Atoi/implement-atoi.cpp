//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
        long long sum = 0;
        int flag = 1;
        int i = 0;

        while (s[i] == ' ') 
            i++;


        if (s[i] == '-' || s[i] == '+') 
        {
            flag = (s[i] == '-') ? -1 : 1;
            i++;
        }
    

        while (s[i] >= '0' && s[i] <= '9') 
        {
            sum = sum * 10 + (s[i] - '0');
    
            if (flag == 1 && sum >= INT_MAX) 
                return INT_MAX;
            
            else if (flag == -1 && sum > INT_MAX) 
                return INT_MIN;
            
    
            i++;
        }

        return (int)(flag * sum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends