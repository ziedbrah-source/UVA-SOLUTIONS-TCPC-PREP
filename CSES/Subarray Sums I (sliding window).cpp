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
int n,x;
void prefixSum(vector<long long>& pref,vector<long long>& nonPref){
	pref[0]=0;
	for(int i=1;i<=n;i++){
		pref[i]=pref[i-1]+nonPref[i];
	}
}



void solve(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> x;
	vector<int> vec(n);
	for(int i=0;i<n;i++){
		cin >> vec[i];
	}

	int counter=0;
	int i=0;
	int j=0;
	int sum=0;

	while(i<n){
		sum+=vec[i];
		while(sum>=x){
			if(sum==x){
				counter++;
			}
			sum-=vec[j];
			j++;

		}
		
		i++;
	}
	cout << counter << endl;



}
int main()
{
	
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	// Use standard input to read from "paint.in"
	//freopen("div7.in", "r", stdin);
	// Use standard output to write to "paint.out"
	//freopen("div7.out", "w", stdout);
	//int tc;
	//cin >> tc;
	//while(tc--){
    //while(scanf("%d %d",&m,&n)!=EOF)
		solve();
	
	//}
    return 0;
}

