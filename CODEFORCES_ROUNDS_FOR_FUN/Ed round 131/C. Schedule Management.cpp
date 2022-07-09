#include <bits/stdc++.h>
using namespace std;
int workers[200000];
long long tasks;
int workersSize;

// this checker gives the maximum that they can do in x hours.
// and now we make a binary search for the answer.
// [FFFFFFFFFFFFTTTTTTTTT]
// we want to get the first T; -> minimum needed time to make the tasks.

// the observation is : if tasks can get done within d hours , they can be done within d+1 hours.
// -> we can think of smart brute force . with binary search 
// also if we get another observation : if tasks can get done with in d , then it can be done within d-1 -> [TTTTTTTTTFFFFF]-> and we want to get the last True-> the maximum D

bool checker(long long hours){
	long long tasksInHours=0;
	for(int i=1;i<=workersSize;i++){
		if(workers[i]>=hours){
			tasksInHours+=hours;
		}else{
			tasksInHours+=(workers[i]+(hours-workers[i])/2);
		}
	}
	if(tasksInHours>=tasks){
		return true;
	}
	return false;
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
    int tc;
    scanf("%d",&tc);
    while(tc--){
    	memset(workers,0,sizeof workers);    	
    	cin >> workersSize >> tasks;
    	int tasksWorkerEffIn;
    	for(int i=0;i<tasks;i++){
    		cin >> tasksWorkerEffIn;
    		workers[tasksWorkerEffIn]++;
    	}
    	//binary search;
    	//[FFFFFFFFFFFFTTTTTTTTT]
    	// the invariant is that l is always false; r is always true.
    	long long l=0;
    	long long r=1e10;
    	while(r>l+1){
    		long long mid=(l+r)/2;
    		if(checker(mid)){
    			r=mid;
    		}else{
    			l=mid;
    		}
    	}
    	cout << r<< endl;
    }




	
    return 0;
}
