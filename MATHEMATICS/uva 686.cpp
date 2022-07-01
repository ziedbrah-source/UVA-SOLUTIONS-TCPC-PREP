#include <bits/stdc++.h>
using namespace std;

//vector<long long> primes;
queue<int> otherPartsToReinitialise;
int PairsDone[33000];
bitset<33000>bs;
void sieve()  {
	bs.set();
	bs[0]=0;
	bs[1]=0;
	//int root = sqrt(1000010);
	for(long long i=2;i<=33000;i++){
		if(bs[i]){
			for(long long j=i*i;j<33000;j+=i){
				bs[j]=0;
			}		}

	}
}

int solve(int input){
	int counter=0;
	int theOtherPart=0;
	for(int i=1;i<input;i++){
		theOtherPart=input-i;
		if(bs[i]){
			if(PairsDone[theOtherPart]==-1){
				if(bs[theOtherPart]){
					counter++;
					PairsDone[theOtherPart]=1;
					PairsDone[i]=1;
					otherPartsToReinitialise.push(theOtherPart);
					otherPartsToReinitialise.push(i);
				}
			} 

		}
	}
	 while (!otherPartsToReinitialise.empty()) {
        PairsDone[otherPartsToReinitialise.front()]=-1;
        otherPartsToReinitialise.pop();
    }

	return counter;
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
    sieve();// sieve function to generate the prime numbers;
    memset(PairsDone,-1,sizeof PairsDone);

    int n;
    int x=0,y=0;
    while(scanf("%d",&n),n>0){
    	int res=solve(n);
    	cout<< res<<endl;
    }


    
    return 0;
}
