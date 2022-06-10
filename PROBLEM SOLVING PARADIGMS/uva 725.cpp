#include<bits/stdc++.h>
using namespace std;
int main ()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n;
	int solutionExists=false;
	int counter=0;
	int second;
	scanf("%d %d",&n,&second);
	while(true){
		/*if(counter>1){
			printf("\n");
		}
		counter++;*/

		for(int fghij=1234;fghij<=(98765/n);fghij++){
			// (abcde/fghij)/n=1  so max digits is 5 because we divided by n and multiplied by n -> the same , 
			// we just did it to shorten the search area.
			int abcde=fghij*n; 
			int tmp,used=(fghij<10000);
			tmp=fghij;
			while(tmp){
				//bitmask technique to make "used =(1111111111)(base2)" in the end. if yes -> it's a solution
				used|=(1<< (tmp%10)); tmp/=10;
			}
			tmp=abcde;
			while(tmp){
				//bitmask technique to make "used =(1111111111)(base2)" in the end. if yes -> it's a solution
				used|=(1<< (tmp%10)); tmp/=10;
			}

			if(used==((1<<10)-1)){
				solutionExists=true;
				printf("%d / ",abcde);
				if(fghij<10000){
					printf("0");
				}
				printf("%d = %d\n",fghij,n);
			}
		}
		if(!solutionExists){
			printf("There are no solutions for %d.\n",n);
		}
		solutionExists=false;
		if(second==0){
			break;
		}else{
			printf("\n");
			n=second;
		}
		scanf("%d",&second);

		}


	
	
	

	
    return 0;
}

