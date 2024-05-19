//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    long long f(long long n,long long p,long long M){
        if(p==0)return 1;
        if(p==1)return n%M;
        long long ans=f(n,p/2,M);
        ans=ans%M * ans%M;
        if(p&1)ans=(ans * n)%M;
        return ans%M;
    }
	public:
	long long int PowMod(long long int x,long long int n,long long int M)
	{
		 return f(x,n,M);
	}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends