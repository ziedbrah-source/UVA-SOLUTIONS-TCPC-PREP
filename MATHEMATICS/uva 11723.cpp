#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int roadsNumber;
    int numberIntegers;
    int i=0;
    int x;
    while(scanf("%d %d",&roadsNumber,&numberIntegers),roadsNumber!=0&&numberIntegers!=0){
    	i++;
    	if(roadsNumber<=numberIntegers){
    		printf("Case %d: 0\n",i);
    		continue;
    	}
    	int roadsWithSuffix=roadsNumber-numberIntegers;
    	int x = ceil((float)roadsWithSuffix / (float)numberIntegers);
    	if(x>26){
    		printf("Case %d: impossible\n",i);
    		continue;
    	}
    	else{
    		printf("Case %d: %d\n",i,x);
    	}
    }
    
    return 0;
}
