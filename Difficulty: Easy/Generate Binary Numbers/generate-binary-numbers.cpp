class Solution {
  public:
    string ToBinary(int n){
        string binary = "";
        while(n){
            binary.push_back('0'+(n%2));
            n/=2;
        }
        reverse(binary.begin(), binary.end());
        return binary;
    }
    vector<string> generateBinary(int n) {
        vector<string> result;
        
        for(int i = 1;i<=n;i++){
            result.push_back(ToBinary(i));
        }
        
        return result;
    }
};