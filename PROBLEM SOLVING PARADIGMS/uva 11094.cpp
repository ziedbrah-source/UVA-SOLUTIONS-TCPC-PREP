#include <bits/stdc++.h>
using namespace std;
int n,m;
char arr[21][21];
bool visited[21][21];

void dfs(int x,int y,char land){
	if(y==n){
		x=0;
	}
	if(y==-1){
		y=n-1;
	}
	if(x==m){
		return ;
	}
	if(x==-1){
		return ;
	}
	if(visited[x][y]){
		return ;
	}

	if(arr[x][y]!=land){
		return ;
	}
	visited[x][y]=true;

	dfs(x+1,y,land);
	dfs(x-1,y,land);
	dfs(x,y+1,land);
	dfs(x,y-1,land);

}
int dfsSum(int x,int y,char land){
	if(y==n){
		x=0;
	}
	if(y==-1){
		y=n-1;
	}
	if(x==m){
		return 0;
	}
	if(x==-1){
		return 0;
	}
	if(visited[x][y]){
		return 0 ;
	}

	if(arr[x][y]!=land){
		return 0;
	}
	visited[x][y]=true;

	return 1+dfsSum(x+1,y,land)+dfsSum(x-1,y,land)+dfsSum(x,y+1,land)+dfsSum(x,y-1,land);
}
void solve(){
	memset(visited,false,sizeof visited);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin >> arr[i][j];
		}
	}

	int X,Y;
	cin >> X >> Y;
	char land=arr[X][Y];
	dfs(X,Y,land);
	

	int maxi=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			maxi=max(maxi,dfsSum(i,j,land));
		}
		
	}
	cout << maxi << endl;







}



int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	//int tc;
	//cin >> tc;
	//while(tc--){
    while(scanf("%d %d",&m,&n)!=EOF)
		solve();
	//}
    return 0;
}
