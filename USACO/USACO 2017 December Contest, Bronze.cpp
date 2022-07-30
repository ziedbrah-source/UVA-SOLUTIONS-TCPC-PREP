#include <bits/stdc++.h>
using namespace std;


struct Rect{
	int x1,x2,y1,y2;
	int area(){
		return (x2-x1)*(y2-y1);
	}
};
int intersect(Rect a,Rect b){
	int x=max(0,min(a.x2,b.x2)-max(a.x1,b.x1));
	int y=max(0,min(a.y2,b.y2)-max(a.y1,b.y1));
	return x*y;

}
void solve(){
	Rect a, b, t;  // billboards a, b, and the truck

	cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
	cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
	cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;


	cout << a.area()+b.area()-intersect(a,t)-intersect(b,t)<<endl;



}
int main()
{
	/*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif*/

	// Use standard input to read from "paint.in"
	freopen("billboard.in", "r", stdin);
	// Use standard output to write to "paint.out"
	freopen("billboard.out", "w", stdout);
	//int tc;
	//cin >> tc;
	//while(tc--){
    //while(scanf("%d %d",&m,&n)!=EOF)
		solve();
	
	//}
    return 0;
}
