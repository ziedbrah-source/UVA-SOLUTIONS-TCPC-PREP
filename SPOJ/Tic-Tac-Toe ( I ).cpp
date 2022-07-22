#include <bits/stdc++.h>
using namespace std;

int arr[3][3];

bool checkRows(int x){
	if(arr[0][0]==arr[0][1]&&arr[0][1]==arr[0][2]&&arr[0][0]==x){
		return true;
	}
	if(arr[1][0]==arr[1][1]&&arr[1][1]==arr[1][2]&&arr[1][1]==x){
		return true;
	}
	if(arr[2][0]==arr[2][1]&&arr[2][1]==arr[2][2]&&arr[2][1]==x){
		return true;
	}
	return false;
}

bool checkColumns(int x){
	if(arr[0][0]==arr[1][0]&&arr[1][0]==arr[2][0]&&arr[0][0]==x){
		return true;
	}
	if(arr[0][1]==arr[1][1]&&arr[1][1]==arr[2][1]&&arr[0][1]==x){
		return true;
	}
	if(arr[0][2]==arr[1][2]&&arr[1][2]==arr[2][2]&&arr[1][2]==x){
		return true;
	}
	return false;
}
bool checkDiag(int x){
		// diags
	if(arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2]&&arr[2][2]==x){
		return true;
	}
	if(arr[2][0]==arr[1][1]&&arr[1][1]==arr[0][2]&&arr[1][1]==x){
		return true;
	}
	return false;
}
void solve(){
	
	memset(arr,0,sizeof arr);
	int OCounter=0;
	int XCounter=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			char input;
			cin >> input;
			if(input=='O'){
				arr[i][j]=0;
				OCounter++;
			}
			else if(input=='X'){
				arr[i][j]=1;
				XCounter++;
			}else{
				arr[i][j]=-1;
			}
		}
	}
	bool possible=true;
	if(OCounter > XCounter){
		possible = false;
		
	}else if((XCounter-OCounter)>1){
		possible=false;
	}
	
	bool winnerX=(checkDiag(1)||checkColumns(1)||checkRows(1));
	if(winnerX){
		if(XCounter-OCounter!=1){
			possible=false;
		}
	}
	bool winnerO=(checkDiag(0)||checkColumns(0)||checkRows(0));
	if(winnerO){
		if(XCounter-OCounter!=0){
			possible=false;
		}
	}
	if(possible){
		cout <<"yes"<<endl;
	}else{
		cout <<"no"<<endl;
	}
}



int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int tc;
	cin >> tc;
	while(tc--){
		solve();
	}
    return 0;
}
