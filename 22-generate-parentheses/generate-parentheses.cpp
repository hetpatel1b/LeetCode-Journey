
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string current;

        backtrack(ans, current, 0, 0, n);

        return ans;
    }

    void backtrack(vector<string>& ans, string& current,
                   int open, int close, int n) {

        // Base case: all parentheses are used
        if (open == n && close == n) {
            ans.push_back(current);
            return;
        }

        // Choice 1: Add opening parenthesis
        if (open < n) {
            current.push_back('(');

            backtrack(ans, current, open + 1, close, n);

            current.pop_back();  // Backtrack
        }

        // Choice 2: Add closing parenthesis
        if (close < open) {
            current.push_back(')');

            backtrack(ans, current, open, close + 1, n);

            current.pop_back();  // Backtrack
        }
    }
};
