#include <bits/stdc++.h>
using namespace std;



void solve(){
	int n;
	cin>> n ;
	vector<pair<int,int>> points(n);

	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >>y;
		points[i]=make_pair(x,y);
	}

	int maximumTriangle=0;
	for(int i=0;i<points.size();i++){
		// same x so // to Y axe
		for(int j=0;j<points.size();j++){
			if(j==i){
				continue;
			}
			if(points[i].first==points[j].first){
				// check the y == y , // to x axe
				for(int k=0;k<points.size();k++){
					if(i==k || j==k){
						continue;
					}
					if(points[j].second==points[k].second){
						maximumTriangle=max(maximumTriangle,(abs(points[j].first-points[k].first)*abs(points[i].second-points[j].second)));
					}
				}
			}
		}
		//---
		for(int j=0;j<points.size();j++){
			if(j==i){
				continue;
			}
			if(points[i].second==points[j].second){
				// check the y == y , // to x axe
				for(int k=0;k<points.size();k++){
					if(i==k || j==k){
						continue;
					}
					if(points[j].first==points[k].first){
						maximumTriangle=max(maximumTriangle,(abs(points[j].second-points[k].second)*abs(points[i].first-points[j].first)));
					}
				}
			}
		}		
	}
	cout << maximumTriangle << endl;
}
int main()
{
	/*
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif*/

	// Use standard input to read from "paint.in"
	freopen("triangles.in", "r", stdin);
	// Use standard output to write to "paint.out"
	freopen("triangles.out", "w", stdout);
	//int tc;
	//cin >> tc;
	//while(tc--){
    //while(scanf("%d %d",&m,&n)!=EOF)
		solve();
	
	//}
    return 0;
}
