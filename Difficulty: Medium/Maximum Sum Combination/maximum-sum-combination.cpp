class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n=a.size();// both are same size array
        priority_queue<int,vector<int>,greater<int>>pq;
        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int sum=b[j]+a[i];
                if(pq.size()<k)pq.push(sum);
                else if(sum>pq.top()){
                    pq.pop();
                    pq.push(sum);
                }
                else break;
            }
        }
        // vector<int>ans;
        // while(!pq.empty()){
        //     ans.push_back(pq.top());
        //     pq.pop();
        // }
        // reverse(ans.begin(),ans.end());
        vector<int>ans(k);
        int idx=k-1;
        while(!pq.empty() && idx>=0){
            ans[idx]=(pq.top());
            pq.pop();
            idx--;
        }
        return  ans;
    }
};