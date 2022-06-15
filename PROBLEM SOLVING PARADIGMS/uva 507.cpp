#include<bits/stdc++.h>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int a[20020];

	int tc;
	int n, maxSI, maxEI, cs;
	cs=1;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(int i=1;i<=n-1;i++){
			cin >> a[i];
		}


	int maxi=-1e9;
	int sum=0;
	int end=1;
	for(int i=1;i<=n-1;i++){
		sum+=a[i];
		if(sum<0){
			sum=0;
			end=i+1;
		}
		if(maxi<sum || (sum == maxi && (maxEI-maxSI < i- end))){
			maxi=sum;
			maxEI=i;
			maxSI=end; // because last time we affected end -> i+1 (it's the start :) )

		}

	}
	    if(maxi > 0)printf("The nicest part of route %d is between stops %d and %d\n", cs++, maxSI, maxEI+1);
        else printf("Route %d has no nice parts\n", cs++);
	}
    return 0;
}
