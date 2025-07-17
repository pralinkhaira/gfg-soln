class Solution {
  public:
    int maxKPower(int n, int k) {
        map<int,int> primeFactor;
        for(int i=2;i*i<=k;i++){
            while(k%i==0){
                primeFactor[i]++;
                k=k/i;
            }
        }
        if(k>1) primeFactor[k]++;
        int ans=INT_MAX;
        for(auto &it:primeFactor){
            int p=it.first;
            int lnk=it.second;
            
            int powerinNFact=0;
            int temp=n;
            while(temp){
                powerinNFact+=temp/p;
                temp/=p;
            }
            ans=min(ans,powerinNFact/lnk);
            
        }
        return ans;
    }
};