class Solution {
  public:
    int substrCount(string &s, int k) {
        unordered_map<char, int> mp;
        int res = 0;
        for(int i = 0; i < k; i++) {
            mp[s[i] - 'a']++;
        }
        if(mp.size() == k - 1) {
            res++;
        }
        for(int i = k; i < s.length(); i++) {
            mp[s[i - k] - 'a']--;
            if(mp[s[i - k] - 'a'] == 0) {
                mp.erase(s[i - k] - 'a');
            }
            mp[s[i] - 'a']++;
            if(mp.size() == k - 1) {
                res++;
            }
        }
        return res;
    }
}; // ✅ this closes the class
