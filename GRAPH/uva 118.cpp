#include <bits/stdc++.h>
using namespace std;
int themap[50][50];
int n,m;
char cmd[1000];
bool notValid(int x,int y){
	if(x<0||x>n||y<0||y>m){
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
    scanf("%d %d",&n,&m);
    int posX,posY;
    char orientation;
    bool flag;
    memset(themap,-1,sizeof themap);
    while(scanf("%d %d %c",&posX,&posY,&orientation)!=EOF){
    	flag=0;
    	scanf("%s", cmd);
    	for(int i = 0; cmd[i]; i++) {
    		if(cmd[i]=='R'){
    			switch(orientation){
    				case 'N':orientation='E';break;
    				case 'E':orientation='S';break;
    				case 'S':orientation='W';break;
    				case 'W':orientation='N';break;
    			}
    		}
    		if(cmd[i]=='L'){
    			switch(orientation){
    				case 'N':orientation='W';break;
    				case 'E':orientation='N';break;
    				case 'S':orientation='E';break;
    				case 'W':orientation='S';break;
    			}
    		}
    		if(cmd[i]=='F'){
    			switch(orientation){
    				case 'N':posY++;break;
    				case 'E':posX++;break;
    				case 'S':posY--;break;
    				case 'W':posX--;break;
    			}
    		}
    		if(notValid(posX,posY)){
    			switch(orientation){
    				case 'N':posY--;break;
    				case 'E':posX--;break;
    				case 'S':posY++;break;
    				case 'W':posX++;break;
    			}
    			if(themap[posX][posY]==1){
    				continue;
    			}
    			themap[posX][posY]=1;
    			flag=1;
    			break;
    		}
    	}
    	if(flag){
    		cout << posX << " " << posY << " "<< orientation << " LOST"<<endl;
    	}else{
    		cout << posX << " " << posY << " "<< orientation << endl;
    	}
    }
    
    return 0;
}
