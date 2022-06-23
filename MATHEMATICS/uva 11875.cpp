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
    // we can ignore the array. useless.
    int arr[11];
    int n;
    while(tc--){
    	i++;
    	scanf("%d",&n);
    	for(int j=0;j<n;j++){
    		cin >> arr[j];
    	}
    	cout << "Case "<< i << ": "<<arr[n/2]<<endl;
    	
    }
    
    return 0;
}
