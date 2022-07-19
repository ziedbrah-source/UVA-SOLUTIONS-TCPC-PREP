#include <bits/stdc++.h>
using namespace std;
int n,m;
bool visited[101];
vector<vector<int>> graph;
vector<int> ans;
void dfs(int node){
	visited[node]=true;
	for(int i=0;i<graph[node].size();i++){
		int child=graph[node][i];
		if(!visited[child]){
			dfs(child);
		}
	}

	//ans.insert(ans.begin(), node +1);
	ans.push_back(node+1);
	//cout << node+1;
}
void solve(){
	

	int x,y;
	graph.clear();
	graph.assign(n+1, vector<int>());
	ans.clear();
	for (int i = 0; i < m; ++i) {
			cin >> x >> y;
			graph[y - 1].push_back(x - 1);
	}

	for(int i=0;i<n;i++){
		if(!visited[i]){
			dfs(i);
		}
	}
	for (int i = 0; i < (int)ans.size(); i++){
		cout << ans[i] << " \n"[i == (int)ans.size() - 1];
	}






}


int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	//int tc;
	//cin >> tc;

	while(scanf("%d%d",&n,&m)){
		if(n==0&&m==0){
			break;
		}
		memset(visited,false,sizeof visited);
		solve();
	

	} 
    return 0;
}
