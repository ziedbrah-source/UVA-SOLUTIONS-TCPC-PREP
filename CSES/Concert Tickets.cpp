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
void solve(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	multiset<int> multi;
	for(int i=0;i<n;i++){
		int val;
		cin>> val;
		multi.insert(val);
	}

	for(int i=0;i<m;i++){
		int maximumPrice;
		cin >> maximumPrice;
		
		if(multi.size()>=1){
			auto it=multi.lower_bound(maximumPrice); // greater or equal to maximumPrice
			if(it==multi.begin()){
				if(*it>maximumPrice){
					cout << -1 <<endl;
				}else if(*it==maximumPrice){
					cout << *it << endl;
					multi.erase(multi.find(*it));
				}
			}else if(it==multi.end()){
				cout << *(--it)<<endl;
				multi.erase(multi.find(*it));	
							
			}else{
				if(*it>maximumPrice){
					cout << *(--it)<<endl;
				}else{
					cout << *it << endl;	
				}				
				multi.erase(multi.find(*it));
			}
		}else{
			cout << -1 << endl;
		}
	}
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

