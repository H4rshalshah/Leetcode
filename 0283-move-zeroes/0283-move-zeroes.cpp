class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int start;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                start=i;
                break;
            }
        }
        for(int j=start+1;j<n;j++){
            if(nums[j]!=0){
                nums[start]=nums[j];
                nums[j]=0;
                start++;
            }
            if(j==n-1){
                break;
            }
        }
    }
};