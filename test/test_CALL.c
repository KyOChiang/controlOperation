/**
 * Author: Chiang Choon Yong
 * Email: yong931231@hotmail.com
 * Date: 07 - 04 - 2014
 * Project name: PIC18 simulator
 * Programme: Microelectronic with Embedded Technology
 * Institution: Tunku Abdul Rahman University College
 * Copyright: GPLv3
 */

#include "unity.h"
#include "CException.h"
#include "Bytecode.h"
#include "CALL.h"

void setUp(){}
void tearDown(){}

void test_CALL_should_throw_exception_if_operand2_is_non_empty(){
	CEXCEPTION_T operandERR;
	
	Bytecode code = {.instruction = {.mnemonic = CALL, .name = "CALL"},
					 .operand1 = 0x256,
					 .operand2 = 2,
					 .operand3 = -1,
					 .absoluteAddress = 0x100
					 };				 
	Try{
		call(&code);
	}Catch(operandERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND2,operandERR);
	}
	
	TEST_ASSERT_EQUAL(0x100,code.absoluteAddress);
}

void test_CALL_should_throw_exception_if_operand3_is_non_empty(){
	CEXCEPTION_T operandERR;
	
	Bytecode code = {.instruction = {.mnemonic = CALL, .name = "CALL"},
					 .operand1 = 0x256,
					 .operand2 = -1,
					 .operand3 = 99,
					 .absoluteAddress = 0xAA
					 };				 
	Try{
		call(&code);
	}Catch(operandERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND3,operandERR);
	}
	
	TEST_ASSERT_EQUAL(0xAA,code.absoluteAddress);
}