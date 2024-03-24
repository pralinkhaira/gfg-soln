//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
void solve(int n, string t, int one,int zero,vector<string>&ans)
{
    if(t.size()==n)
    {
        ans.push_back(t);
        return;
    }
    if(one<n)
        solve(n,t+'1',one+1,zero,ans);
    if(zero<one)
        solve(n,t+'0',one,zero+1,ans);
}
	vector<string> NBitBinary(int n)
	{
	    vector<string>ans;
	    solve(n,"",0,0,ans);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends