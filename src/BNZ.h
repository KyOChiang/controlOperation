#ifndef _BNZ_H_
#define _BNZ_H_

#define WREG 0xFE8
#define STATUS 0xFD8

extern char FSR[];

void bnz(Bytecode *code);

#endif