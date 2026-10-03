class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // Base index for calculating length
        int maxLength = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    // Push current index as a new base for valid substrings
                    st.push(i);
                } else {
                    // Current valid length = current_index - index_of_last_unmatched
                    maxLength = max(maxLength, i - st.top());
                }
            }
        }

        return maxLength;
    }
};