#include "unity.h"
#include "CException.h"
#include "Bytecode.h"
#include "BNZ.h"

void setUp(){}
void tearDown(){}

void test_bnz_should_not_branch_throw_exception_if_operand1_is_invalid_by_exceeding_127(){
	CEXCEPTION_T operandERR;
	
	Bytecode code = {.instruction = {.mnemonic = BNZ, .name = "bnz"},
					 .operand1 = 0x256,
					 .operand2 = -1,
					 .operand3 = -1,
					 .absoluteAdress = 0x100
					 };
	PC = code.absoluteAdress;				 
	Try{
		bnz(&code);
	}Catch(operandERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND1,operandERR);
	}
	
	TEST_ASSERT_EQUAL(code.absoluteAdress,PC);
}

void test_bnz_should_not_branch_throw_exception_if_operand1_is_invalid_that_less_than_neg_128(){
	CEXCEPTION_T operandERR;
	
	Bytecode code = {.instruction = {.mnemonic = BNZ, .name = "bnz"},
					 .operand1 = 0x100,
					 .operand2 = -1,
					 .operand3 = -1,
					 .absoluteAdress = 0x256
					 };
	PC = code.absoluteAdress;				 
	Try{
		bnz(&code);
	}Catch(operandERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND1,operandERR);
	}
	
	TEST_ASSERT_EQUAL(code.absoluteAdress,PC);
}


void test_bnz_throw_exception_if_operand2_is_invalid(){
	
}

void test_bnz_throw_exception_if_operand3_is_invalid(){
	
}
