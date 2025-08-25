class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here
        int n=s1.size();
        int m=s2.size();
        int i=0,j=0;
        int c=0;
        while(i<n && j<m){
         if(s1[i]==s2[j]){
             i++;
             j++;
            c++;
                }
            else if(s1[i]!=s2[j])
                j++;
            
        }
        if(c==n) return true;
        else  return false;
        
    }
};