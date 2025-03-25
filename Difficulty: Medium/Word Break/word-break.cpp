//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class TrieNode {
  public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
  public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string &word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch))
                node->children[ch] = new TrieNode();
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    bool search(const string &word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch))
                return false;
            node = node->children[ch];
        }
        return node->isEndOfWord;
    }
};

class Solution {
  public:
    bool wordBreak(string &s, vector<string> &dictionary) {
        int n = s.size();
        Trie trie;
        for (const string &word : dictionary) {
            trie.insert(word);
        }

        queue<int> q;
        vector<bool> visited(n + 1, false);

        q.push(0);  // Start from the first character
        visited[0] = true;

        while (!q.empty()) {
            int start = q.front();
            q.pop();

            TrieNode* node = trie.root;
            for (int end = start; end < n; end++) {
                if (!node->children.count(s[end])) break; // No valid prefix
                node = node->children[s[end]];

                if (node->isEndOfWord && !visited[end + 1]) {
                    if (end + 1 == n) return true; // Successfully partitioned
                    q.push(end + 1);
                    visited[end + 1] = true;
                }
            }
        }

        return false;
    }
};

//{ Driver Code Starts.

vector<string> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<string> res;
    while (ss >> str) {
        res.push_back(str);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        cin.ignore();
        vector<string> dictionary = inputLine();

        Solution ob;
        if (ob.wordBreak(s, dictionary)) {
            cout << "true\n";
        } else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends