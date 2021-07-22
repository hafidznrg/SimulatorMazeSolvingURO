#ifndef PATH.H
#define PATH.H
#include <iostream>
using namespace std;

int a = 34;
int b = 16;
int i,j,k;

typedef struct petak{
	int i;                             
	int j;                            
	int direction;                          
}petak;

typedef struct Way{
	petak num[34*16];
	int block;
}Way;

bool path(int map[i][j],int x,int y,int x1,int y1) 
{
	int dir,find;
	Way way;
	way.block = -1; 
	way.block++;
	x = way.num[way.block].i; //baris
	y = way.num[way.block].j; //kolom
	way.data[way.block].direction = -1; //
	map[i][j]=-1;
	while(way.top>-1)
	{
		i = x;
		j = y;
		dir = way.num[way.block].direction;

		if(i == x1 && j == y1)  // pilihan x1 dan y1 ialah 
		// kalo line room 1 berarti (8,14),(8,15),(8,16),(8,17),(8,18),(8,19),(8,20)
		// kalo line room 2 berarti (12,6),(13,6),(14,6) tapi besok mau dibuat polymorph biar efisien
		{
			cout<<"Alur koordinate:\n";
			for(k=0;k<=way.block;k++)
			{
				cout<<way.num[k].i;
				cout<",";
				way.num[k].j;
				if((k+1)%17==0 || (k+1)%16==0) {
			    cout<<"\n";}
			}
			cout<<"\n";
			return true;
		};
		//setelah explore room 1 berarti way.num[k].i = xi
}
#endif
