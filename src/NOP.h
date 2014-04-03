#ifndef _NOP_H_
#define _NOP_H_

#define WREG 0xFE8

extern char FSR[];

int nop(Bytecode *code);

#endif