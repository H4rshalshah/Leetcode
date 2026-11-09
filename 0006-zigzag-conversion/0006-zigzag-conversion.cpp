class Solution {
public:
    string convert(string s, int numRows) {
        // Base case: If 1 row or string length is less than numRows, return as is.
        if (numRows <= 1 || numRows >= s.length()) {
            return s;
        }

        // Create a vector of strings for each row
        vector<string> rows(min(numRows, int(s.length())));
        int curRow = 0;
        bool goingDown = false;

        // Traverse the string and append characters to the appropriate row
        for (char c : s) {
            rows[curRow] += c;
            
            // Change direction when we hit the top or bottom row
            if (curRow == 0 || curRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            // Move to the next row depending on the direction
            curRow += goingDown ? 1 : -1;
        }

        // Concatenate all rows to form the final result
        string result;
        for (string row : rows) {
            result += row;
        }
        
        return result;
    }
};