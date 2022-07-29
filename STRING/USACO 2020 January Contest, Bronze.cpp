#include <bits/stdc++.h>
using namespace std;




void solve(){
	int n,k;
	string input;
	cin >> n >>k;
	std::getline(std::cin, input, '$');
	vector<string> wordVec;
	string toBeConstructed="";
	for(int i=0;i<input.length();i++){
		if(input[i]==' '||input[i]=='\n'){
			if(toBeConstructed.length()>0){
				wordVec.push_back(toBeConstructed);
			}
			toBeConstructed="";
		}else{
			toBeConstructed+=input[i];
		}
	}
	if(toBeConstructed.length()>0){
		wordVec.push_back(toBeConstructed);
	}
	int counter=0;
	int firstWord=true;
	for(int i=0;i<wordVec.size();i++){
		counter+=wordVec[i].length();
		if(counter>k){
			firstWord=false;
			cout <<"\n"<<wordVec[i];
			counter=wordVec[i].length();
		}else{
			if(firstWord){
				cout<<wordVec[i];
				firstWord=false;
			}else{
				cout << " "<<wordVec[i];
			}
		}
	}
}
int main()
{
	/*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif*/

	// Use standard input to read from "paint.in"
	freopen("word.in", "r", stdin);
	// Use standard output to write to "paint.out"
	freopen("word.out", "w", stdout);
	//int tc;
	//cin >> tc;
	//while(tc--){
    //while(scanf("%d %d",&m,&n)!=EOF)
		solve();
	
	//}
    return 0;
}
