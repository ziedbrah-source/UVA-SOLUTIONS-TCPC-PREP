#include<bits/stdc++.h>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int tc;
	scanf("%d",&tc);
	int n;
	int n1;
	int n2;
	int n3;
	while(tc--){
		scanf("%d",&n);
		n1=0;
		n2=0;
		n3=0;
		int choice=1;
		while(n--){
			if(choice==1){
				n1++;
				choice=2;
			}else if(choice==2){
				n2++;
				choice=3;
			}else if(choice==3){
				n3++;
				choice=1;
			}
		}
		// pire cas el kol 9ad b3adhhom
		if(n1==n2 && n2==n3){
			n1+=1;
			n3-=1;
		}else if(n2==n3){
			n2++;
			n3--;
			if(n2==n1){
				n2--;
				n1++;
			}
		}else if(n1==n2){
			n1++;
			n2--;
			if(n2==n3){
				n2++;
				n3--;
			}
		}
		printf("%d %d %d\n",n2,n1,n3);
	}
    return 0;
}
