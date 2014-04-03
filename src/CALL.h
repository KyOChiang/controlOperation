#ifndef _CALL_H_
#define _CALL_H_

#define WREG 0xFE8

extern char FSR[];

void call(Bytecode *code);

#endif