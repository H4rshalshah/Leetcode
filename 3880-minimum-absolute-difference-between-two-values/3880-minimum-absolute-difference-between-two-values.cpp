class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int mini=nums.size();
        int one=-1,two=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                one =i;
            }
            if(nums[i]==2){
                two=i;
            }
            if(one !=-1 and two !=-1)
                mini=min(mini,abs(one-two));
        }
        if(one ==-1 | two==-1){
            return -1;
        }




        return mini;
        
    }
};