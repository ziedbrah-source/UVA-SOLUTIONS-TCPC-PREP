//============================================================================
// Name        : Brahmi Zied
// Author      : brahZied
// Version     : 2022
// Description : Road to specialist
//============================================================================
/*
    STAY ORGANIZED
    CHANGE YOUR APPROACH
    BE CONFIDENT
*/

//Think different approaches (bs,dp,greedy,graphs,shortest paths,mst,dsu,LCA(binary lifting?))
//Stay Calm
//Look for special cases
//Beware of overflow and array bounds
//Think the problem backwards
#include <bits/stdc++.h>
using namespace std;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
// prob link : https://cses.fi/problemset/task/1667/
typedef long long ll;
typedef long double ld;
ll n,m,k,t,g,l,r,a,b,d,p;
const int prime=1e9+7;
const int Nax=1e5+10;
vector<int> adj[Nax];
bool visited[Nax];
vector<int> parent(Nax);
void bfs(){
	queue<int> q;
	q.push(0);
	visited[0]=true;
	while(!q.empty()){
		int node=q.front();
		q.pop();
		for(int i=0;i<(int)adj[node].size();i++){
			if(!visited[adj[node][i]]){
				visited[adj[node][i]]=true;
				q.push(adj[node][i]);
				parent[adj[node][i]]=node;
			}
		}
	}
}
void solve(){
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int from,to;
		cin >> from >> to;
		from--;to--;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}
	bfs();
	
	if(!visited[n-1]){
		cout <<"IMPOSSIBLE"<<"\n";
		return;
	}
	
	vector<int> res;
	int val=n-1;
	while(val!=0){
		res.push_back(val);
		val=parent[val];
	}
	res.push_back(0);
	
	cout << res.size() << "\n";
	
	for(int i=(int)res.size()-1;i>=0;i--){
		cout << res[i]+1 << " ";
	}
	cout <<"\n";
}



	
 
 
 
int main() {
	fastInp;
	//freopen("mootube.in","r",stdin);
	//freopen("mootube.out","w",stdout);
	int tc=1;

	while(tc--){
		solve();
	}
	return 0;
}
