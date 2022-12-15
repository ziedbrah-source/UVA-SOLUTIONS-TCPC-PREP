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
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// problem link : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043b0c6#problem
typedef long long ll;
typedef long double ld;
ll m,k,q,t,g,l,r;
//int dp[nax][na];
const int prime=1e9+7;
ll dp[20][2][2][2];
const ll INF=2e18;
// leading==true means that at this point we sill leading by ZERO
int c=0;
ll solveRec(string& num,int n,bool even,bool leading,bool tight){
	if(n==0&&!leading){
		 return 1;
	}else if(n==0 && leading) return 0;
	int upperBound=9;
	if(dp[n][even][leading][tight]!=-1) return dp[n][even][leading][tight];
	if(tight){
		upperBound=num[num.length()-n]-'0';
	}
	if(even){
		vector<int> digits={0,2,4,6,8};
		ll res=0;
		for (int dig:digits){	
			if(dig<=upperBound) res+=solveRec(num,n-1,0,0,(tight&&(dig==upperBound)));
		}
		return dp[n][even][leading][tight]=res;	
	}else{
		vector<int> digits={1,3,5,7,9};
		ll res=0;
		if(leading){
			res+=solveRec(num,n-1,0,1,0);
		}
		for (int dig:digits){
			
			if(dig<=upperBound) {res+=solveRec(num,n-1,1,0,(tight&&(dig==upperBound)));}
		}
		return dp[n][even][leading][tight]=res;		
	}
}
void solve(){
	cin >> l >> r;
	l--;
	string R=to_string(r);
	string L=to_string(l);
	memset(dp,-1,sizeof dp);
	ll res=solveRec(R,R.length(),0,1,1);
	//cout <<R[0] << "\n";
	memset(dp,-1,sizeof dp);
	res-=solveRec(L,L.length(),0,1,1);
	cout << "Case #" << c <<": " << res << "\n";
}



	
 
 
 
int main() {
	fastInp;
	//freopen("mootube.in","r",stdin);
	//freopen("mootube.out","w",stdout);
	int tc=1;
	//cout << res[9] << "\n";
	//reverse(res.begin(),res.end());
	
	cin >> tc;
	//cout << setprecision(10)<<fixed;
	//int i=1;
	//tempTC=tc;
	while(tc--){
		//cout <<"HELLO"<<endl;
		//cout << "Case #"<<i<<": " ;
		//cout << setprecision(10) << "\n";
		c++;
		solve();
		//i++;
	}
	/*Slong long number;
	while(cin >> number){
		if(number==0) break;
		long long i=(long long)sqrt(number);
		if(i*i==number){
			cout <<"yes"<<"\n";
		}else{
			cout <<"no"<<"\n";
		}
		
	}*/
	
	/*while(true){
		cin >> n >> m >>coin;
 
		if(n==0 && m==0&&coin==0){
			break;
		}
		solveUVA();
	}
	*/
	return 0;
}
