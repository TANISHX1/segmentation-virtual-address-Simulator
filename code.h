#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define OS_BOUND 102400 // 100 KB address space of OS

// for (16-bit) binary conversion
char * binaryconv( int num,int BITS) {
    char *binary = malloc(BITS+1);  // 16 bits + null terminator
    if(binary ==NULL)
    {
        printf("Allocation failed \n");
        exit (1);
    }
    else
    {for (int i = 0; i <BITS; i++) {          
        binary[BITS-1-i] = (num & (1 << i)) ? '1' : '0';
    }
    binary[BITS] = '\0';  // Null-terminate
    return binary;}
}

int binary_to_decimal(char *seg){
    return strtol(seg,NULL,2);
}

// costom Details
void OS(){
    srand(time(NULL)); 
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("                Operating system  space \n");
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("Base                 : %d \n",0);
    printf("Bound                : %s      [%d] \n",binaryconv(OS_BOUND,20), OS_BOUND);
}

// to generate Random address
int random_number (){
    int randomarray[2];
    randomarray[0] = rand()%32768;
    randomarray[1] = rand()%70000;
    int num = rand()%2;
    return randomarray[num]; 
}
