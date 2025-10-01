class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
         sort(arr.begin(), arr.end());
           vector<vector<int>> out;
           int length = 0, n = arr.size() - 1;

    while (length < n) {
        int sum = arr[length] + arr[n];

        if (sum == 0) {
            out.push_back({arr[length], arr[n]});

            int leftValue = arr[length];
            int rightValue = arr[n];

            while (length < n && arr[length] == leftValue) length++;
            while (length < n && arr[n] == rightValue) n--;

        } else if (sum < 0) {
            length++; 
        } else {
            n--; 
        }
    }

    return out;
        
    }
};