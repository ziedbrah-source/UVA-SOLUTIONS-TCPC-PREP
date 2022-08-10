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

/*
bool comp(string s1,string s2){
	// return the one smaller lexicographically
	return s1+s2 < s2+s1;
}*/



void solve(){
	long long n,t;
	cin >> n >> t;
	vector<int> vec(n);
	for(int i=0;i<n;i++){
		cin >> vec[i];
	}

	int l=0;
	int maxLength=0;
	int sum=0;
	// two pointers Method (because we have a good interval and inside it also good, so we can use the two points method.)
	for(int r=0;r<n;r++){
		sum+=vec[r];
		while(sum>t){
			sum-=vec[l];
			l++;
		}

		maxLength=max(maxLength,r-l+1);
	}

	cout << maxLength << endl;


}
int main()
{
	
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	// Use standard input to read from "paint.in"
	//freopen("diamond.in", "r", stdin);
	// Use standard output to write to "paint.out"
	//freopen("diamond.out", "w", stdout);
	//int tc;
	//cin >> tc;
	//while(tc--){
    //while(scanf("%d %d",&m,&n)!=EOF)
		solve();
	
	//}
    return 0;
}

