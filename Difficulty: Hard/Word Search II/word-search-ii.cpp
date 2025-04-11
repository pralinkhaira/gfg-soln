//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<string> result;
    int n;
    int m;
  
    struct trieNode {
        bool endofword;
        string word;
        trieNode* children[26];
    };
  
    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->endofword = false;
        newNode->word = "";
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }
  
    void insert(trieNode* root, string& word) {
        trieNode* crawler = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            int idx = ch - 'a';
            if (crawler->children[idx] == NULL) {
                crawler->children[idx] = getNode();
            }
            crawler = crawler->children[idx];
        }
        crawler->endofword = true;
        crawler->word = word;
    }
  
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
  
    void findword(vector<vector<char>>& board, int i, int j, trieNode* root) {
        if (i < 0 || j < 0 || i >= n || j >= m) return;
        if (board[i][j] == '$' || (root->children[board[i][j] - 'a'] == NULL)) return;

        root = root->children[board[i][j] - 'a'];
        if (root->endofword == true) {
            result.push_back(root->word);
            root->endofword = false;
        }
      
        char temp = board[i][j];
        board[i][j] = '$';
      
        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            findword(board, nx, ny, root);
        }
      
        board[i][j] = temp;
    }
  
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        m = board[0].size();
      
        trieNode* root = getNode();
        for (string word : words) {
            insert(root, word);
        }
      
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (root->children[board[i][j] - 'a'] != NULL) {
                    findword(board, i, j, root);
                }
            }
        }
      
        return result;
    }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

vector<char> inputLineChar() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    char num;
    vector<char> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

vector<string> inputLineString() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    string num;
    vector<string> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    vector<int> v = inputLine();
    t = v[0];
    while (t-- > 0) {
        // Read board dimensions
        int n, m;
        vector<int> v = inputLine();
        n = v[0];
        v = inputLine();
        m = v[0];

        // Read board
        vector<vector<char>> board(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            vector<char> v = inputLineChar();
            for (int j = 0; j < m; j++) {
                board[i][j] = v[j];
            }
        }

        // Read words to search
        vector<string> words = inputLineString();

        // Find words using Solution class
        Solution obj;
        vector<string> ans = obj.findWords(board, words);
        sort(ans.begin(), ans.end());

        // Output results
        if (ans.empty()) {
            cout << "[]\n";
        } else {
            for (const string& s : ans) {
                cout << s << " ";
            }
            cout << "\n";
        }
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends