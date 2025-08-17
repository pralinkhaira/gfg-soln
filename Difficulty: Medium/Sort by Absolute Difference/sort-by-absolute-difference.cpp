class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        int n = arr.size();
        
        vector<pair<int,pair<int,int>>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({abs(arr[i] - x), {i, arr[i]}});
        }
        
        sort(v.begin(), v.end()); // rearrange automatically using sorting
        
        for(int i = 0; i < n; i++) {
            arr[i] = v[i].second.second;
        }
    }
};