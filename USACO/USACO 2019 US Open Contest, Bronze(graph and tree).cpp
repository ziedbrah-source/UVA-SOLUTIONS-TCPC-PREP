#include <bits/stdc++.h>
using namespace std;
int n;
int visitedCount[101];
vector<int> vec[101];
void dfs(int node){
	visitedCount[node]++;
	for(auto u:vec[node]){
		dfs(u);
	}
}
void solve(){

	cin >> n ;
	for(int i=0;i<n-1;i++){
		int from,to;
		cin >> from >> to;
		vec[from].push_back(to);
		// directed graph :)
	}

	for(int i=1;i<=n;i++){
		dfs(i);
	}

	int maxiVisted=0;
	int index=-1;
	for(int i=0;i<=n;i++){
		if(visitedCount[i]>maxiVisted){
			maxiVisted=visitedCount[i];
			index=i;
		}
	}

	if(maxiVisted==n){
		cout << index << endl;
	}else{
		cout << -1 << endl;
	}


}
int main()
{
	/*
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif*/

	// Use standard input to read from "paint.in"
	freopen("factory.in", "r", stdin);
	// Use standard output to write to "paint.out"
	freopen("factory.out", "w", stdout);
	//int tc;
	//cin >> tc;
	//while(tc--){
    //while(scanf("%d %d",&m,&n)!=EOF)
		//toWorkOn.clear();
		solve();
	
	//}
    return 0;
}
