//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int mod=1e9+7;
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        int n=s.length();
        vector<long long int> v(n);
        v[0]=s[0]-'0';
        long long int res=v[0];
        for(int i=1;i<n;i++)
        {
            v[i]=(((i+1)*(s[i]-'0'))%mod+(10*(v[i-1]))%mod)%mod;
            res+=v[i];
        }
        return res%mod;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends