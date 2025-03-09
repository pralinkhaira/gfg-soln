//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
  void solve(string &s,int i,int j, int &count){
        while(i>=0 && j<s.size() && s[i]==s[j]){
              if(j-i+1>=2)
                count++;
                
                i--;
                j++;
        }
        
    }
    int countPS(string &s) {
        // code here
        int n = s.size();
        int count = 0;
        
        for(int i=0;i<n;i++){
            solve(s,i,i,count);
            solve(s,i,i+1,count);
        }
        return count;
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
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends