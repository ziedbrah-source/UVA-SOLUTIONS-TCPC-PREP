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
    while(tc--){
    	int x1,y1,x2,y2,x3,y3;
    	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    	// make x1,y1 represents (0,0)
    	x2-=x1;
    	y2-=y1;
    	x3-=x1;
    	y3-=y1;
    	long long crossProduct=(long long)x2*y3-(long long)x3*y2;
    	if(crossProduct>0){
    		cout << "LEFT" << "\n";
    	}else if(crossProduct<0){
    		cout <<"RIGHT" << "\n";
    	}else{
    		cout <<"TOUCH"<<"\n";
    	}

    	}
     return 0;
}
