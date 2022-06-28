#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
bitset<1020>bs;

void sieve()  {
	bs.set();
	bs[0]=0;
	bs[1]=1;
	primes.push_back(1);
	for(int i=2;i<=1010;i++){
		if(bs[i]){
			for(int j=i*i;j<=1010;j+=i){
				bs[j]=0;
			}
		primes.push_back((int)i);
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
    int n,c;
    while(scanf("%d %d",&n,&c)!=EOF){
    	printf("%d %d:",n,c);
    	int list[1010];
    	int length=0;
    	for(int i=0;i<(int)primes.size();i++){
    		if(primes[i]<=n){
    			list[length++]=primes[i];
    		}else{
    			break;
    		}
    	}
    	if(length&1){
    		c=2*c-1;
    	}else{
    		c=2*c;
    	}
    	if(c>length){
    		c=length;
    	}

    	int i,j;
    	for(i=length/2-c/2,j=0;j<c;j++,i++){
    		printf(" %d",list[i]);
    	}
    	printf("\n\n");

    }


    
    return 0;
}
