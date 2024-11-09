//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end()); 

        int l = arr.size(), rem = 0;
        string ans = "";
    
        for (int i = l - 1; i >= 0; i -= 2) {
            if (i - 1 >= 0) {
                rem += arr[i] + arr[i - 1];  
            } else {
                rem +=  arr[i];  
            }

            if (rem > 0) ans.push_back((rem % 10) + '0'); 
            
            rem /= 10; 
        }
    
        if (rem > 0) ans.push_back((rem % 10) + '0');
    
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends