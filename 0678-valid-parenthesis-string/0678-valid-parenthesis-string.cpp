class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for (char c : s) {

            if (c == '(') {
                low++;
                high++;
            }
            else if (c == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;
                high++;
            }

            // Even the maximum possibility is invalid
            if (high < 0)
                return false;

            // Minimum cannot be negative
            low = max(0, low);
        }

        // If we can have exactly 0 open brackets
        return low == 0;
    }
};