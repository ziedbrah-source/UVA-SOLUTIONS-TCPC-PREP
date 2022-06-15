#include<bits/stdc++.h>
using namespace std;

long long dp[30010][7];
int coins[]={1,5,10,25,50};

long long ways(int money,int index){
	if(money < 0 || index==5){
		return 0;
	}
	if(money==0){
		return 1;
	}
	if(dp[money][index]!=-1){
		return dp[money][index];
	}
	if(money-coins[index]>-1){
		return dp[money][index]=ways(money-coins[index],index)+ways(money,index+1);
	}else{
		return dp[money][index]=ways(money,index+1);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	double n;
	memset(dp,-1,sizeof (dp));
	while(scanf("%lf",&n)!=EOF){
		
		// we need combinaisons not permutations put that IN YOUR MIND!
		long long res=ways(n,0);
		if(res>1){
			cout << "There are "<<res<<" ways to produce "<< n <<" cents change."<<endl;

		}else{
			cout << "There is only 1 way to produce "<< n << " cents change."<<endl;
		}

	}
    return 0;
}
