class Solution {
public:
	// problem link : https://leetcode.com/problems/count-special-integers/submissions/
	// topic: dp (digit dp),bitmask :) 
    int dp[11][2][1<<10][2];
    int recVal(string& nums,int bits,bool leading, int mask,bool tight){
        if(bits==0&&!leading) return 1;
        if(bits==0) return 0;
        if(dp[bits][leading][mask][tight]!=-1)return dp[bits][leading][mask][tight];
        int upperBound=9;
        if(tight){
            upperBound=nums[nums.length()-bits]-'0';
        }
        int res=(leading)?recVal(nums,bits-1,1,mask,0):0;
        for(int i=0;i<10;i++){
            if(leading && i==0) continue;
            if((mask&(1<<i))&&i<=upperBound){
                int val=1<<i;
                val=mask-val;
                res+=recVal(nums,bits-1,0,val,tight&(i==upperBound));
            }
        }
        return dp[bits][leading][mask][tight]=res;
    }
    int countSpecialNumbers(int n) {
        string tempn=to_string(n);
        int val=(1<<10)-1;
        memset(dp,-1,sizeof dp);
        return recVal(tempn,tempn.length(),1,val,1);

    }
};
