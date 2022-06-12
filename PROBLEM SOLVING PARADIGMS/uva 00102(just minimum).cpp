#include<bits/stdc++.h>
using namespace std;
int main ()
{
		#ifndef ONLINE_JUDGE
		freopen("input.in","r",stdin);
		freopen("output.out","w",stdout);
	#endif
	int arr[] = { 1, 2, 3 };
	int bottles[10];
	int minimum=1e7;
	int val=0;
	int choice;
	bottles[0]=0;
	int first;
	while(scanf("%d",&first)!=EOF){
		bottles[1]=first;
		for(int i=2;i<10;i++){
			scanf("%d",&first);
			bottles[i]=first;
					}
		do{
			val=0;
		for(int i=0;i<3;i++){
			choice=arr[i];
			while(choice<10){
				if((i==0 )&& (choice>=1&&choice<=3)){
				
						choice+=3;
						continue;

				}
				if((i==1)&&(choice>=4&&choice<=6)){
						choice+=3;
						continue;
				}
				if( (i==2)&&(choice>=7&&choice<=9)){
						choice+=3;
						continue;
				}
				val+=bottles[choice];
				choice+=3;
			} 
		}
		minimum=min(minimum,val);
	}while (next_permutation(arr, arr + 3));
	cout << minimum;
	minimum=1e7;
	}
    return 0;
}