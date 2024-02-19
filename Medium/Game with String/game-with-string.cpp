//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    int minValue(string s, int k){
        priority_queue<int>pq;
        unordered_map<char,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        for(auto x:mp){
            pq.push(x.second);
        }
        while(k--){
            int p=pq.top();
            pq.pop();
            p--;
            if(p>0){
                pq.push(p);
            }
        }
        int sum=0;
        while(!pq.empty()){
            int p=pq.top();
            sum+=p*p;
            pq.pop();
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends