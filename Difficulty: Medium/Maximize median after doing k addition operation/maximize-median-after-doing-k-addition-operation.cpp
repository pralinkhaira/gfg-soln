class Solution {
  public:
    int maximizeMedian(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        if(n%2 != 0){
            int curr_sum=0;
            int count=0;
            for(int i=n/2;i<n;i++){
                curr_sum+=arr[i];
                count++;
                if(i<=n-2){
                    if((curr_sum+k)/count <= arr[i+1]){
                        break;
                    }
                }
            }
            return (curr_sum+k)/count;
        }
        else{
            
            int curr_sum=0;
            int count=0;
            int breakpoint=-1;
            for(int i=n/2-1;i<n;i++){
                curr_sum+=arr[i];
                count++;
                if(i<=n-2){
                    if((curr_sum+k)/count <= arr[i+1]){
                        breakpoint=i;
                        break;
                    }
                }
            }
            if(breakpoint==n/2-1){
                return (arr[n/2-1]+k+arr[n/2])/2;
            }
            return (curr_sum+k)/count;
            
        }
    }
};
