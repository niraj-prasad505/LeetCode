class Solution {
public:

    string reverseVowels(string s) {
        int end = s.size() - 1;
        int x = 0;
        int y = end;
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' ||
                   c == 'o' || c == 'u' ||
                   c == 'A' || c == 'E' || c == 'I' ||
                   c == 'O' || c == 'U';
        };

        while (x < y) {
            while (x < y && !isVowel(s[x])) {
                x++;
            }
            while (x < y && !isVowel(s[y])) {
                y--;
            }
            swap(s[x], s[y]);
            x++;
            y--;
        }
        return s;
    }
};