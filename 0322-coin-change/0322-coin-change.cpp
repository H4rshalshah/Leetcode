class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>prev(amount+1,0),curr(amount+1,0);
        int n=coins.size();
        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0) prev[target]= target/coins[0];
            else{
                prev[target]= 1e9;
            }
        }
        for(int index=1;index<n;index++){
            for(int target=0;target<=amount;target++){
                int nottake=prev[target];
                int take=INT_MAX;
                if(coins[index]<=target){
                    take=1+curr[target-coins[index]];
                }
                curr[target]=min(take,nottake);
            }
            prev=curr;
        }
        int ans=prev[amount];
        if(prev[amount]>=1e9){
            return -1;
        }
        return prev[amount];
        
    }
};