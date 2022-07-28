#include <bits/stdc++.h>
using namespace std;




void solve(){
	string hours;
	int x;
	cin >> hours >> x;
	queue<int> hoursQ;
	queue<int> minutesQ;
	int hoursDigits=((hours[0]-'0')*10+(hours[1]-'0'));
	int minutesDigits=((hours[3]-'0')*10+(hours[4]-'0'));
	hoursQ.push(hoursDigits);
	minutesQ.push(minutesDigits);
	int initialHours=hoursDigits;
	int initialMinutes=minutesDigits;
	int xhours=x/60;
	int xminutes=x%60;

	//cout << hoursDigits << minutesDigits << endl;
	//cout << xhours << xminutes << endl;

	while(true){
		int minu=(minutesDigits+xminutes)%60;
		hoursDigits+=(minutesDigits+xminutes)/60;
		minutesDigits=minu;
		hoursDigits+=xhours;
		hoursDigits=hoursDigits%24;
		if(hoursDigits==initialHours && minutesDigits==initialMinutes){
			break;
		}else{
			hoursQ.push(hoursDigits);
			minutesQ.push(minutesDigits);
		}
	}
	int counter=0;
	while(!hoursQ.empty()){
		int h=hoursQ.front();hoursQ.pop();
		int x=minutesQ.front();minutesQ.pop();
		if(h%10==x/10 && h/10==x%10){
			counter++;
		}
		//cout << h << x << endl;
	}

	cout << counter << endl;
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
    //while(scanf("%d %d",&m,&n)!=EOF)
		solve();
	
	}
    return 0;
}
