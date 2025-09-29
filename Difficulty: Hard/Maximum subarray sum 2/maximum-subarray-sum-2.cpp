class Solution {
  public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size();
        vector<long long> pref(n+1, 0);
        for(int i=1; i<=n; i++) pref[i] = pref[i-1] + arr[i-1];
        
        multiset<long long> ms;
        int res = INT_MIN;
        
        int r = a;
        for(int l=1; l<=n-a+1; l++) {
            while(r<=n && r<l+b) ms.insert(pref[r++]);
            
            res = max(res, int(*ms.rbegin() - pref[l-1]));
            ms.erase(ms.find(pref[l+a-1]));
        }
        
        return res;
    }
};