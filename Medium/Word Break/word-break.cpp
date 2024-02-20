//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings
class Solution
{
public:
    int wordBreak(int N, string s, vector<string> &dictionary) {
        //code here
        int n = s.size();
        vector<int> dp(n + 1);
        dp[n] = true;
        
        for(int i = n - 1; i >= 0; i--) 
        {
            for(auto word: dictionary) 
            {
                if(i + word.size() <= n and s.substr(i, word.size()) == word and dp[i + word.size()])
                    dp[i] = true;
            }
        }
        
        return dp[0];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends