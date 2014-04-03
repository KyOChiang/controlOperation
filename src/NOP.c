#include <stdio.h>
#include "Bytecode.h"
#include "NOP.h"

char FSR[0x1000];


int nop(Bytecode *code){
	if(code->operand1 != -1){
		Throw(ERR_INVALID_OPERAND1);
	}
	
	
	return 0;
}