class Solution {
  public:
    int countStrings(string &s) {
        // code here
        vector<int> freq(26, 0);
        int n = s.size();
    
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }
    
        int count = 0;
        bool flag=false;
        for (int i = 0; i < n; i++) {
            if(freq[s[i]-'a']>0)
            {
                count+=(n-freq[s[i]-'a']);
            }
            if(freq[s[i]-'a']>1)
            {
                flag=true;
            }
        }
        count/=2;
        return flag?count+1:count;
    }


};
