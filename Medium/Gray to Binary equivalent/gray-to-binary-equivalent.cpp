//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        
     // Your code here
        vector<int>temp;
        
        //Binary conversion
        while(n){
            if(n & 1){
                temp.push_back(1);
            }else {
                temp.push_back(0);
            }
            
            n=n>>1;
        }
        
        reverse(temp.begin(),temp.end());
        
       //Gray code conversion
        for(int i=1;i<temp.size();i++){
            temp[i]=temp[i-1]^temp[i];
        }
        
        
        int j=0;
        int ans=0;
        //Gray code to decimal conversion
        for(int i=temp.size()-1;i>=0;i--){
            ans+= (1<<j)*temp[i];
            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t,n;
    cin>>t;//testcases
    while(t--)
    {
        cin>>n;//initializing n
        
        Solution ob;
        //calling function grayToBinary()
       cout<< ob.grayToBinary(n)<<endl;
    }
}

// } Driver Code Ends