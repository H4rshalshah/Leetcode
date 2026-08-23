class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i=0;
        int j=n;
        vector<int>ans;
        while(i<nums.size()/2){
            ans.push_back(nums[i]);
            i++;
            ans.push_back(nums[j]);
            j++;
        }
        return ans;
        
    }
};