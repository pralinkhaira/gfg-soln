//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    /*You are required to complete below function */
    string multiplyStrings(string& s1, string& s2) {
        // Your code here
         if(s1=="0" || s2=="0"){
            return "0";
        }
          bool neg = false;
         
    if(s1[0] == '-'){
        neg = !neg;
        s1 = s1.substr(1); 
        
    }
    if(s2[0] == '-') {
        neg = !neg; 
        s2 = s2.substr(1); 
        
    }

    while(s1.length()>1 && s1[0]=='0') s1.erase(s1.begin());
    while(s2.length()>1 && s2[0]=='0') s2.erase(s2.begin());
 vector<int>ans(s1.length()+s2.length(),0);
       for(int i=s1.length()-1;i>=0;i--){
           for(int j=s2.length()-1;j>=0;j--){
               int product=(s1[i]-'0')*(s2[j]-'0');
               int sum=product+ans[i+j+1];
               ans[i+j+1]=sum%10;
               ans[i+j]+=sum/10;
           }
       }
       string result="";
       int i=0;
       while(i<ans.size() && ans[i]==0){
           i++;
       }
        if (i == ans.size()) {
        return "0";
    }
       for(;i<ans.size();i++){
           result+=(ans[i]+'0');
       }
       if(neg) result="-"+result;
return result.empty()?"0":result;        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string a;
        string b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends