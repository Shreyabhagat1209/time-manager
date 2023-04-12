/* This file shall invoke the getTime() function and print the output */

#include</home/ee212784/Downloads/time_manager/lib/include/time_manager.h>
#include</home/ee212784/Downloads/time_manager/lib/src/time_manager_lib.c>
#include<stdio.h>

int main()
{
     printf("time in epoch format: %ld\n",getTime());
     return 0;
}
