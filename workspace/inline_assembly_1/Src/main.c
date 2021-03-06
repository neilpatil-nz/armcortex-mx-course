/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void generate_interrupt(){
	uint32_t *pSTIR = (uint32_t*)0xE000EF00;
	uint32_t *pISER0 = (uint32_t*)0xE000E100;

	//ENABLE IRQ3 interrupt
	*pISER0 |= (1<<3);

	//generate an interrupt from software for IRQ3
	*pSTIR = (3 & 0x1FF);
}

void change_access_level_unpriv(void){
	//read
	asm volatile("MRS R0, CONTROL");
	//modify
	asm volatile("ORR R0, R0, #0x01");
	//write
	asm volatile("MSR CONTROL,R0");
}

int main(void)
{
//	asm volatile("LDR R1,=#0x20001000");
//	asm volatile("LDR R2,=#0x20001004");
//	asm volatile("LDR R0,[R1]");
//	asm volatile("LDR R1,[R2]");
//	asm volatile("ADD R0,R0,R1");
//	asm volatile("STR R0,[R2]");

//	int val = 50;
//
//	asm volatile("MOV R0,%0"::"r"(val));

//	int control_reg;
//	asm volatile("MRS %0, CONTROL":"=r"(control_reg)::);
//
//	int p1, *p2;
//
//	p2 = (int*)0x2000008;
//
//	asm volatile("LDR %0, [%1]":"=r"(p1):"r"(p2):); // p1 = *p2

	printf("In thread mode: before interrupt \n");

	change_access_level_unpriv();

	generate_interrupt();

	printf("In thread mode: after interrupt \n");

	for(;;);
}

void RTC_WKUP_IRQHandler(void){
	printf("In Handler mode \n");
}

void HardFault_Handler(void){
	printf("Hard fault \n");
}
