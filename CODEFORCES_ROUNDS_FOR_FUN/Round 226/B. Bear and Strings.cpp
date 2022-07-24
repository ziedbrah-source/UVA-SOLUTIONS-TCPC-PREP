#include <bits/stdc++.h>
using namespace std;

//brute force
/*void solve(){
	string input;
	cin >> input;
	int counter=0;
	for(int i=0;i<input.length();i++){
		for(int j=i;j<input.length();j++){
			for(int k=i;k<=j;k++){
				if(k>j || (k+1)>j || (k+2)>j || (k+3)>j){
					continue;
				}else{
					if(input[k]=='b'&&input[k+1]=='e'&&input[k+2]=='a'&&input[k+3]=='r'){
						counter++;
						//break;

					}
				}
			}
			
		}
	}
cout << counter << endl;
// this is TLE BAZ
}*/

void solve(){
	string input;
	cin >> input;
	int counter=0;
	int firstLetterFoundAt=0;
	if(input.length()<4){
		cout << counter << endl;
		return;
	}
	for(int i=0;i<input.length()-3;i++){
		if(input[i]=='b'&&input[i+1]=='e'&&input[i+2]=='a'&&input[i+3]=='r'){
			
			counter++;
			// those starting from firstLetterfoundAt to the end;
			counter+=(input.length()-i-4);
			// starting from the left at firstLetterFoundAt+1
			counter+=i+1-(firstLetterFoundAt+1);
			// starting from firstLetterfOUNdAt+1 till length
			counter+=(i+1-(firstLetterFoundAt+1))*(input.length()-i-4);
			firstLetterFoundAt=i+1;
		}
	}
	cout << counter << endl;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	//int tc;
	//cin >> tc;
	//while(tc--){
    //while(scanf("%d %d",&m,&n)!=EOF)
		solve();
	//}
    return 0;
}
