class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
        // should we do 2 pointer?
        // first find idx of x
        // oh its not necessary target is there
        // then we point idx-1 to prev smaller and idx to >=
        int n=arr.size();
        int idx=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int i=idx-1;
        int j=idx;
        if(arr[j]==x){
            j++;
        }
        vector<int>ans;
        int cnt=0;
        while(i>=0 && j<n && cnt<k){
            if(abs(arr[i]-x)<abs(arr[j]-x)){
                ans.push_back(arr[i]);
                i--;
            }
            else if(abs(arr[i]-x)>abs(arr[j]-x)){
                ans.push_back(arr[j]);
                j++;
            }
            else{
                ans.push_back(arr[j]);
                j++;
            }
            cnt++;
        }
        
        while(i>=0 && cnt<k){
            ans.push_back(arr[i]);
            i--;
            cnt++;
        }
        while(j<n && cnt<k){
            ans.push_back(arr[j]);
            j++;
            cnt++;
        }
        return ans;
    }
};