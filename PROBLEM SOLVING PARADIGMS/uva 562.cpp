#include <bits/stdc++.h>
using namespace std;
int coins[100];
int numberOfBags;
int dp[110][50010];
int sum;

int solve(int coinNumber,int firstPersonMoney){
	if(coinNumber==numberOfBags){
		return abs(firstPersonMoney-(sum-firstPersonMoney)); // difference between the two, first and second.
	}
	if(dp[coinNumber][firstPersonMoney]!=-1){
		return dp[coinNumber][firstPersonMoney];
	}

	int Takeit=solve(coinNumber+1,firstPersonMoney+coins[coinNumber]);
	int dontTakeIt=solve(coinNumber+1,firstPersonMoney);
	return dp[coinNumber][firstPersonMoney]=min(Takeit,dontTakeIt);
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int tc;
	scanf("%d",&tc);

	while(tc--){
		memset(dp,-1,sizeof dp);
		scanf("%d",&numberOfBags);
		sum=0;
		for(int i=0;i<numberOfBags;i++){
			cin >>coins[i];
			sum+=coins[i];
		}

		int res=solve(0,0);

		cout << res << endl;

	}
    
    return 0;
}
