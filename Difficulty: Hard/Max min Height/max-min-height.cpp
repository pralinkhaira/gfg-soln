class Solution {
  public:
    int maxMinHeight(vector<int> &arr, int k, int w) {
        // code here
        int low=*min_element(arr.begin(),arr.end());
        
        int high=(int)(1e9);
        
        int n=(int)arr.size();
        
        function<int(int)>f=[&](int mid)->int{
            
            vector<int>prefix(n+1,0);
            int k1=k;
            auto v=arr;
            for(int i=0;i<n;i++)
            {
                prefix[i]+=(i>0)?prefix[i-1]:0;
                if((v[i]+prefix[i])<mid)
                {
                    int diff=mid-(v[i]+prefix[i]);
                    if(k1<diff)
                    return 0;
                    k1-=diff;
                    prefix[i]+=diff;
                    prefix[min(i+w,n)]-=diff;
                }
            }
            for(int i=0;i<n;i++)
            v[i]+=prefix[i];
            int minm=*min_element(v.begin(),v.end());
            if(minm<mid)
            return 0;
            
            return 1;
            
        };
        int res=high;
        while(low<=high)
        {
            int mid=(low+high)/2;
            // cout<<mid<<endl;
            if(f(mid))
            {
                res=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return res;
    }
};