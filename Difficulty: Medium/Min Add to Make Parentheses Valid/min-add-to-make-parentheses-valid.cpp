class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        int open = 0;
        int ans = 0;
        for(auto it:s){
            if(it=='('){
                open++;
            }
            else{
                if(open>0){
                    open--;
                }
                else{
                    ans++;
                }
            }
        }
        return ans+open;
    }
};