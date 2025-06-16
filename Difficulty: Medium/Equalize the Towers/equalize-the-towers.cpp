class Solution {
  public:
    int minCost(vector<int>& h, vector<int>& cost) {
        // code here
        int s=*min_element(begin(h),end(h));
        int n=h.size();
        int e=*max_element(begin(h),end(h));
        long long ans=1e11;
        auto pos=[&](int mid)->long long{
          long long temp=0;
          for(int i=0;i<n;i++)
              temp+=cost[i]*(abs(mid-h[i]));
          return temp;
        };
        while(s<=e){
            long long mid=(s+e)/2;
            long long f=pos(mid);
            long long prev=pos(mid-1);
            long long next=pos(mid+1);
            ans=min(ans,f);
            if(prev<=next)
                e=mid-1;
            else
                s=mid+1;
        }
        return ans;
    }
};