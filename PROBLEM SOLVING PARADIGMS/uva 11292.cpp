#include<bits/stdc++.h>
using namespace std;
int main ()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int n;
	int m;
	int headsDiameters[20010];
	int headDiameter;
	int height;
	int heights[20010];
	while(scanf("%d %d",&n,&m)){
		if(n==0&&m==0){
			return 0;
		}
		/*if(n>m){
			printf("Loowater is doomed!\n");
			continue;
		}*/
		for(int i=0;i<n;i++){
			scanf("%d",&headDiameter);
			headsDiameters[i]=headDiameter;
		}
		for(int i=0;i<m;i++){
			scanf("%d",&height);
			heights[i]=height;
		}
		sort(heights,heights+m);
		sort(headsDiameters,headsDiameters+n);
		//we want to take the minimimum knight that can kill the head of the dragon.
		// so we sort heights and headsDiameters in increasing order and select the first height >= diameter 
		int j=0;
		int k=0;
		int gold=0;
		while(j<n && k<m){
			while(headsDiameters[j]>heights[k] && k<m){
				k++;
			}
			if(k==m){
				break;
			}
			gold+=heights[k];
			j++;
			k++;
		}
		if(j==n){
			printf("%d\n",gold );
		}else{
			printf("Loowater is doomed!\n");
		}


	}
    return 0;
}