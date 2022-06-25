#include <bits/stdc++.h>
using namespace std;

long long dp[60];
long long solve(int n){
	if(n==0){
		return 1;
	}
	if(n==1){
		return dp[1]=2;
	}
	if(dp[n]!=-1){
		return dp[n];
	}
	dp[n]=solve(n-1)+solve(n-2);
	return dp[n];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc;
    scanf("%d",&tc);
    // at first we can put 0 or 1 or 0 1 (after that we only can put 0 or 01 because if we put 1 we will get to 0 1 (already computed.))
    memset(dp,-1,sizeof dp);
    int i=0;
    while(tc--){
    	i++;
    	int n;
    	scanf("%d",&n);
    	long long res=solve(n);
    	cout << "Scenario #"<<i<<":"<<endl;
    	cout << res << endl;
    	cout <<endl;
    }

    
    return 0;
}
