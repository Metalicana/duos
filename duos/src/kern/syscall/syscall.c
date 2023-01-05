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

#include <syscall.h>
#include <syscall_def.h>
#include <errno.h>
#include <errmsg.h>
#include <kunistd.h>
void syscall(unsigned int *args)
{
	unsigned int svc_number;
	svc_number = ((char *) args[6])[-2];
/* The SVC_Handler calls this function to evaluate and execute the actual function */
/* Take care of return value or code */
	switch(svc_number)
	{
		/* Write your code to call actual function (kunistd.h/c or times.h/c and handle the return value(s) */
		case SYS_read: 
			{
				char *toRead;
				//we need to send pointer or pointer
				//so that we can use the first char pointer as our string to write
				__sys_read(0,&toRead);
				//get arguments
				unsigned int string_add = args[18];

				*((char**)string_add) = toRead;
				break;
			}
			
		case SYS_write:
			{
				unsigned int string_add = args[18];
				char *ch = string_add;
				__sys_write(STDOUT_FILENO, ch);
				break;
			}
		case SYS_reboot:
			break;	
		case SYS__exit:
			break;
		case SYS_getpid:
			break;
		case SYS___time:
			break;
		case SYS_yield:
			break;				
		/* return error code see error.h and errmsg.h ENOSYS sys_errlist[ENOSYS]*/	
		default: ;
	}
/* Handle SVC return here */
}

