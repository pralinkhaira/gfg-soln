class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
         int i=0,j=arr.size()-1;
        int ans = 0;
        while(i<j) {
            ans = max(ans,min(arr[i],arr[j])*(j-i));
            if(arr[i]<arr[j]) i++;
            else if(arr[i]>arr[j]) j--;
            else{
                if(arr[i+1] > arr[j-1]) i++;
                else j--;
            }
        }
        return ans;
    }
};
