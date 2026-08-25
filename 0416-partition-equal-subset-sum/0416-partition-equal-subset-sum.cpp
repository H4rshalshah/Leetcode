class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for(auto it : nums) {
            sum += it;
        }

        if(sum % 2 != 0) {
            return false;
        }

        int s = sum / 2;

        vector<bool> prev(s + 1, false);
        vector<bool> curr(s + 1, false);

        prev[0] = true;

        if(nums[0] <= s) {
            prev[nums[0]] = true;
        }

        for(int index = 1; index < nums.size(); index++) {

            curr[0] = true;

            for(int target = 1; target <= s; target++) {

                bool nottake = prev[target];

                bool take = false;

                if(target >= nums[index]) {
                    take = prev[target - nums[index]];
                }

                curr[target] = take || nottake;
            }

            prev = curr;
        }

        return prev[s];
    }
};