#include<bits/stdc++.h>
using namespace std;
int val[1010];
int wt[1010];
int dp[1010][1010];
/*int knapSack(int weight,int n){
	if(n==0 || weight==0){
		return 0; //can't add any thing , profit is 0.
	}
	if(weight<wt[n-1]){
		return knapSack(weight,n-1);
	}else{
		return max(val[n - 1]+knapSack(weight-wt[n-1],n-1),knapSack(weight,n-1));// choose if you want to pick it or no. this way we will generate all subsets and test the maximum of them all
	}
}*/
    int knapSackHelper(int W,int n){
        if(n==0 || W==0){
            return 0;}
        if(dp[W][n-1]!=-1){
            return dp[W][n-1];
        }
        if(W<wt[n-1]){
            dp[W][n-1]= knapSackHelper(W,n-1);
            return dp[W][n-1];
        }else{
            dp[W][n-1]=max(val[n-1]+knapSackHelper(W-wt[n-1],n-1),knapSackHelper(W,n-1));
            return dp[W][n-1];
        }
        
    }
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
    memset(dp,-1,sizeof dp);
    int n;
    scanf("%d",&n);
    int w;
    scanf("%d",&w);
    for(int i=0;i<n;i++){
    	cin >> val[i];
    }


    for(int i=0;i<n;i++){
    	cin >> wt[i];
    }

    cout << knapSackHelper(w, n);
    return 0;
}
