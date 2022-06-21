#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long n1;
    long long n2;
    while(scanf("%lld %lld",&n1,&n2)!=EOF){
    	//The input numbers are not greater than 2 to the power of 32. it's more than 2^31-1 so we use long long :) or unsigned INT
    	cout << abs(n2-n1)<<endl;;
    }

    
    return 0;
}
