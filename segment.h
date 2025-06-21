#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"code.h"


#define BOUND 16384  //64KB  virtual  memory = 4(segment)*16 (segment size (16384))
#define OFFSET_BITS  14
#define SEGMENTS_BITS 2
   typedef struct segment
    {
      char  *segment_no ;
      char  *segment_name;
      char  *offset;
      int bound ;
      int base; 
    }segment;
 
//to generate segment number & name
void  binary(segment *seg, int num ){
    int rem ,i=0; 
    seg->segment_no = (char*)malloc(SEGMENTS_BITS+1);
    if(seg->segment_no ==NULL)
       {
          printf("Allocation failed \n");
          exit(1);
        }
    
    for (int i = SEGMENTS_BITS-1; i >= 0; i--) {
       seg->segment_no[SEGMENTS_BITS -1- i] = (num & (1 << i)) ? '1' : '0';
   }
    seg->segment_no[SEGMENTS_BITS] = '\0';
    seg->segment_name = (char*)malloc(7);
   if(!strcmp(seg->segment_no ,"00")) strcpy(seg->segment_name , "CODE ");
   else if(!strcmp(seg->segment_no ,"01"))strcpy(seg->segment_name , "DATA ");
   else if(!strcmp(seg->segment_no ,"10"))strcpy(seg->segment_name , "HEAP ");
   else if(!strcmp(seg->segment_no ,"11"))strcpy(seg->segment_name , "STACK");
   
}
  
//copy offset 
 void copy(segment *seg , char *address){
    seg->offset = (char*)malloc(OFFSET_BITS+1);
    if(seg->offset ==NULL)
       {
          printf("Allocation failed \n");
          exit (1);
        }
        
    for(int i =0 ; i<OFFSET_BITS;i++){
        seg->offset[i] = address[i+SEGMENTS_BITS];
    }
    seg->offset[OFFSET_BITS] ='\0';
} 


//prints segment data 
 void print(segment *seg){
    printf("------------------------------------------------------------\n");
    printf("Segment info         \n");
    printf("------------------------------------------------------------\n");
    printf("Segment Name        : %s \n",seg->segment_name);
    printf("Segment Number      : %s \n",seg->segment_no);
    printf("Offset              : %s             [%d]\n",seg->offset,binary_to_decimal(seg->offset));
    printf("Value of Base       : %d \n",seg->base);
    printf("Value of Bound      : %d \n",seg->bound);
    printf("============================================================\n");

 }

 // copy offset, sets Base & bound Values of segements 
void Bound(segment *seg , segment *prevseg)
   {     
         seg->bound = BOUND;
         seg->base=  prevseg->base +BOUND;
         //print(seg);
    }
//segment search & offset fault check
void segment_search(segment *seg,char *address){
    int offset_val = binary_to_decimal(seg->offset);
    if(offset_val >= seg->bound){
        printf("SEGMENTATION FAULT : Offset exceeds bound limit for segment : %s\n",seg->segment_no);
        exit(1);
    }
        else
        if(!strncmp(seg->segment_no,address,2)) 
          {
            print(seg); 
            int physical_address = seg->base + offset_val;
            printf("Physical Address    : %s       [%d]\n",binaryconv(physical_address,20), physical_address);
         }
}

    