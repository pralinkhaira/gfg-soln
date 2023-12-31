


class Solution {
public:
boolcanPair(vector<int>nums,intk){
// Code here.
intn=nums.size();
if(n%2!=0)returnfalse;
unordered_map<int,int>mp;//for storing remainder
intpair=0;
for(inti=0;i<nums.size();i++){
intrem=nums[i]%k;
if(rem==0){
mp[0]++;
if(mp[0]%2==0){
pair++;
mp[0]=mp[0]-2;
}
 
}
elseif(mp.find(k-rem)!=mp.end()&&mp[k-rem]>0){
pair++;
mp[k-rem]--;
// if(mp[k-rem]==0)mp.erase(mp[k-rem]);
}
 
elsemp[rem]++;
 
}
 
if(pair*2==n)returntrue;
 
returnfalse;
}
};


