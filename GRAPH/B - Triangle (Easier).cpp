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
void solve(){
	cin >> n >> m;
	vector<int> adj[n];
	for(int i=0;i<m;i++){
		int from, to ;
		cin >> from >> to;
		from--;
		to--;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}

	int counter=0;
	/*
	for(int i=0;i<n;i++){
		for(auto x:adj[i])
			for(auto s:adj[x]){
				for(auto h:adj[s]){
					if(h==i){
						counter++;
					}
				}
			}
	}*/
	for(int i=0;i<n;i++){
		for(int j=0;j<adj[i].size();j++){
			for(int k=0;k<adj[j].size();k++){
				for(int h=0;h<adj[k].size();h++){
					if(adj[k][h]==i){
						counter++;
					}
				}
			}
		}
	}
	cout << counter/6 <<endl;
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

