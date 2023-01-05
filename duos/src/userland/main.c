#include <ustdio.h>
#include <kunistd.h> 
#include <usart.h>
void main()
{
    //starting the testing code here 

    kprintf("In user main\r\n");

    
    //Dummy test
    char x[] = "aaa";
    //firstTest(x);

    //TODO UPRINTF

    char *str = "String to be printed";
    int var1 = 42;
    int var2 = 15;
    char c = 'X';
    uprintf("decimal %d, hex %x, string: %s, char %c \r\n",var1,var2,str,c);
    //TODO USCANF

    kprintf("Enter a decimal, hex, string and char\r\n");
    uscanf("%d %x %s %c",&var1,&var2,&str,&c);
    uprintf("decimal %d, hex %x, string: %s, char %c \r\n",var1,var2,str,c);
    //TODO reboot
    //TODO gettime

    //testing printf of integers.
    // int x = 1;
    // uprintf("%d\n",x);


    kprintf("out of main\r\n");
    while(1);
}