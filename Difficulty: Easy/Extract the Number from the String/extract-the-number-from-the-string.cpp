//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string s) {

        // code here
         long long cur=0;
     long long ans=0;
     for(int i=0;i<s.size();)
     {
        while(i<s.size() && s[i]-'0'>=0 && s[i]-'0'<=9)
         {
             if(s[i]=='9') 
                {   
                    cur=0;
                while(i<s.size())
                    {
                        if(s[i]==' ')
                        break;
                        i++;
                    }
                    break;
                }
             cur=cur*10+s[i]-'0';
             i++;
         }
if(ans<=cur) ans=cur;
             cur=0;
            i++;
     }
     if(ans==0)
        return -1;
    return ans;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends