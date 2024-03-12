//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    using mat = array<array<long long, 3>, 3>;
    int genFibNum(int a, int b, int c, int n, int m)
    {
        if (n <= 2)
            return 1;
        else
            n -= 2;
        auto mul = [m](mat x, mat y) -> mat
        {
            mat ans{{}};
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    for (int k = 0; k < 3; k++)
                        ans[i][j] = (ans[i][j] + x[i][k] * y[k][j]) % m;
            return ans;
        };
        mat curr = {{{a, b, c},
                     {1, 0, 0},
                     {0, 0, 1}}};
        mat ans = {{{1, 0, 0},
                    {0, 1, 0},
                    {0, 0, 1}}};
        if (n & 1)
            ans = curr;
        for (int p = 1; p <= 30; p++)
        {
            curr = mul(curr, curr);
            if (n & (1 << p))
                ans = mul(ans, curr);
        }
        return (ans[0][0] + ans[0][1] + ans[0][2]) % m;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a,b,c,n,m;
        
        cin>>a>>b>>c>>n>>m;

        Solution ob;
        cout << ob.genFibNum(a,b,c,n,m) << endl;
    }
    return 0;
}
// } Driver Code Ends