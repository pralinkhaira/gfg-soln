class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        int n = pat.length() ;
        int m = txt.length() ;
        
        vector<int>lps(n , 0) ;
        int len = 0 ; 
        for(int i = 1 ; i < n ; i ++){
            while(len > 0 && pat[len] != pat[i]) len = lps[len - 1] ;
            if(pat[len] == pat[i]) len ++ ;
            lps[i] = len ;
        }
        
        vector<int>ans ;
        int j = 0 ;
        for(int i = 0 ; i < m ; i ++){
            while(j > 0 && pat[j] != txt[i]) j = lps[j - 1] ;
            if(txt[i] == pat[j]) j ++ ;
                        
            if(j == n){
                ans.push_back(i - n + 2) ;
                j = lps[n - 1] ;
            } 
        }
        return ans ;
    }
};