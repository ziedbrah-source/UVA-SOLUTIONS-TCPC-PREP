#include<bits/stdc++.h>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int a[1000];

	int n;
	scanf("%d",&n);
	int val;
	for(int i=0;i<n;i++){
		cin >>a[i];

	}
	// try all i,j pairs and compute from i to j and test if it's maxi
	int maxi=-1e9;
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
		maxi=max(maxi,sum);
		if(sum<0){
			sum=0;
		}
	}
	cout << maxi;
    return 0;
}
