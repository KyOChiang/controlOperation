#include "unity.h"
#include "CException.h"
#include "Bytecode.h"
#include "NOP.h"

void setUp(){}
void tearDown(){}

void test_nop_should_do_nothing_and_return_0(){
	Bytecode code = {.instruction = {.mnemonic = NOP, .name = "nop"},
					 .operand1 = -1,
					 .operand2 = -1,
					 .operand3 = -1
					 };
	TEST_ASSERT_EQUAL(0,nop(&code));
}

void test_nop_should_do_nothing_but_throw_exception_for_invalid_operand1(){
	CEXCEPTION_T operandERR;
	Bytecode code = {.instruction = {.mnemonic = NOP, .name = "nop"},
					 .operand1 = 123,
					 .operand2 = -1,
					 .operand3 = -1
					 };
	Try{
		nop(&code);
	}Catch(operandERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND1,operandERR);
	}
}

