#include <ustdio.h>
#include <kunistd.h> 
#include <usart.h>
void main()
{
    //starting the testing code here 

    kprintf("In user main\n");

    
    //Dummy test
    char x[] = "aaa";
    firstTest(x);
    
    //TODO UPRINTF
    //TODO USCANF
    //TODO reboot
    //TODO gettime

    //testing printf of integers.
    // int x = 1;
    // uprintf("%d\n",x);


    kprintf("out of main\n");
    while(1);
}