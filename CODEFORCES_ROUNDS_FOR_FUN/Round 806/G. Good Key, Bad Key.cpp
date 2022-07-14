#include <bits/stdc++.h>
using namespace std;


int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
    int tc;
    int n;
    int k;
    cin >> tc;
    while(tc--){
    	cin >> n >> k ;
    	int arr[n];
    	for(int i=0;i<n;i++){
    		cin >> arr[i];
    	}

    	long long sum=0;
    	long long ans=0;
    	for(int i=-1;i<n;i++){
    		long long now=sum;
    		for(int j=i+1;j<min(n,i+32);j++){
    			int copy=arr[j];
    			copy >>= j-i; // division / 2 plusieurs fois. what an implementation!
    			now+=copy;
    		}
    		ans=max(now,ans);
    		if(i+1!=n){
    			sum+=arr[i+1]-k;
    		}
    	}
    	cout <<ans << endl;
    }
     return 0;
}
