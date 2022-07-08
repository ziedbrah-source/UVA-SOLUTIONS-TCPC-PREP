#include <bits/stdc++.h>
using namespace std;
int arr[200];
int n;

void solve(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int sum=0;
			for(int k=0;k<n;k++){

				if(j!=k){
					sum+=arr[k];
				}
			}
			double mean=(double)sum/(double)(n-1);
			if(arr[j]==mean){
				cout << "YES"<< endl;
				return;
			}

		}
	}
	cout <<"NO"<< endl;
	return;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
    int tc;
    scanf("%d",&tc);

    while(tc--){
    	scanf("%d",&n);
    	for(int i=0;i<n;i++){
    		cin >> arr[i];
    	}
    	solve();
    }




	
    return 0;
}
