class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maximum=-1;
        int dp[2510];
        memset(dp,-1,sizeof dp);
        for(int i=nums.size()-1;i>=0;i--){
            maximum=max(maximum,LIS(nums,i,dp));
        }
        return maximum;
    }
    
    int LIS(vector<int>& nums,int i,int dp[]){
        if(i==0){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int lis=1;
        for(int k=i;k>=0;k--){
            if(nums[i]>nums[k]){
              lis=max(lis,1+LIS(nums,k,dp));
            }
            
        }
        return dp[i]=lis;
    }
};