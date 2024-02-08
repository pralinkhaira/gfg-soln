//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public: 
  int lcs(int x,int y,string s1,string s2){
      int dp[x+1][y+1];
      for(int i=0;i<=x;i++){
          for(int j=0;j<=y;j++){
              if(i==0 || j==0){
                  dp[i][j]=0;
              }  
              else{
              if(s1[i-1]==s2[j-1]){
                  dp[i][j]=1+dp[i-1][j-1];
              }
              else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
              }
          }
      }
      }
      return dp[x][y];
  } 
  

      int countMin(string str){
    //complete the function here   
    int n=str.length(); 
    string str1=str;
    string str2=str;
    reverse(str2.begin(),str2.end());
    int x=n;
    int y=n;
    int len=lcs(x,y,str1,str2); 
    return n-len;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends