class Solution {
public:
    bool isValid(string s) {
        int count = 0;

        for (char c : s) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;

                if (count < 0) {
                    return false;
                }
            }
        }

        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;

        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                string curr = q.front();
                q.pop();

                // Found valid strings at minimum removal level
                if (isValid(curr)) {
                    ans.push_back(curr);
                    found = true;
                }

                // Don't generate next level
                if (found) {
                    continue;
                }

                // Remove one character
                for (int i = 0; i < curr.size(); i++) {

                    if (curr[i] != '(' && curr[i] != ')')
                        continue;

                    string next = curr.substr(0, i) + curr.substr(i + 1);

                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            if (found) {
                break;
            }
        }

        return ans;
    }
};