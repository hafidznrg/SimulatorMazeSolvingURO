#ifndef PATH.H
#define PATH.H

#include <iostream>
using namespace std;

#define M 16
#define N 34


typedef struct{
	int i;                             
	int j;                            
	int direction;                          
}petak;

typedef struct{
	petak num[34*16]; //total petak
	int block;        //1 petak
}matrix;
	matrix way;

void PathForward(){
	int i,j,x,y;
	way.block = -1; 
	way.block++;
	x = way.num[way.block].i; //baris
	y = way.num[way.block].j; //kolom
	way.num[way.block].direction = -1; //
}
void PathBackward(){
	int i,j,x,y;
	way.block = -1; 
	way.block--;
	x = way.num[way.block].i; //baris
	y = way.num[way.block].j; //kolom
	way.num[way.block].direction = -1; //
}
bool path(int map[M][N], int x,int y,int x1,int y1) 
{
	int i,j,dir,locate;

	PathForward();
	map[x][y]=-1;
//	PathBackward();
//	map[x][y]=-1;

	while(way.block>-1)
	{
		i = way.num[way.block].i;
		j = way.num[way.block].j;
		dir = way.num[way.block].direction; //banyak movement

		if(i == x1 && j == y1)  // pilihan x1 dan y1 ialah 
		// kalo line room 1 berarti (8,14),(8,15),(8,16),(8,17),(8,18),(8,19),(8,20)
		// kalo line room 2 berarti (12,6),(13,6),(14,6) 
		{
			cout<<"\n";
			return true;
		}locate = 0;

		while(dir < 3 && locate == 0) // letak dinding
		{
			dir++;
			switch(dir)
			{
				case 0:
					i= way.num[way.block].i-1;
					j= way.num[way.block].j; 
					break;	
				case 1:
					i= way.num[way.block].i;
					j= way.num[way.block].j+1; 
					break;
				case 2:
					i= way.num[way.block].i+1;
					j= way.num[way.block].j; 
					break;
				case 3:
					i= way.num[way.block].i;
					j= way.num[way.block].j-1; 
					break;
			}
			if(map[M][N]==0){ //melalui jalur array matriks 0
				locate = 1;
			} 
		}

		//while(dir < 3 && locate == 0)
		//{
		//	dir--;
		//	switch(dir)
		//	{
// case 0:
		//			i= way.num[way.block].i-1;
		//			j= way.num[way.block].j; 
		//			break;	
		//		case 1:
		//			i= way.num[way.block].i;
		//			j= way.num[way.block].j+1; 
		//			break;
		//		case 2:
		//			i= way.num[way.block].i+1;
		//			j= way.num[way.block].j; 
		//			break;
		//		case 3:
		//			i= way.num[way.block].i;
		//			j= way.num[way.block].j-1; 
		//			break;
		//	}
		//	if(map[M][N]==0){
		//		locate = 1; //melalui jalur matriks 0
//} 
	//	}
		if(locate == 1)
		{
			dir = way.num[way.block].direction;

			way.block++;
			way.num[way.block].i = i;
			way.num[way.block].j = j;
			way.num[way.block].direction = -1;
			map[i][j]= -1;
		}
		else
		{
			map[way.num[way.block].i][way.num[way.block].j] = 0;
			way.block--;
		}
	 } 
	 return false;
}
#endif
