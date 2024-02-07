//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            if(i!=A.size()-1) cout << A[i]<< " ";
            else cout << A[i];
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    
    int check(string str){
        int len = 0;
        stack<char> s;
        for(int i = 0;i < str.size();i++){
            if(str[i] == '(')s.push('(');
            else if(str[i] == ')'){
                if(s.empty())len++;
                else s.pop();
            }
        }
        len += s.size();
        return len;
    }
    vector<string>ans;
    unordered_map<string,int>mp;
    void solve(string &str,int len){
        if(mp.find(str) != mp.end())return;
        else mp[str]++;
        if(len < 0)return;
        if(check(str) == 0){
            ans.push_back(str);
            return;
        }
        for(int ptr = 0; ptr < str.size();ptr++){
        string s = str.substr(0,ptr)+str.substr(ptr+1);
        solve(s,len-1);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        // code here
        int len = check(s);
        solve(s,len);
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
        string s; 
        cin>>s;
        
        Solution obj;
        vector<string> res = obj.removeInvalidParentheses(s);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends