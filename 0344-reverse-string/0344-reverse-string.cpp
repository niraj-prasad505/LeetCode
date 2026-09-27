class Solution {
public:
    void reverseString(vector<char>& s) {
        int end = s.size() - 1;
        int start = 0;
        while (end >= start) {
            swap(s[end], s[start]);
            start++;
            end--;
        }
    }
};