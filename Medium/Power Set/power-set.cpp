//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void fun(int ind, string &s, string x, vector<string> &v)
	    {
	        if(ind==s.size())
	        {
	            if(x!="")v.push_back(x);
	            return;
	        }
	        
	        fun(ind+1,s,x+s[ind],v);
	        fun(ind+1,s,x,v);
	    }
		vector<string> AllPossibleStrings(string s)
		{
		    // Code here
		    
		    vector<string> v;
		    string x;
		    fun(0,s,x,v);
		    
		    sort(v.begin(),v.end());
		    
		    return v;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends