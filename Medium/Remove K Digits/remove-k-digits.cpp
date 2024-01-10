//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
  public:
    string removeKdigits(string S, int K)
    {
        int i, len, d, t;
        char ch;
        stack<int> st;
        string ans;

        len = (int)S.length();
        if (K == len) return "0";

        d = S[0] - '0';
        st.push(d);
        for (i = 1; i < len; i++)
        {
            d = S[i] - '0';
            t = st.top();
            for (   ;  K > 0 ;  )
            {
//printf("i %d, d %d, t %d\n", i, d, t);
                if (t <= d) break;
                st.pop();
                K--;
                if (st.empty()) break;
                if (K <= 0) break;
                t = st.top();
            }
            st.push(d);
        }
//printf("K %d\n", K);

        for (i = 0; i < K; i++)
        {
            st.pop();
        }

        ans.clear();
        for (   ;    ;   )
        {
            if (st.empty()) break;
            d = st.top();
            st.pop();
            ch = d + '0';
            ans += ch;
        }
//printf("ans %s\n", ans.c_str());

        len = (int)ans.length();
        for (i = len - 1; i >= 0; i--)
        {
            if (ans[i] != '0') break;
            ans.pop_back();
        }

        len = (int)ans.length();
        if (len == 0) return "0";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends