#include <bits/stdc++.h>
using namespace std;

/*
// how to sort+ use the iterator:)
	std::sort(v.begin(), v.end(), std::greater<int>());
  
    std::vector<int>::iterator low, up;
    low = std::lower_bound(v.begin(), v.end(), 3, std::greater<int>());         
    up = std::upper_bound(v.begin(), v.end(), 5, std::greater<int>()); 
*/

// #PREFIX SUM 1 index Based.
int n,m;

/*
bool comp(string s1,string s2){
	// return the one smaller lexicographically
	return s1+s2 < s2+s1;
}*/
long long dp[101][101][101][101];
long long arr[100];
long long solveDp(long long somme,int currIndex,int goal,int totalIndex){
	if(currIndex==goal){
		if(somme==0){
			return 1;
		}
		return 0;
	}
	if(dp[somme%goal][currIndex][goal][totalIndex]!=-1){
		return dp[somme%goal][currIndex][goal][totalIndex];
	}
	if(totalIndex==n){
		return 0;
	}
	return dp[somme%goal][currIndex][goal][totalIndex]=(solveDp(somme%goal,currIndex,goal,totalIndex+1)+solveDp((somme+arr[totalIndex])%goal,currIndex+1,goal,totalIndex+1))%998244353;
}
void solve(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}

	long long answer=0;
	memset(dp,-1 ,sizeof dp);
	for(int i=1;i<=n;i++){

		answer=(answer%998244353+solveDp(0,0,i,0)%998244353)%998244353;
	}
	cout << answer<<endl;
}
int main()
{
	
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	// Use standard input to read from "paint.in"
	//freopen("maxcross.in", "r", stdin);
	// Use standard output to write to "paint.out"
	//freopen("maxcross.out", "w", stdout);
	//int tc;
	//cin >> tc;
	//while(tc--){
    //while(scanf("%d %d",&m,&n)!=EOF)
		solve();
	
	//}
    return 0;
}

