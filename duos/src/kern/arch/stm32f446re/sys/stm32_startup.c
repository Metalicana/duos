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
 
#include <stm32_startup.h>
#include <types.h>
#include <schedule.h>
#define NUM_TASKS 5
void Reset_Handler(void){
	uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata;
	uint8_t *pDst = (uint8_t*)&_sdata;
	uint8_t *pSrc = (uint8_t*)&_la_data;
	for(uint32_t i=0;i<size;i++){
		*pDst++ = *pSrc++;
	}
	size = (uint32_t)&_ebss - (uint32_t)&_sbss;
	pDst = (uint8_t*)&_sbss;
	for(uint32_t i=0;i<size;i++){
		*pDst++ = 0;
	}
	_text_size = (uint32_t)&_etext - (uint32_t)&_stext;
	_data_size = (uint32_t)&_edata - (uint32_t)&_sdata;
	_bss_size = (uint32_t)&_ebss - (uint32_t)&_sbss;
	kmain();
}
void Default_Handler(void){
	while(1);
}
//2. implement the fault handlers
void HardFault_Handler(void)
{
//	printf("Exception : Hardfault\n");
	while(1);
}


void MemManage_Handler(void)
{
//	printf("Exception : MemManage\n");
	while(1);
}

void BusFault_Handler(void)
{
//	printf("Exception : BusFault\n");
	while(1);
}


// void SVC_Handler_Main( unsigned int *svc_args )
// {
//   unsigned int svc_number;

//   /*
//   * Stack contains:
//   * r0, r1, r2, r3, r12, r14, the return address and xPSR
//   * First argument (r0) is svc_args[0]
//   */
  
//   svc_number = ( ( char * )svc_args[ 6 ] )[ -2 ] ;
//   switch(svc_number)
//   {
// 	case 0:
// 		_USART_WRITE(USART2,(uint8_t*)"OOOOOOOOOOOOF\n\r");
// 		break;
// 	case 2:
// 		_USART_WRITE(USART2,(uint8_t*)"2\n\r");
// 		break;
// 	case 3:
// 		_USART_WRITE(USART2,(uint8_t*)"3\n\r");
// 		break;
// 	case 4:
// 		_USART_WRITE(USART2,(uint8_t*)"4\n\r");
// 		break;
// 	case 5:
// 		_USART_WRITE(USART2,(uint8_t*)"5\n\r");
// 		break;
// 	case 6:
// 		_USART_WRITE(USART2,(uint8_t*)"6\n\r");
// 		break;
// 	case 7:
// 		_USART_WRITE(USART2,(uint8_t*)"7\n\r");
// 		break;
// 	case 8:
// 		_USART_WRITE(USART2,(uint8_t*)"8\n\r");
// 		break;
	
//   }
//   switch( svc_number )
//   {
//     case 0:  /* EnablePrivilegedMode */
      
//       break;
// 	case 1:
// 		_USART_WRITE(USART2,(uint8_t*)"heeheee\n\r");
// 		break;
//     default:    /* unknown SVC */
//       break;
//   }
// }

void SVCall_Handler(void) {
/* Write code for SVC handler */
/* the handler function evntually call syscall function with a call number */	
	//Copied from book~
	__asm volatile (
		"TST lr, #4\n"
        "ITE EQ\n"
        "MRSEQ r0, MSP\n"
    	"MRSNE r0, PSP\n"
		"MOV r1, r0\n"
		"B syscall\n"
	);
	
}

//TODO implement pendsv handler here

