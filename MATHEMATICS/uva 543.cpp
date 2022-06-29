#include <bits/stdc++.h>
using namespace std;

//vector<long long> primes;
bitset<1000010>bs;

void sieve()  {
	bs.set();
	bs[0]=0;
	bs[1]=0;
	//int root = sqrt(1000010);
	for(long long i=2;i<=1000010;i++){
		if(bs[i]){
			for(long long j=i*i;j<1000010;j+=i){
				bs[j]=0;
			}
		//primes.push_back((int)i);
		}

	}
}


int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    sieve();// sieve function to generate the prime numbers;
    int n;
    int x=0,y=0;
    while(scanf("%d",&n),n>0){
    	for(int i=2;i<n;i++){
    		int intermed=n-i;
    		if(bs[intermed]){
    			if(bs[i]){
    				x=i;
    				y=intermed;
    				break;
    			}

    		}
    	}
    	printf("%d = %d + %d\n",n,x,y);
    }


    
    return 0;
}
