//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Node {
public:
    Node* children[26];
    bool isLeaf;

    Node() {
        isLeaf = false;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
  public:
    Node* root = new Node();
    Trie() {
        
    }

    void insert(string &word) {
        int n = word.size();

        Node* curr = root;
        for (int i = 0; i < n; i++){
            if (i == n - 1){ // if last word
                if (curr -> children[word[i] - 'a'] != NULL){
                    curr = curr -> children[word[i] - 'a'];
                }
                else{
                    Node* node = new Node();
                    curr -> children[word[i] - 'a'] = node;
                    curr = node;
                }
                curr -> isLeaf = true;
            }
            else{
                if (curr -> children[word[i] - 'a'] != NULL){
                    curr = curr -> children[word[i] - 'a'];
                }
                else{
                    Node* node = new Node();
                    curr -> children[word[i] - 'a'] = node;
                    curr = node;
                }
            }
        }
    }

    bool search(string &word) {
        Node* curr = root;
        int n = word.size();
        for (int i = 0; i < n; i++){
            if (curr -> children[word[i] - 'a'] == NULL){
                return false;
            }
            curr = curr -> children[word[i] - 'a'];
        }
        
        return curr -> isLeaf;
    }

    bool isPrefix(string &word) {
        Node* curr = root;
        int n = word.size();
        for (int i = 0; i < n; i++){
            if (curr -> children[word[i] - 'a'] == NULL){
                return false;
            }
            curr = curr -> children[word[i] - 'a'];
        }
        
        return true;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int q;
        cin >> q;
        cin.ignore();
        vector<bool> ans;
        Trie ob;
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            string s;
            cin >> s;
            cin.ignore();
            if (x == 1) {
                ob.insert(s);
            } else if (x == 2) {
                ans.push_back(ob.search(s));
            } else if (x == 3) {
                ans.push_back(ob.isPrefix(s));
            }
        }
        cout << boolalpha;
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends