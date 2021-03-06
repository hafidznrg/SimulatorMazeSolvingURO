#ifndef PATH_H
#define PATH_H

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

void PathStructBlock(){
	
	int i,j,x,y;
	structblock = -1; 
	structblock++;
	x = way.num[structblock].i; //baris
	y = way.num[structblock].j; //kolom
	switch (way.num[structblock].direction){
	case 1:
		way.num[structblock].direction = -1;
		break;
	case 2:
		way.num[structblock].direction = -2;
		break;
	case 3:
		way.num[structblock].direction = -3; 
		break;
	default:
		break;
	}
	way.num[structblock].direction = -1;
	way.num[structblock].direction = -2;
	way.num[structblock].direction = -3; 
}

bool path(int map[M][N],int x,int y,int x1,int y1) 
{
	int i,j,dir,locate;

	PathStructBlock();
	map[x][y]=-1;


	while(way.block>-1){
		i = way.num[structblock].i;
		j = way.num[structblock].j;
		dir = way.num[structblock].direction; //banyak movement

		if(i == x1 && j == y1){  //koordinat line door
			cout<<"\n";
			return true;
		}
		locate = 0;

		while(dir < 4  && locate == 0) // letak dinding
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
			if(map[i][j]==0){ //melalui jalur array matriks 0
				locate = 1;
			} 
		}

		if(locate == 1){
			dir = way.num[structblock].direction;
			structblock++;
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
void PathtoRoom2(){
    int i,j;
    int map[M][N]={                
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,1},
        {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,2,2,2,2,2,0,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1,0,0,0,0,0,1},
        {1,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	};
	
    path(map,1,14,1,2); // node to node
    path(map,1,2,5,2);
    path(map,5,2,9,2);
    path(map,9,2,11,2);
    path(map,11,2,14,2);
    path(map,14,2,14,10);
    path(map,14,10,14,10); // titik akhir room 2
	for(i=0;i<16;i++){
	 	for(j=0;j<34;j++)
	 	{
	 	    switch(map[i][j]){
                case 1:
                cout<<"|"; 
                break;
                case 2:
                    cout<<"-"; 
                    break;
                case 3:
                    cout<<"\\"; 
                    break;
                case 0:
                    cout<<" "; 
                    break;
                case -1:
                    cout<<"R"; 
                    break;
			}	
		} 
		cout<<"\n";
	}
}

void PathtoRoom1(){
    int i,j;
    int map[M][N]={                
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,1},
        {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,2,2,2,2,2,0,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1,0,0,0,0,0,1},
        {1,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	};
    path(map,14,10,14,2);
    path(map,14,2,11,2);
    path(map,11,2,9,2);
    path(map,9,2,9,10);
    path(map,9,10,9,16);
    path(map,9,16,5,16);
    path(map,5,16,5,16); // titik akhir koordinat room 1
	for(i=0;i<16;i++){
	 	for(j=0;j<34;j++)
	 	{
	 	    switch(map[i][j]){
                case 1:
                cout<<"|"; 
                break;
                case 2:
                    cout<<"-"; 
                    break;
                case 3:
                    cout<<"\\"; 
                    break;
                case 0:
                    cout<<" "; 
                    break;
                case -1:
                    cout<<"R"; 
                    break;
			}	
		} 
		cout<<"\n";
	}
}

void PathtoHome(){
    int i,j;
    int map[M][N]={                
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,1},
        {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,2,2,2,2,2,0,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1,0,0,0,0,0,1},
        {1,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	};
    path(map,5,16,9,16);
    path(map,9,16,9,10);
    path(map,9,10,9,2);
    path(map,9,2,5,2);
    path(map,5,2,1,2);
    path(map,1,2,1,14);
    path(map,1,14,1,14); // titik awal start
	for(i=0;i<16;i++){
	 	for(j=0;j<34;j++)
	 	{
	 	    switch(map[i][j]){
                case 1:
                cout<<"|"; 
                break;
                case 2:
                    cout<<"-"; 
                    break;
                case 3:
                    cout<<"\\"; 
                    break;
                case 0:
                    cout<<" "; 
                    break;
                case -1:
                    cout<<"R"; 
                    break;
			}	
		} 
		cout<<"\n";
	}
}

#endif
