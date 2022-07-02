#include <bits/stdc++.h>
using namespace std;

int killed[1024][1024];
int d;
int n;

bool check(int x,int y){
	if((x>=0)&&(x<1024)&&(y>=0)&&(y<1024)){
		return true;
	}
	return false;
}
void addToKilled(int x,int y,int quantity){
	for(int i=x-d;i<=x+d;i++){
		for(int j=y-d;j<=y+d;j++){
			if(check(i,j)){
				killed[i][j]+=quantity;
			}
		}
	}
}

int getMax(){
	int maxi=0;
	for(int i=0;i<1024;i++){
		for(int j=0;j<1024;j++){
			maxi=max(maxi,killed[i][j]);
		}
	}
	return maxi;
}

//O(n*d^2)
// better than the brute force with (1024**2 * d**2)
// preprocess stuff when inputting 
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int tc;
    int x,y,quantity;
    int n;
   scanf("%d",&tc);
    while(tc--){
    	memset(killed,0,sizeof killed);
    	scanf("%d",&d);
    	scanf("%d",&n);
    	for(int i=0;i<n;i++){
    		scanf("%d %d %d",&x,&y,&quantity);
    		addToKilled(x,y,quantity);
    	}
    	int maxi=0;
    	int maxX=0;
    	int maxY=0;
		for(int i=0;i<1024;i++){
			for(int j=0;j<1024;j++){
				if(maxi<killed[i][j]){
					maxi=killed[i][j];
					maxX=i;
					maxY=j;
				}
			}
		}
    	cout << maxX<<" "<<maxY<<" "<< maxi<< endl;

    }


    
    return 0;
}
