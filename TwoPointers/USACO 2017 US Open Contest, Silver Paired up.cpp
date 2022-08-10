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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	vector<pair<long long,long long>> vec;
	int n;
	cin >>n;
	long long counter=0;
	for(int i=0;i<n;i++){
		long long number;
		long long val;
		cin >> number;
		counter+=number;
		cin >> val;
		vec.push_back({val,number});

	}

	sort(vec.begin(),vec.end());

	long long maximum=0;

	int l=0;
	int r=n-1;

	while(l<r){
		if(vec[r].second>0&&vec[l].second>0){
			maximum=max(vec[l].first+vec[r].first,maximum);
			vec[r].second--;
			vec[l].second--;
		}else if(vec[r].second==0){
				r--;
				
		}else if(vec[l].second==0){
			l++;
		}else {
			r--;
			l++;
		}
		

	}
	cout << maximum << endl;

}
int main()
{
	/*
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif*/

	// Use standard input to read from "paint.in"
	freopen("pairup.in", "r", stdin);
	// Use standard output to write to "paint.out"
	freopen("pairup.out", "w", stdout);
	//int tc;
	//cin >> tc;
	//while(tc--){
    //while(scanf("%d %d",&m,&n)!=EOF)
		solve();
	
	//}
    return 0;
}

