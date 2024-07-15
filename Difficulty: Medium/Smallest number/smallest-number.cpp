//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // codeGenius
        if((9*d)<s) return "-1";
        string ans="";
        for(int i= d-1;i>=0;i--){
            if(s>9){
                ans='9'+ans;
                s-=9;
            }
            else{
                if(i==0){
                    ans=to_string(s)+ans;
                }
                else{
            
                ans=to_string(s-1)+ans;
                i--;
                while(i>0){
                    ans='0'+ans;
                    i--;
                }
                ans='1'+ans;
                break;
                
            }
        }
    }
    return ans;
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
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends