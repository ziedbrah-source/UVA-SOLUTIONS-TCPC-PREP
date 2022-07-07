#include <bits/stdc++.h>
using namespace std;


int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
    int tc;
    scanf("%d",&tc);
    int n;

    // A + B = A XOR B + (A and B)>>1
    // -> (AxorB)+(BxorC) + (a xor C) has the same parity as (A+b) + (B +c)+ (a + c) = 2(a+b+c) -> there is a solution if n is even.
    while(tc--){
    	scanf("%d",&n);
    	if(n%2){
    		printf("-1\n");
    		continue;
    	}

    	printf("0 0 %d\n",n/2);

    }




	
    return 0;
}
