class Solution {
  public:
    void solve(int i ,vector<int> &arr,vector<string>&ans,string& s,unordered_map<int,string>&map){
        if(i>=arr.size()){
            ans.push_back(s);
            return;
        }
        int n = arr[i];
        if(n==1 || n==0){
            solve(i+1,arr,ans,s,map);
        }
        for(int j =0;j<map[n].size();j++){
            s.push_back(map[n][j]);
            solve(i+1,arr,ans,s,map);
            s.pop_back();
        }
    }
    vector<string> possibleWords(vector<int> &arr) {
        unordered_map<int,string>map;
        map[2] = "abc";
        map[3] = "def";
        map[4] = "ghi";
        map[5] = "jkl";
        map[6] = "mno";
        map[7] = "pqrs";
        map[8] = "tuv";
        map[9] = "wxyz";
        vector<string>ans;
        string s;
        solve(0,arr,ans,s,map);
        return ans;
    }
};