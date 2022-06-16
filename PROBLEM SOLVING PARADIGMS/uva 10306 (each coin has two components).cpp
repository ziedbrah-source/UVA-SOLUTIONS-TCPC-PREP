#include<bits/stdc++.h>
using namespace std;

pair<int, int> coordinates[40];
int s;
int dp[305][305][42];
int currModulos(int x,int y){
	return x * x + y * y;
}
int minimumCoins(int x,int y,int pairs){
	int currentModulos=currModulos(x,y);
	if(currentModulos>s||pairs==-1){
		return 1e9; // this combinaison cannot lead to noth.
	}
	if(currentModulos==s){
		return 0; // we got it :D
	}
	if(dp[x][y][pairs]!=-1){
		return dp[x][y][pairs];
	}
	return dp[x][y][pairs]=min(1+minimumCoins(x+coordinates[pairs].first,y+coordinates[pairs].second,pairs),minimumCoins(x,y,pairs-1));
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int tc;
	int m;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&m,&s);
		memset(dp,-1,sizeof dp);
		for(int i = 0; i < m; ++i)
			cin >> coordinates[i].first >> coordinates[i].second;
		s*=s; // make it easier.
		int res=minimumCoins(0,0,m-1);
		if(res>=1e9){
			cout << "not possible" << endl;
		}else{
			cout << res << endl;
		}

	}
    return 0;
}
