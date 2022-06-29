#include <bits/stdc++.h>
using namespace std;

//vector<long long> primes;
bitset<20000010>bs;
vector<pair<int,int>> sThtwin;
void sieve()  {
	bs.set();
	bs[0]=0;
	bs[1]=0;
	//int root = sqrt(1000010);
	for(long long i=2;i<=20000010;i++){
		if(bs[i]){
			for(long long j=i*i;j<20000010;j+=i){
				bs[j]=0;
			}		}

	}
}


int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    sieve();// sieve function to generate the prime numbers;
    // precalculate stuff, complexity goes from O(testcase*n) to O(n);
        for(int i=0;i<20000010;i++){
    	if(bs[i]){
    		if(bs[i+2]){
    			sThtwin.push_back(make_pair(i,i+2));
    		}
    	}
    }
    int n;
    int x=0,y=0;
    while(scanf("%d",&n)!=EOF){
    	pair<int,int> res=sThtwin[n-1];
    	printf("(%d, %d)\n",res.first,res.second);
    }


    
    return 0;
}
