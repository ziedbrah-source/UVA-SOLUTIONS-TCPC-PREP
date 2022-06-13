#include<bits/stdc++.h>
using namespace std;
int M,C,price[25][25];
int memo[215][25];
int shop(int money,int g){
	if(money < 0 ){
		return -1e9;
	}
	if(g==C){
		return M-money; //we must maximize this.
	}
	if(memo[money][g]!=-1){
		return memo[money][g];
	}
	int ans=-1;
	for(int i=0;i<price[g][0];i++){
		ans=max(ans,shop(money-price[g][i+1],g+1));
	}
	memo[money][g]=ans;
	return ans;
}
int main ()
{
		#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int tc;
	int score;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&M,&C);
		for(int i=0;i<C;i++){ 
			// garment i;
			scanf("%d",&price[i][0]); // in price[i][0] there is the number of models for i'th garment
			for(int j=1;j<=price[i][0];j++){
				scanf("%d",&price[i][j]);
			}
		}
		memset(memo,-1,sizeof(memo)); // init to -1 
		score=shop(M,0);
		if(score<0){
			printf("no solution\n");
		}else{
			printf("%d\n",score);
		}

	}
    return 0;
}