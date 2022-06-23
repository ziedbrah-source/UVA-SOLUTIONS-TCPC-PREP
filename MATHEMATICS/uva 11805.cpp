#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc;
    int i=0;
    scanf("%d",&tc);
    int n;
    int k;
    int p;
    while(tc--){
    	i++;
    	scanf("%d %d %d",&n,&k,&p);
    	int player=(k+p)%(n);
    	if(player==0){
    		cout << "Case "<< i << ": " << n << endl;
    	}else{
    		cout << "Case "<< i << ": " << player << endl;
    	}
    	
    }
    
    return 0;
}
