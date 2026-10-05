
class Solution {
private:
    std::unordered_map<int, std::vector<int>> mp;

public:
    Solution(std::vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        const auto& indices = mp[target];
        int rand_idx = rand() % indices.size();
        return indices[rand_idx];
    }
};