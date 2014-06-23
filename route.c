#include <stdio.h>

int m[9][9]={
	{2,2,2,2,2,2,2,2,2},
	{2,0,0,0,2,2,2,0,2},
	{2,0,2,0,2,2,2,0,2},
	{2,0,2,0,2,2,2,0,2},
	{2,0,2,0,2,0,0,0,2},
	{2,0,2,0,2,0,2,0,2},
	{2,0,2,0,0,0,0,0,2},
	{2,0,0,0,2,2,2,0,2},
	{2,2,2,2,2,2,2,2,2},
};

int startx,starty,goalx,goaly,success,visitedx[100],visitedy[100],c;//,path;

int visit(int x,int y){
	int i;
	static int path=0;

	m[x][y] = 1;
	visitedx[c] = x;
	visitedy[c] = y;
	c++;

	if(x==goalx && y==goaly){
		printf("case %d:",++path);
		for(i=0;i<c;i++){
			printf("(%d,%d) ",visitedx[i],visitedy[i]);
		}
		puts("");
		success = 1;
	}

	if(m[x][y+1]==0)visit(x,y+1);
	if(m[x+1][y]==0)visit(x+1,y);
	if(m[x][y-1]==0)visit(x,y-1);
	if(m[x-1][y]==0)visit(x-1,y);

	c--;

	m[x][y] = 0;

	return success;
}

int main(){
	success = c = 0;//path = 0;
	startx = starty = 1;
	goalx = goaly = 7;

//	puts("迷路の探索");
	puts("find path");
	if(visit(startx,starty)==0){
		puts("出口は見つかりませんでいた");
	}
	return 0;
}

