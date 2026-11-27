
class Solution {
    struct TrieNode {
        TrieNode* child[26] = {};
        string word = "";
    };

    TrieNode* root = new TrieNode();

    void insert(string& word) {
        TrieNode* node = root;

        for (char c : word) {
            int index = c - 'a';

            if (!node->child[index])
                node->child[index] = new TrieNode();

            node = node->child[index];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j,
             TrieNode* node, vector<string>& ans) {

        char c = board[i][j];

        if (c == '#' || !node->child[c - 'a'])
            return;

        node = node->child[c - 'a'];

        if (node->word != "") {
            ans.push_back(node->word);
            node->word = "";
        }

        board[i][j] = '#';

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && x < board.size() &&
                y >= 0 && y < board[0].size()) {
                dfs(board, x, y, node, ans);
            }
        }

        board[i][j] = c;
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        for (string& word : words)
            insert(word);

        vector<string> ans;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, ans);
            }
        }

        return ans;
    }
};
