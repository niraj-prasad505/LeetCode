class Solution {
public:
    string reverseVowels(string s) {
        int end = s.size() - 1;
        int x = 0;
        int y = end;
        map<char, bool> vowelMap = {
            {'a', true}, {'e', true}, {'i', true}, {'o', true}, {'u', true},
            {'A', true}, {'E', true}, {'I', true}, {'O', true}, {'U', true}};

        while (x < y) {
            while (x < y && !vowelMap[s[x]]) {
                x++;
            }
            while (x < y && !vowelMap[s[y]]) {
                y--;
            }
            swap(s[x], s[y]);
            x++;
            y--;
        }
        return s;
    }
};