class Solution {
  public:
    int search(vector<int>& arr, vector<int>&mini, int ele){
        int pos = -1;
        int l = 0;
        int r = mini.size()-1;
        int mid = 0;
        while(l<=r){
            mid = (l+r)/2;
            if(ele <= arr[mini[mid]]){
                l = mid+1;
            }
            else{
                r = mid-1;
                pos = mini[mid];
            }
        }
        return pos;
    }
    vector<int> farMin(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>ans;
        vector<int>mini;
        for(int i = n-1; i>=0 ; i--){
            int ele = arr[i];
            int pos = search(arr, mini, ele);
            if(pos == -1){
                mini.push_back(i);
            }
            ans.push_back(pos);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};