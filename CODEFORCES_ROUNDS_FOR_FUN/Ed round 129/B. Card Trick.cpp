#include <bits/stdc++.h>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
    int tc;

    int n;
    int numberOfShuffles;
    int input;
    scanf("%d",&tc);
    while(tc--){
    	vector<int> vec;
    	scanf("%d",&n);
    	for(int i=0;i<n;i++){
    		cin >> input;
    		vec.push_back(input);
    	}
    	cin >> numberOfShuffles;
    	long long sum=0;
    	for(int i=0;i<numberOfShuffles;i++ ){
    		cin >> input;
    		sum+=input;
    	}

    	numberOfShuffles=sum%n; // because it s a circular operation
    	rotate(vec.begin(), vec.begin()+numberOfShuffles, vec.end());

    	cout << vec[0]<<endl;
    }




	
    return 0;
}
