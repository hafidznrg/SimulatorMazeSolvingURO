#include "path.hpp"
int i,j;

int main(){
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
    path(map,1,14,1,2);
    path(map,1,2,5,2);
    path(map,5,2,9,2);
    path(map,9,2,11,2);
    path(map,11,2,14,2);
    path(map,14,2,14,10);
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
         //sleep(1);
	}
     //sleep(1)
     // @parameter node + output
     // @parameter exploreroom
     cout<<"Explore Room 2 Done!"<<endl;
    path(map,14,10,14,2);
    path(map,14,2,11,2);
    path(map,11,2,9,2);
    path(map,9,2,9,10);
    path(map,9,10,9,16);
    path(map,9,16,5,16);
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
         //sleep(1);
	}
    //sleep(1)
     // @parameter node + output
     // @parameter exploreroom
     cout<<"Explore Room 1 Done!"<<endl;
    path(map,5,16,9,16);
    path(map,9,16,9,10);
    path(map,9,10,9,2);
    path(map,9,2,5,2);
    path(map,5,2,1,2);
    path(map,1,2,1,2);
    
    cout<<"ROBOT SURVIVE!"<<endl;

    for(i=0;i<16;i++) //Convert array matrix map into constschar
	{
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
        //sleep(1);
	}
return 0;
} 
