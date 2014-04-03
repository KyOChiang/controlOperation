#include <stdio.h>
#include "Bytecode.h"
#include "BNZ.h"

char FSR[0x1000];
int PC;

void bnz(Bytecode *code){

	if((code->operand1 - code->absoluteAdress) > 127||(code->operand1 - code->absoluteAdress) < -128)
		Throw(ERR_INVALID_OPERAND1);
	
	
	
	
}