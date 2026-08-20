class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int,int>freq;
        int n =nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==key){
                freq[nums[i+1]]++;
            }
        }
        int ans=0;
        int maxi=0;
        for(auto it:freq){
            if(it.second>maxi){
                maxi=it.second;
                ans=it.first;
            }
        }
        return ans;
        
    }
};