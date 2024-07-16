//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    string printString(string s, char ch, int count) {
        // Your code goes here
        unordered_map<char, int> m;
        bool found = 0;
        int index = 0;
        string res = "";
        for (int i = 0; i < s.length(); i++)
        {
            m[s[i]] ++;
            if(m[ch] == count)
            {
                found = 1;
                index = i;
                break;
            }
        }
        while(found && index < s.length())
        {
            index++;
            res += s[index];
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        char ch;
        int count;

        cin >> s >> ch >> count;
        Solution ob;
        cout << ob.printString(s, ch, count) << "\n";
    }

    return 0;
}
// } Driver Code Ends