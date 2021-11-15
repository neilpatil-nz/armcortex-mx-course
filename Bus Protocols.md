Bus Protocols and Bus Interfaces
===================================
1) Cortex MX processor bus interfaces are based on AMBA (advanced 
microcontroller bus architecture) 

2) This specification governs the standard for on-chip communication
inside the SoC

3) AMBA specification supports several bus protocols
    - AHB Lite (AMBA High Performance Bus)
    - APB (AMBA Peripheral Bus)

4) APB is used for private peripheral bus (PPB) access and some on-chip
access using an AHB-APB bridge

5) AHB Lite is mostly used for peripherals that require high speed communication 

6) APB Bus is used for low-speed communication

(Processor D-CODE) <-AHB(32 Bit)-> Program Data
(Processor I-CODE) <-AHB(32 Bit)-> Program Data
(Processor PPB) <-AHB(32 Bit)-> PPB (NVIC, MPU, ETM, etc)
(Processor System) <-AHB(32 Bit)-> SRAM



Bit Banding
===================================
1) Directly accessing individual bits of a byte using an address

2) Advantage - allows for atomic operations on data