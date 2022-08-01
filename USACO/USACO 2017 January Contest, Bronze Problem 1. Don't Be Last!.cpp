#include <bits/stdc++.h>
using namespace std;


void solve(){
	int n;
	cin>>n;
	map<string,int> m;
	map<int,string> sum;
	map<int,int> occ;
	string input;
	int milkLog;
	set<int> s;
	for(int i=0;i<n;i++){
		cin >> input;
		cin >> milkLog;
		m[input]+=milkLog;
	}
	int counter=0;
	for (auto& x : m) {
		s.insert(x.second);
		counter++;
		sum[x.second]=x.first;
		occ[x.second]++;
	}
	if(counter<7){
		auto it=s.upper_bound(0); // first one > 0;
		if(it!=s.end()){
			if(occ[*it]>=2){
				cout << "Tie" << endl;
			}else{
				cout << sum[*it]<<endl;
			}
		}else{
			cout <<"Tie"<<endl;
		}
	}else{
	
		auto iter=s.begin();
		auto it=s.upper_bound(*iter);
		if(it!=s.end()){
			if(occ[*it]>=2){
				cout<< "Tie" << endl;
			}else{
				cout << sum[*it]<<endl;
			}
		}else{
			cout <<"Tie"<<endl;
		}

	}


	
}
int main()
{
	/*
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif*/

	// Use standard input to read from "paint.in"
	freopen("notlast.in", "r", stdin);
	// Use standard output to write to "paint.out"
	freopen("notlast.out", "w", stdout);
	//int tc;
	//cin >> tc;
	//while(tc--){
    //while(scanf("%d %d",&m,&n)!=EOF)
		//toWorkOn.clear();
		solve();
	
	//}
    return 0;
}
