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
		cin >> val;
		a[i]=val;
	}
	// try all i,j pairs and compute from i to j and test if it's maxi
	int maxi=-1e9;
	int sum;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			sum=0;
			for(int k=i;k<=j;k++){
				sum+=a[k];
			}
			maxi=max(maxi,sum);
		}
	}
	cout << maxi;
    return 0;
}
