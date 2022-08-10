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
map<char,int> counterOfChars;
int counter1=0;
int counter=0;
void add(char x){
	counterOfChars[x]++;
	if(counterOfChars[x]==1){
		counter1++;
	}
}
void del(char x){
	counterOfChars[x]--;
	if(counterOfChars[x]==0){
		counter1--;
	}
}
check(char x){
	int counter=counterOfChars[x];
	if(counter>1){
		return false;
	}
	return true;
}
void solve(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<char,bool> mp;
	cin >> n;
	
	string input;
	cin >> input;
	for(int i=0;i<n;i++){
		if(!mp[input[i]]){
			counter++;
			mp[input[i]]=true;
		}
	}
	int l=0;
	int minimumLength=n;

	for(int r=0;r<n;r++){
		add(input[r]);
		while(counter1==counter&&!check(input[l])){
			del(input[l]);
			l++;
		}
		if(counter1==counter){
			minimumLength=min(minimumLength,r-l+1);
		}

		
		
	}

	cout << minimumLength << endl;
}
int main()
{
	
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	// Use standard input to read from "paint.in"
	//freopen("pairup.in", "r", stdin);
	// Use standard output to write to "paint.out"
	//freopen("pairup.out", "w", stdout);
	//int tc;
	//cin >> tc;
	//while(tc--){
    //while(scanf("%d %d",&m,&n)!=EOF)
		solve();
	
	//}
    return 0;
}

