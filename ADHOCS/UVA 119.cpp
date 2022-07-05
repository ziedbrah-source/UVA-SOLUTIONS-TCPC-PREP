#include <bits/stdc++.h>
using namespace std;


int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	unordered_map<string, int> umap;
	int n;
	int number;
	int money;
	string input;
	int moneyForOne;
	queue<string> names;
	int T=1;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			cin >> input;
			names.push(input);
			umap[input]=0;
		}
		for(int i=0;i<n;i++){
			cin >> input >> money >> number;
			if(number!=0){
				moneyForOne=money/number;
				int rest=ceil(money%number);
				umap[input]+=rest;
				umap[input]-=money;
			}
			
			for(int i=0;i<number;i++){
				cin >> input;
				umap[input]+=moneyForOne;

			}
		}
		if(T++>1){
			cout << endl;
		}
		while (!names.empty()) {
       		cout << names.front()<<" "<<umap[names.front()]<<endl;
        names.pop();
    }
    	umap.clear();
	}



    
    return 0;
}
