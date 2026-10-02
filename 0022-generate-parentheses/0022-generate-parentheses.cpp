#include <vector>
#include <string>

class Solution {
public:
    void backtrack(int n, int open, int close, std::string current, std::vector<std::string>& result) {
        // Base case: formed a valid combination of length 2 * n
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        // Add open bracket if we haven't reached n
        if (open < n) {
            backtrack(n, open + 1, close, current + "(", result);
        }
        
        // Add close bracket if close count is less than open count
        if (close < open) {
            backtrack(n, open, close + 1, current + ")", result);
        }
    }

    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        backtrack(n, 0, 0, "", result);
        return result;
    }
};