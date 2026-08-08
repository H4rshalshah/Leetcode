#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        // last[j] stores the MAX index in word1 from which word2[j...] 
        // can be matched as a subsequence with ZERO mismatches.
        vector<int> last(m, -1);
        int ptr = n - 1;
        
        for (int j = m - 1; j >= 0; j--) {
            while (ptr >= 0 && word1[ptr] != word2[j]) {
                ptr--;
            }
            if (ptr >= 0) {
                last[j] = ptr;
                ptr--; // move left for the next character of word2
            }
        }
        
        vector<int> result;
        int j = 0; // index in word2
        bool changed = false; // tracks if 1 mismatch has been used
        
        for (int i = 0; i < n && j < m; i++) {
            bool is_match = (word1[i] == word2[j]);
            bool can_take = false;
            
            // If it's the last character of word2, we can always complete it
            if (j + 1 == m) {
                can_take = is_match || !changed;
            } else {
                // If we match word1[i] with word2[j]:
                if (is_match) {
                    // Option A: Match word1[i] == word2[j], and the rest word2[j+1...] matches
                    if (last[j + 1] > i) {
                        can_take = true;
                    } 
                    // Option B: Match word1[i] == word2[j], but we reserve our mismatch 
                    // for a LATER index in word2 (so word2[j+1...] can have 1 mismatch).
                    else if (!changed) {
                        // If we use our mismatch later, then word2[j+1...] only needs to be formed 
                        // with 1 mismatch starting after i.
                        // Since we are taking word1[i] right now, can we complete word2[j+1...]?
                        // Yes! Because we have not used `changed` yet, word2[j+1...] is guaranteed 
                        // to be valid as long as we continue.
                        can_take = true;
                    }
                } 
                // If it's NOT a match, but we haven't used our mismatch yet:
                else if (!changed) {
                    // We consume our 1 mismatch RIGHT NOW at word1[i] = word2[j].
                    // Therefore, the remaining suffix word2[j+1...] MUST match 
                    // with 0 mismatches after index i.
                    if (last[j + 1] > i) {
                        can_take = true;
                    }
                }
            }
            
            if (can_take) {
                if (!is_match) {
                    changed = true; // Mark mismatch as used
                }
                result.push_back(i);
                j++;
            }
        }
        
        return (result.size() == m) ? result : vector<int>();
    }
};