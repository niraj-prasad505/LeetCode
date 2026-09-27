class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string ans1 = "";
        string ans2 = "";

        for (int i = 0; i < word1.size(); i++) {
            for (int j = 0; j < word1[i].size(); j++) {
                ans1.push_back(word1[i][j]);
            }
        }

        for (int i = 0; i < word2.size(); i++) {
            for (int j = 0; j < word2[i].size(); j++) {
                ans2.push_back(word2[i][j]);
            }
        }
        
        if (ans1 == ans2) {
            return true;
        }
        return false;
    }
};