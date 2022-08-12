#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);
/*
// how to sort+ use the iterator:)
	std::sort(v.begin(), v.end(), std::greater<int>());
  
    std::vector<int>::iterator low, up;
    low = std::lower_bound(v.begin(), v.end(), 3, std::greater<int>());         
    up = std::upper_bound(v.begin(), v.end(), 5, std::greater<int>()); 
*/

// #PREFIX SUM 1 index Based.

/*
bool comp(string s1,string s2){
	// return the one smaller lexicographically
	return s1+s2 < s2+s1;
}*/
int n,m;
const int maxN=3010;
vector<int> vec[maxN]; 
bool visited[maxN];
bool cleared[maxN];
int lastNode=-1;
int newNode=-1;
int counter;
void dfs(int node){
	visited[node]=true;
	lastNode=node;
	counter++;
	for (int i = 0; i < (int)vec[node].size(); i++)
	{
		if(!visited[vec[node][i]]&&!cleared[vec[node][i]]){
			dfs(vec[node][i]);
			}
	}
	
}
void solve(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	set<int> s;
	for(int i=0;i<n;i++){
		s.insert(i+1);
	}
	
	for (int i = 0; i < m; i++)
	{
		int from,to;
		cin >> from >> to;
		vec[from].push_back(to);
		vec[to].push_back(from);
	}
	
	for (int i = 0; i < n; i++)
	{
		counter=0;
		memset(visited,false,sizeof visited);
		auto it=s.end();
		--it;
		dfs(*it);
		if(counter==(int)s.size()){
			cout << "YES" <<endl;
		}else{ cout <<"NO" << endl;}
		int toBeCleared;
		cin >> toBeCleared;
		cleared[toBeCleared]=true;
		s.erase(toBeCleared);
	}
	
	
	
	
}
int main()
{
	
	// Use standard input to read from "paint.in"
	freopen("closing.in", "r", stdin);
	// Use standard output to write to "paint.out"
	freopen("closing.out", "w", stdout);
	//int tc;
	//cin >> tc;
	//while(tc--){
    //while(scanf("%d %d",&m,&n)!=EOF)
		solve();
	
	//}
    return 0;
}
