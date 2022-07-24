#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100];
int dp[101][3];
// lastActivity ==0 -> rest
// lastActivity ==1 -> contest
// lastActivity ==0 -> gym
int minNumberOfDays(int days,int lastActivity){
	if(days==n){
		return 0;
	}
	if(dp[days][lastActivity]!=-1){
		return dp[days][lastActivity];
	}
	if(arr[days]==0){
		return dp[days][lastActivity]=1+minNumberOfDays(days+1,0);
	}
	if(arr[days]==1){
		// only contest dispo
		if(lastActivity==1){
			return dp[days][lastActivity]=1+minNumberOfDays(days+1,0);
		}else{
			return dp[days][lastActivity]=min(minNumberOfDays(days+1,1),minNumberOfDays(days+1,0)+1);
		}
	}
	if(arr[days]==2){
		// only gym
		if(lastActivity==2){
			return dp[days][lastActivity]=1+minNumberOfDays(days+1,0);
		}else{
			return dp[days][lastActivity]=min(minNumberOfDays(days+1,2),minNumberOfDays(days+1,0)+1);
		}
	}
	if(arr[days]==3){
		// everything dispo.
		if(lastActivity==1){
			return dp[days][lastActivity]=min(minNumberOfDays(days+1,2),minNumberOfDays(days+1,0)+1);
		}else if(lastActivity==2){
			return dp[days][lastActivity]=min(minNumberOfDays(days+1,1),minNumberOfDays(days+1,0)+1);
		}else if(lastActivity==0){
			return dp[days][lastActivity]=min(minNumberOfDays(days+1,2),min(minNumberOfDays(days+1,0)+1,minNumberOfDays(days+1,1)));
		}
	}
}

void solve(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}

	memset(dp,-1,sizeof dp);
	int res=minNumberOfDays(0,0);
	cout << res << endl;

}



int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	//int tc;
	//cin >> tc;
	//while(tc--){
		solve();
	//}
    return 0;
}
