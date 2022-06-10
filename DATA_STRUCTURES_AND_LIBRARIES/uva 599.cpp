#include<bits/stdc++.h>
using namespace std;
int main ()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int tests;
	scanf("%d",&tests);
	char vertice1;
	char vertice2;
	bitset<27> bs; //A index 1 
	int numberOfVertices;
	int numberOfEdges;
	int numberOfnonAcrons;
	char lineOfVertices[60]; //26*2-2 but for overflow purposes let's make it 60 
	int index1;
	int index2;
	// how we will solve it.
	// all components are either trees or single nodes, we know that for a tree that vertices=edges+1;
	// so to compute how many components we can just compute nombreOfComponents=vertcies-edges (points and trees)
	// after that we check our bitset to see how many vertices are not edged . so they are single points
	string buffer;
	while(tests--){
		numberOfEdges=0;
		numberOfVertices=0;
		numberOfnonAcrons=0;
		//scanf(" (%c,%c)",&vertice1,&vertice2);
		//printf("%c  %c\n",vertice1,vertice2);
		while(scanf(" (%c,%c)",&vertice1,&vertice2)){
			if(vertice1=='*'){
				break;
			}
			//'a' is 0x41 and 'A' is 0x61. 0x20 = 32. And 26 < 32
			index1=(int)vertice1 % 32;
			index2= (int)vertice2 % 32;
			// we are trying to say that they are seen with edges.
			bs[index1]=1;
			bs[index2]=1;
			numberOfEdges++;
		};
		getline(cin,buffer);//just to ignore the "*****"
		scanf(" %s",lineOfVertices);
		int lengthOfLineOfVertices=strlen(lineOfVertices);
		//n-2 -> if n=a,b,c -> 5-2 =3 
		if(lengthOfLineOfVertices<=3){
			if(lengthOfLineOfVertices==1){
				numberOfVertices=1;
			}else{
				numberOfVertices=2;
			}
		}else{
			// n+n-1=2n-1 -> (lengthOfLineOfVertices+1)/2 because lengthOfLineOfVertices will be pair pair
			numberOfVertices=(lengthOfLineOfVertices+1)/2;

		}
		for(int i=1;i<28;i++){
			if(bs[i]){
				numberOfnonAcrons++;
			}
		}
		//int numberOfComponents=numberOfVertices-numberOfEdges;
		int numberOfacorns=numberOfVertices-numberOfnonAcrons;
		int numberOfTrees=numberOfVertices-numberOfEdges-numberOfacorns;
		printf("There are %d tree(s) and %d acorn(s).\n",numberOfTrees,numberOfacorns);
		bs.reset(); // reset the bs to 0 for all 
	    strcpy(lineOfVertices, "");//erase last content.

	}
    return 0;
}


