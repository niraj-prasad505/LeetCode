class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int n1 = p.size(), n2 = s.size();
        if (n1 > n2){
            return result;
        }

        vector<int> need(26, 0), window(26, 0);
        for (char c : p){
            need[c - 'a']++;
        }
        
        for (int i = 0; i < n2; i++) {
            window[s[i] - 'a']++;

            if (i >= n1) {
                window[s[i - n1] - 'a']--;
            }
            if (i >= n1 - 1 && window == need) {
                result.push_back(i - n1 + 1);
            }
        }
        return result;
    }
};