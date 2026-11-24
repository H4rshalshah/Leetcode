class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Stores the most recent index of each ASCII character
        vector<int> lastSeen(128, -1);
        int maxLen = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char current = s[right];
            
            // If the character was seen within the current window, shrink from the left
            if (lastSeen[current] >= left) {
                left = lastSeen[current] + 1;
            }
            
            lastSeen[current] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};