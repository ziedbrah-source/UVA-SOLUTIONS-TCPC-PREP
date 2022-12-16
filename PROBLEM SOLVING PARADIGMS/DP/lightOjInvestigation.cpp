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
// problem link :https://lightoj.com/problem/investigation
typedef long long ll;
typedef long double ld;
ll m,k,q,t,g,l,r;
const int prime=1e9+7;
ll getVal(int v){
	ll val=1;
	for(int i=1;i<v;i++) val*=10;
	return val;
}
ll dp[12][2][90][90];
const ll INF=2e18;
ll solveRec(string& num,int pos,bool tight,int currSum,int currReminder){
	if(pos==0 && currSum==0 && currReminder==0) {
		return 1;
	}
	if(pos==0) return 0;
	if(dp[pos][tight][currSum][currReminder]!=-1) return dp[pos][tight][currSum][currReminder];
	int upperBound=9;
	if(tight){
		upperBound= num[num.length()-pos]-'0';
	}
	ll res=0;
	for(int i=0;i<=upperBound;i++){
		ll val=currReminder+i*getVal(pos);
		res+=solveRec(num,pos-1,tight&(i==upperBound),(currSum+i)%k,val%k);
	}
	return dp[pos][tight][currSum][currReminder]=res;
}
int c=0;
void solve(){
	cin >> l >> r >> k;
	if(k>83) {
		cout << "Case " << c <<": " << 0 << "\n";
		return;
	}
	l--;
	string R=to_string(r);
	string L=to_string(l);
	memset(dp,-1,sizeof dp);
	ll res=solveRec(R,R.length(),1,0,0);
	//cout <<R[0] << "\n";
	memset(dp,-1,sizeof dp);
	res-=solveRec(L,L.length(),1,0,0);
	cout << "Case " << c <<": " << res << "\n";
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
