class Solution {
  public:
  
   bool ispossible(vector<int>&arr,int mid , int k){
         
                   int n = arr.size();
        
        int sum = 0, cnt = 1;
        for(int i = 0; i < n; i++){
            if(cnt > k) return false;
            if(sum + arr[i] <= mid) sum += arr[i];
            else{
                if(arr[i] > mid) return false;
                sum = arr[i];
                cnt++;
            }
        }
        
        return (cnt <= k);
                 
         
   }
  
   
  
  
    int splitArray(vector<int>& arr, int k) {
           
           // 1 3 6 10 
           // k=3
          
           int l=0;
           int r = accumulate(arr.begin(),arr.end(),0);
           int ans =r;
           while (l<=r){
                 
                   int mid =l+(r-l)/2;
                   
                   
                   if (ispossible(arr,mid,k)){
                        //   cout<<"ok";
                          ans =mid;
                          r=mid-1;
                   }
                   else{
                         l=mid+1;
                   }
                  
           }
           
           return ans;
        
    }
};