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
    cin >> tc;
    while(tc--){
    	cin >> n ;
    	int arr[n][n];
    	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++){
    			char input;
    			cin >> input;
    			arr[i][j]=input-'0';

    		}
    	}
    	int l=0;
    	int r=n-1;
    	int sum=0;
    	while(l<r){

    		for(int i=0;i<r-l;i++){
    			int top=l;
    			int bottom=r;
    			int summation=arr[top][l+i]+arr[bottom-i][l]+arr[bottom][r-i]+arr[top+i][r];
    			sum+=min(summation,4-summation); // zeros or ones 
    		}
    		l++;
    		r--;
    	}
    	cout <<sum << endl;


    	
    }
     return 0;
}
