Stack Memory
===================================
1) Part of main memory (SRAM or external RAM)

2) Mainly used during function/isr (for ISR, the context will be saved on stack memory - some general purpose registers, register address)

3) Accessed in LIFO

4) Accessed using PUSH and POP instructions or memory manipulation (LD,STR)

5) Stack is traced using a stack pointer register(SP,R13).

6) In ARM processor, the stack operation mode is fully descending.