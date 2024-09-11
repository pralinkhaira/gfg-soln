//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
long long minCost(std::vector<long long>& arr) {
    long long ans = 0;
    std::multiset<long long> ms(arr.begin(), arr.end());
    
    while (ms.size() > 1) {
        // Get the two smallest elements
        long long p = *ms.begin();
        ms.erase(ms.begin());
        long long q = *ms.begin();
        ms.erase(ms.begin());
        
        // Compute the cost and insert the new element
        long long k = p + q;
        ans += k;
        ms.insert(k);
    }
    
    return ans;
}
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends