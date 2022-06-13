#include<bits/stdc++.h>
using namespace std;
int val[] = { 60, 100, 120 };
int wt[] = { 10, 20, 30 };
int W = 50;
int knapSack(int weight,int n){
	if(n==0 || weight==0){
		return 0; //can't add any thing , profit is 0.
	}
	if(weight<wt[n-1]){
		return knapSack(weight,n-1);
	}else{
		return max(val[n - 1]+knapSack(weight-wt[n-1],n-1),knapSack(weight,n-1));// choose if you want to pick it or no. this way we will generate all subsets and test the maximum of them all
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
    

    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, n);
    return 0;
}