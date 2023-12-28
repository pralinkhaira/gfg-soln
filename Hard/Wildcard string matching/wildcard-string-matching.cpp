//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool match(string p, string s)
    {
        int n = s.size(), m = p.size(), j = 0, asterick = -1, prev = 0;
        for (int i = 0; i < n; i++)
        {
            if (j < m && p[j] == '*')
            {
                prev = i;
                asterick = j++;
                i--;
            }
            else if (j < m && (s[i] == p[j]) || (p[j] == '?'))
            j++;
            else if (asterick >= 0)
            {
                i = prev++;
                j = asterick + 1;
            }
            else
            return false;
        }
        while (j < m && p[j] == '*')
        j++;
        return j == m;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends