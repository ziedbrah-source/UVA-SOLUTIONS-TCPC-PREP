#include <bits/stdc++.h>
using namespace std;

long long solve(long long k){
	long long cycleLengh=1;
	while(k!=1){
		cycleLengh++;
		if(k%2!=0){
			k=3*k+1;
		}else{
			k=k/2;
		}
	}
	return cycleLengh;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long i;
    long long j;
    while(scanf("%lld %lld",&i,&j)!=EOF){
    	bool switched=false;
    	if(i>j){
    		switched=true;
    		long long temp=j;
    		j=i;
    		i=temp;
    	}
    	long long maximum=-1;
    	for(long long k=i;k<=j;k++){
    		maximum=max(maximum,solve(k));
    	}
    	if(switched){
    		cout <<j<<" "<<i<< " "<<maximum<<endl;
    	}else{
    		cout <<i<<" "<<j<< " "<<maximum<<endl;
    	}
    }
    
    return 0;
}
