#include <bits/stdc++.h>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
    int tc;
    scanf("%d",&tc);
    int player1;
    int MaxPlayer1;
    int player2;
    int MaxPlayer2;
    int input;
    while(tc--){
    	MaxPlayer1=-1;
    	MaxPlayer2=-1;
    	cin >> player1;
    	for(int i=0;i<player1;i++){
    		cin>> input;
    		MaxPlayer1=max(MaxPlayer1,input);
    	}
    	cin >> player2;
    	for(int i=0;i<player2;i++){
    		cin>> input;
    		MaxPlayer2=max(MaxPlayer2,input);
    	}

    	if(MaxPlayer2==MaxPlayer1){
    		cout <<"Alice"<<endl;
    		cout <<"Bob"<<endl;
    	}
    	if(MaxPlayer1>MaxPlayer2){
    		cout <<"Alice"<<endl;
    		cout <<"Alice"<<endl;
    	}
    	if(MaxPlayer1<MaxPlayer2){
    		cout <<"Bob"<<endl;
    		cout <<"Bob"<<endl;
    	}
    }




	
    return 0;
}
