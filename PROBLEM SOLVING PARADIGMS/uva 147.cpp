#include<bits/stdc++.h>
using namespace std;
	int a[11]={ 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };
	long long dp[30010][12];
	// at first the problem that I was taking consideration of permutations, now we only need combinations (and same cents can be used more than once.)
	long long ways(int mon,int index){
		if(mon<0 ||index==11 ){
			return 0;
		}
		if(mon==0){
			return 1;
		}
		if(dp[mon][index]!=-1){
			return dp[mon][index];
		}
		if(mon-a[index]>-1){
			return dp[mon][index]=ways(mon-a[index],index)+ways(mon,index+1); // we produce subsets (with multiple a[index] if needed :))
		}else{
			return dp[mon][index]=ways(mon,index+1);
		}
	}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	double n;
	while(scanf("%lf",&n),n>0.0001){
		memset(dp,-1,sizeof (dp));
		printf("%6.2lf%17lld\n", n, ways((int)round(n*100),0));
	}
    return 0;
}
