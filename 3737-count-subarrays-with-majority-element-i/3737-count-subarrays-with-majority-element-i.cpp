class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;

        for (int left = 0; left < n; left++) {
            int count = 0;
            for (int right = left; right < n; right++) {
                if (nums[right] == target) {
                    count++;
                }
                int length = right - left + 1;
                if (count > length / 2) {
                    total++;
                }
            }
        }

        return total;
    }
};