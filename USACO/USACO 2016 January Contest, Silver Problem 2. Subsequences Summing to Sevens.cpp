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
int n;
void prefixSum(vector<long long>& pref,vector<long long>& nonPref){
	pref[0]=0;
	for(int i=1;i<=n;i++){
		pref[i]=pref[i-1]+nonPref[i];
	}
}



void solve(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	vector<long long> vec(n+1);
	vector<long long> pref(n+1);
	map<int, int> mp;
	for(int i=1;i<=n;i++){
		cin >> vec[i];
	}

	prefixSum(pref,vec);
	int MaxInterval=0;
	mp[0]=0;
	for(int i=1;i<=n;i++){
		if(pref[i]%7==0){
			MaxInterval=max(MaxInterval,i);
		}
		else if(mp[pref[i]%7]==0){
			mp[pref[i]%7]=i;
		}else{
			MaxInterval=max(MaxInterval,i-mp[pref[i]%7]);
		}
	}
	cout << MaxInterval <<endl;




}
int main()
{
	/*
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif*/

	// Use standard input to read from "paint.in"
	freopen("div7.in", "r", stdin);
	// Use standard output to write to "paint.out"
	freopen("div7.out", "w", stdout);
	//int tc;
	//cin >> tc;
	//while(tc--){
    //while(scanf("%d %d",&m,&n)!=EOF)
		solve();
	
	//}
    return 0;
}

