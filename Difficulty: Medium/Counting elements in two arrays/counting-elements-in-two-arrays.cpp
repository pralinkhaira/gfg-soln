class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        // sort(begin(b),end(b));
        // vector<int>ans;
        // for(int i:a){
        //     int x=upper_bound(begin(b),end(b),i)-b.begin();
        //     ans.push_back(x);
        // }
        // return ans;
        int mx=*max_element(begin(b),end(b));
        vector<int>arr(mx+1);
        for(int i:b){
            arr[i]++;
        }
        for(int i=0;i<mx+1;i++){
            arr[i]+=arr[i-1];
        }
        vector<int>ans;
        for(int i:a){
           int x=i>=mx?arr[mx]:arr[i];
           ans.push_back(x);
        }
        return ans;
    }
};