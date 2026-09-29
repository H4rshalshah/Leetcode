#include <vector>
#include <set>
#include <cmath>

class Solution {
public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int indexDiff, int valueDiff) {
        std::set<long> window;
        
        for (int i = 0; i < nums.size(); ++i) {
            // Remove element outside the window of size indexDiff
            if (i > indexDiff) {
                window.erase(nums[i - indexDiff - 1]);
            }
            
            // Find the first element >= nums[i] - valueDiff
            auto it = window.lower_bound((long)nums[i] - valueDiff);
            
            // Check if that element is <= nums[i] + valueDiff
            if (it != window.end() && *it <= (long)nums[i] + valueDiff) {
                return true;
            }
            
            window.insert(nums[i]);
        }
        
        return false;
    }
};