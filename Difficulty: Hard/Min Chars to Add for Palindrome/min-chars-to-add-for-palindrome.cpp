//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int minChar(string str){
        //Write your code here
        string a = str;
        reverse(str.begin(),str.end());
        string temp = a+'$'+str;
        int n = temp.length();
        int lps[n];
        int i = 1;
        int j = 0;
        lps[0] = 0;
        
        while(i<n){
            if(temp[i]==temp[j]){
                j++;
                lps[i] = j;
                i++;
            }
            
            else{
                if(j!=0){
                    j = lps[j-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        return a.length()-lps[n-1];
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends