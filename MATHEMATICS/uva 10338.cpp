#include <bits/stdc++.h>
using namespace std;

long long fact[21];
void factorial(){
	fact[0]=1;
	for(int i=1;i<21;i++){
		fact[i]=fact[i-1]*i;
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	factorial();
    int tc;
    char str[20];
    int Case=0;
   scanf("%d",&tc);
    while(tc--){
    	 scanf("%s", str);
    	 int letter[26] = {};
    	 // counting letters occurences.
    	 for(int i = 0; str[i]; i++)
            letter[str[i]-'A']++;
        long long res=fact[strlen(str)];
        for(int i=0;i<26;i++){
        	res/=fact[letter[i]];
        }

    	 printf("Data set %d: %lld\n", ++Case, res);
    }


    
    return 0;
}
