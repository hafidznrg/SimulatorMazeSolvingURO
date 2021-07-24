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
	int structblock = way.block;
void PathForward(){
	
	int i,j,x,y;
	structblock = -1; 
	structblock++;
	x = way.num[structblock].i; //baris
	y = way.num[structblock].j; //kolom
	way.num[structblock].direction = -1; //
}
bool path(int map[M][N],int x,int y,int x1,int y1) 
{
	int i,j,dir,locate;

	PathForward();
	map[x][y]=-1;


	while(way.block>-1){
		i = way.num[structblock].i;
		j = way.num[structblock].j;
		dir = way.num[structblock].direction; //banyak movement

		if(i == x1 && j == y1){  //koordinat line door
			cout<<"\n";
			return true;
		}locate = 0;

		while(dir < 3 && locate == 0) // letak dinding
		{
			dir++;
			switch(dir)
			{
			case 0:
				i= way.num[structblock].i-1;
				j= way.num[structblock].j; 
				break;	
			case 1:
				i= way.num[structblock].i;
				j= way.num[structblock].j+1; 
				break;
			case 2:
				i= way.num[structblock].i+1;
				j= way.num[structblock].j; 
				break;
			case 3:
				i= way.num[structblock].i;
				j= way.num[structblock].j-1; 
				break;
			}
			if(map[M][N]==0){ //melalui jalur array matriks 0
				locate = 1;
			} 
		}

		if(locate == 1){
			dir = way.num[structblock].direction;
			way.block++;
			way.num[structblock].i = i;
			way.num[structblock].j = j;
			way.num[structblock].direction = -1;
			map[i][j]= -1;
		}
		else{
			map[way.num[structblock].i][way.num[structblock].j] = 0; 
			way.block--;
		}
	} 
	return false;
}
#endif
