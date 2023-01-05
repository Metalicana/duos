/*
 * Copyright (c) 2022 
 * Computer Science and Engineering, University of Dhaka
 * Credit: CSE Batch 25 (starter) and Prof. Mosaddek Tushar
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE UNIVERSITY AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE UNIVERSITY OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
 
#include <sys_init.h>
#include <cm4.h>
#include <kmain.h>
#include <kstdio.h>
#include <kstring.h>
#include <stdint.h>
#include <usart.h>
#include<ustdio.h>
#include <./../../userland/main.c>
//#include "../include/float.h"

void kmain(void)
{
	
	__sys_init();

	unsigned int empty[256];
    for(int i = 0; i < 256; i++) empty[i] = 0;

    // kprintf("Inside Read : %s\n", ch);
    
    task_init_env_2(empty+256);

    __asm volatile (
        ".global task_init_env_2\n"
        "task_init_env_2:\n"
	        "msr psp, r0\n"
	        "mov r0, #3\n"
	        "msr control, r0\n"
	        "isb\n"
    );

    main();

//uint32_t b=0;
// float x=50.59;
// uint8_t y=23,f=56;
// x++;
// kprintf("%d %d %f\n",y,f,x);
// kprintf("After Input\n");
// //uint8_t p[8]="1234.34\0";
// //x=str2float(p);
// kprintf("After Input\n");
// kprintf("Time Elapse %d ms\n",__getTime());
while(1){
//	kprintf((uint8_t*)"%d",(uint8_t*)a);
//	kscanf((uint8_t*)"%d",(uint8_t*)b);
//	kprintf((uint8_t*)"%d",(uint8_t*)b);
//	a++;
//	b++;
	//you can change the following line by replacing a delay function
	//for(uint32_t i=0;i<100000000;i++){kprintf("Time Elapse %d ms\n",__getTime());}	
}
}

