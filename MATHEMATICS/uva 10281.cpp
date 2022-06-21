#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    char str[1000];
    int hh,mm,ss;
    double ans,ltime=0,rtime,v=0;
    while(gets(str)){
		sscanf(str, "%d:%d:%d", &hh, &mm, &ss);
		rtime=hh+mm/60.0+ss/3600.0;
		if(str[8]=='\0'){
			ans+=(rtime-ltime)*v;
			printf("%s %.2lf km\n", str, ans);
		}else{
			ans += (rtime-ltime)*v;
            sscanf(str+8, "%lf", &v);
		}
		ltime=rtime;
    }

    
    return 0;
}
