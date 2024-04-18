//{ Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	      vector<int> lps(s.length(),0);
        int l=0,r=1;
        
        while(r<s.length()){
            if(s[l] == s[r]){
                lps[r] = l + 1;
                l++;
                r++;
            }
            else{
                if(l == 0){
                    r++;
                } else{
                    l=lps[l-1];
                }
                
                
            }
            
        }
        
        return lps.back();
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
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends