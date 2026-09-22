class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            cout << "false";
            return 0;
        }

        map<char, int> count;

        for (char c : s) {
            count[c]++;
        }

        for (char c : t) {
            count[c]--;
        }

        for (char c : s) {
            if (count[c] != 0) {
                return false;
            }
        }
        return true;
    }
};