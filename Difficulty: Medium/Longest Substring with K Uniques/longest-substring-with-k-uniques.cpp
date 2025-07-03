class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int bptr=0,ans=-1,n=s.size();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            if(mp.size()==k){
                ans=max(ans,i-bptr+1);
            }
            else{
                while(mp.size()>k){
                    mp[s[bptr]]--;
                    if(mp[s[bptr]]==0){
                        mp.erase(s[bptr]);
                    }
                    bptr++;
                }
            }
        }
        return ans;
        
    }
};