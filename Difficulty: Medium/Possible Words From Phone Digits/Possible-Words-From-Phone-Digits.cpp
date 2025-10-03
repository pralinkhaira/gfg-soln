class Solution {
  public:
  void helper(vector<string>&ans,vector<int>&arr,unordered_map<int,string>mp,int n,string word,int i)
  {
      if(i==n)
      {ans.push_back(word);
          return;
      }
      string temp = mp[arr[i]];
      if(arr[i] == 1 || arr[i] == 0)
      {
          helper(ans,arr,mp,n,word,i+1);
      }
      for(int j = 0;j<temp.size();j++)
      {
          
          word.push_back(temp[j]);
          helper(ans,arr,mp,n,word,i+1);
          word.pop_back();
      }
  }
    vector<string> possibleWords(vector<int> &arr) {
        // code here
        vector<string> ans;
        unordered_map<int,string>mp
        {
            {1,""},
            {2,"abc"},
            {3,"def"},
            {4,"ghi"},
            {5,"jkl"},
            {6,"mno"},
            {7,"pqrs"},
            {8,"tuv"},
            {9,"wxyz"},
            {0,""}
        };
        int n = arr.size();
        helper(ans,arr,mp,n,"",0);
        return ans;
    }
};
