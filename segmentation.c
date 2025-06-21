#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"segment.h"


int main(){
    
  int retry;
  printf("ENTER LOOP RUNS: \t");
  scanf("%d",&retry);
  if(retry ==0 )return 0;
  else{ retry--;}
  
  OS();
    RETRY:
    unsigned int  address_decimal = random_number();
    char *address;
    if(address_decimal < 65537)
    {
        address = binaryconv(address_decimal,16);
        printf("\n\n\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("VIRTUAL ADDRESS GENERATED : %s     [%d]\n",address,address_decimal);
        printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n");
       }
       else {
        printf("FAULT_INVALID_ADDRESS_GENERATION !\n");
        exit(0);
       }
    
     //segment creation  
     segment *segment[4];
     for(int i =0;i<4;i++)
     { 
       segment[i] = (malloc(sizeof( struct segment )));
       if(segment[i] ==NULL)
       {
          printf("Allocation failed \n");
          return 1;
        }
       binary(segment[i],i);
       copy(segment[i], address);
      
       if(i==0)
        {
          segment[0]->bound = BOUND ;
          segment[0]->base  = OS_BOUND ;
        }
         else {
           Bound(segment[i] , segment[i-1]) ;}
          
      }
     //Searching segment 
      for(int i=0;i<4;i++)
        segment_search(segment[i],address);  
     if(retry>0){
      --retry;
      goto RETRY;
     }
}