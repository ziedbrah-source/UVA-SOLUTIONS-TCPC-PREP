#include <bits/stdc++.h>
using namespace std;

int digits(long long curr){
	int counter=0;
	while(curr){
		counter++;
		curr/=10;
	}
	return counter;
}
bool solve(){
	int n;
	long long x;
	cin >> n>> x;
	queue<long long> q;
	map<long long ,long long> umap;

	umap[x]=0;

	q.push(x);

	while(!q.empty()){
		long long curr=q.front();q.pop();
		if(digits(curr)==n){
			cout <<umap[curr]<< endl;
			return true;
		}
		long long temp=curr;
		while(temp){
			long long dig=temp%10;
			temp/=10;
			if(umap.find(dig*curr)==umap.end()){
				umap[dig*curr]=umap[curr]+1;
				q.push(dig*curr);
			}

		}
	}
	return false;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

   	if(!solve()){
    		cout << -1 << endl;
    	}
    
    return 0;
}
