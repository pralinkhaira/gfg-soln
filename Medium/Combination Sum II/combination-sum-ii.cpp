//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    void help(vector<int>& arr,int i,int k,vector<int>& temp,set<vector<int>>& st)
    {
        //base case
        if(k<0)
        return ;
        
        if(k==0 or i==arr.size())
        {
            if(k==0)
            st.insert(temp);
            return ;
        }
        
        //recursive calls
        //and small calculation
        temp.push_back(arr[i]);
        help(arr,i+1,k-arr[i],temp,st);
        temp.pop_back();
        help(arr,i+1,k,temp,st);
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        sort(arr.begin(),arr.end());
        set<vector<int>> st;
        vector<vector<int>> ans;
        vector<int> temp;
        help(arr,0,k,temp,st);
        
        for(auto& it:st)
        ans.push_back(it);
        
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends