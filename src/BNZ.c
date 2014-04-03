#include <stdio.h>
#include "Bytecode.h"
#include "BNZ.h"

char FSR[0x1000];
int PC;

void bnz(Bytecode *code){

	if((code->operand1 - code->absoluteAdress) > 127||(code->operand1 - code->absoluteAdress) < -128)
		Throw(ERR_INVALID_OPERAND1);
	if(code->operand2 != -1)
		Throw(ERR_INVALID_OPERAND2);
	if(code->operand3 != -1)
		Throw(ERR_INVALID_OPERAND3);
	
	if(FSR[STATUS] == 0x00){
		PC = code->operand1;
	}
	else if(FSR[STATUS] == 0x04){
		PC = PC + 0x02;
	}
	
	
	
}