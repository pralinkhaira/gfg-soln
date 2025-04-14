//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string topoSort(unordered_map<char,vector<char>>&adj,vector<bool>&vis,vector<int>&indeg){
        queue<char>q;
        for(int i=0;i<26;i++){
            if(vis[i]&&indeg[i]==0){
                q.push(i+'a');
            }
        }
        string result;
        while(!q.empty()){
            char u=q.front();
            q.pop();
            result+=u;
            for(char v:adj[u]){
                indeg[v-'a']--;
                if(indeg[v-'a']==0){
                    q.push(v);
                }
            }
        }
        for(int i=0;i<26;i++){
            if(vis[i]&&indeg[i]!=0){
                return "";
            }
        }
        return result;
    }
    string findOrder(vector<string> &words) {
        // code here
        unordered_map<char,vector<char>>adj;
        vector<int>indeg(26);
        vector<bool>vis(26,false);
        for(auto &str:words){
            for(auto &ch:str){
                vis[ch-'a']=true;
            }
        }
        int N=words.size();
        for(int i=0;i<N-1;i++){
            string s1=words[i];
            string s2=words[i+1];
            int minLen=min(s1.size(),s2.size());
            if (s1.length() > s2.length() && s1.substr(0, s2.length()) == s2) {
                return "";
            }
            for(int ptr=0;ptr<minLen;ptr++){
                if(s1[ptr]==s2[ptr]) continue;
                else if(s1[ptr]!=s2[ptr]) {
                    adj[s1[ptr]].push_back(s2[ptr]);
                    indeg[s2[ptr]-'a']++;
                    break;
                }
            }
        }
        return topoSort(adj,vis,indeg);
    }
};

//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends