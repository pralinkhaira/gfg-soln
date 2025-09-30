class Solution {
  public:
    vector<string> binstr(int n) {
        // code here
        int no_of_subsets =  1<<n;
        vector<string> ans;
        for(int num = 0;num<no_of_subsets;num++){
            string str = "";
            for(int i = 0;i<n;i++){
                if(num&(1<<i)){
                    str.push_back('1');
                }else{
                    str.push_back('0');
                }
            }
            ans.push_back(str);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};