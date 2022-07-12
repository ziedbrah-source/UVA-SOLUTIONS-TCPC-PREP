#include <bits/stdc++.h>
using namespace std;


// prob : https://codeforces.com/contest/1604/problem/B
// editorial (it's awesome) : https://codeforces.com/blog/entry/96460
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
    int tc;
    int n;
    scanf("%d",&tc);
    while(tc--){
    	scanf("%d",&n);
    	int input;
    	int laterinput;
    	bool test=false;
    	scanf("%d",&input);
    	for(int i=1;i<n;i++){
    		scanf("%d",&laterinput);
    		if(laterinput<=input){
    			test=true;
    		}
    		input=laterinput;
    	}

    	if((n%2==0)||test){
    		cout <<"YES"<<endl;
    	}else{
    		cout <<"NO"<<endl;
    	}
    }
     return 0;
}
